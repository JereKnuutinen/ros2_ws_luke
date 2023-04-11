
#include <rclcpp/rclcpp.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rosbag2_cpp/writer.hpp>

// lidar, cam, cam odometry
class SyncNodeLidarCam: public rclcpp::Node
{
public:
    SyncNodeLidarCam(): rclcpp::Node("sync_node_lidar_cam"), sync_policy_(10),
    image_sync_(sync_policy_) {


         // Create publishers for synchronized topics
        pointcloud_lidar_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_lidar_pc", 10);
        pointcloud_cam_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_cam_pc", 10);
        image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("synced_image", 10);
        odom_publisher_ = this->create_publisher< nav_msgs::msg::Odometry>("synced_odom_cam", 10);


        // Subscribe to topics "/zed2/zed_node/rgb/image_rect_color" for both color and depth images
        lidar_pointcloud_.subscribe(this, "/velodyne_points", rclcpp::SensorDataQoS().get_rmw_qos_profile());
        cam_pointcloud_.subscribe(this, "/zed2/zed_node/point_cloud/cloud_registered", rclcpp::SensorDataQoS().get_rmw_qos_profile());
        cam_image_.subscribe(this, "/zed2/zed_node/rgb/image_rect_color", rclcpp::SensorDataQoS().get_rmw_qos_profile());
        odom_cam_.subscribe(this, "/zed2/zed_node/odom", rclcpp::SensorDataQoS().get_rmw_qos_profile());

        // Sync the color and depth images
        image_sync_.connectInput(lidar_pointcloud_, cam_pointcloud_, cam_image_, odom_cam_);

        // Call the rgbd_callback function when new messages are received
        image_sync_.registerCallback(
            std::bind(&SyncNodeLidarCam::rgbd_callback, this, std::placeholders::_1, std::placeholders::_2,std::placeholders::_3, std::placeholders::_4));
    };
    ~SyncNodeLidarCam() {};

    void rgbd_callback(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC_lidar,
                       const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC_cam,
                       const sensor_msgs::msg::Image::ConstSharedPtr msgRGB,
                       const nav_msgs::msg::Odometry::ConstSharedPtr msgODOM) {

    std::cout << "Callback " << std::endl;
    // Publish synchronized messages
    pointcloud_lidar_publisher_->publish(*msgPC_lidar);
    pointcloud_cam_publisher_->publish(*msgPC_cam);
    image_publisher_->publish(*msgRGB);
    odom_publisher_->publish(*msgODOM);


    RCLCPP_INFO(this->get_logger(),
                "I heard and synchronized the following timestamps: %u, %u, %u, %u",
                msgPC_lidar->header.stamp.sec, msgPC_cam->header.stamp.sec, msgRGB->header.stamp.sec, msgRGB->header.stamp.sec);
    }

private:
    typedef message_filters::Subscriber<sensor_msgs::msg::Image> ImageSubscriberFilter;
    typedef message_filters::Subscriber<sensor_msgs::msg::PointCloud2> PointCloudSubscriberFilter;
    typedef message_filters::Subscriber<nav_msgs::msg::Odometry> OdometrySubscriberFilter;

    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::PointCloud2, sensor_msgs::msg::PointCloud2, sensor_msgs::msg::Image, nav_msgs::msg::Odometry> sync_policy;

    sync_policy sync_policy_;
    message_filters::Synchronizer<sync_policy> image_sync_;
    ImageSubscriberFilter cam_image_;
    PointCloudSubscriberFilter lidar_pointcloud_, cam_pointcloud_;
    OdometrySubscriberFilter odom_cam_;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_lidar_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_cam_publisher_;

};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    std::shared_ptr<SyncNodeLidarCam> node = std::make_shared<SyncNodeLidarCam>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return EXIT_SUCCESS;
}



