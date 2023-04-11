#include <rclcpp/rclcpp.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

// Only lidar
class SyncNode: public rclcpp::Node
{
public:
    SyncNode(): rclcpp::Node("sync_node"), sync_policy_(10),
    image_sync_(sync_policy_) {


         // Create publishers for synchronized topics
        pointcloud1_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_right_pc", 10);
        pointcloud2_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_left_pc", 10);


        // Subscribe to topics "/zed2/zed_node/rgb/image_rect_color" for both color and depth images
        right_pointcloud_.subscribe(this, "/lidar_right/velodyne_points", rclcpp::SensorDataQoS().get_rmw_qos_profile());
        left_pointcloud_.subscribe(this, "/lidar_left/velodyne_points", rclcpp::SensorDataQoS().get_rmw_qos_profile());

        // Sync the color and depth images
        image_sync_.connectInput(right_pointcloud_, left_pointcloud_);

        // Call the rgbd_callback function when new messages are received
        image_sync_.registerCallback(
            std::bind(&SyncNode::rgbd_callback, this, std::placeholders::_1, std::placeholders::_2));
    };
    ~SyncNode() {};

    void rgbd_callback(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC1,
                       const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC2) {

    std::cout << "Callback " << std::endl;
    // Publish synchronized messages
    pointcloud1_publisher_->publish(*msgPC1);
    pointcloud2_publisher_->publish(*msgPC2);
    RCLCPP_INFO(this->get_logger(),
                "I heard and synchronized the following timestamps: %u, %u",
                msgPC1->header.stamp.sec, msgPC2->header.stamp.sec);
    }

private:
    typedef message_filters::Subscriber<sensor_msgs::msg::PointCloud2> PointCloudSubscriberFilter;
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::PointCloud2, sensor_msgs::msg::PointCloud2> sync_policy;

    sync_policy sync_policy_;
    message_filters::Synchronizer<sync_policy> image_sync_;
    PointCloudSubscriberFilter right_pointcloud_, left_pointcloud_;

    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud1_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud2_publisher_;
};

// Camera lidar 
// class SyncNode: public rclcpp::Node
// {
// public:
//     SyncNode(): rclcpp::Node("sync_node"), sync_policy_(10),
//     image_sync_(sync_policy_) {


//          // Create publishers for synchronized topics
//         image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("synced_rgb_depth", 10);
//         pointcloud1_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_right_pc", 10);
//         pointcloud2_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_left_pc", 10);
//         pointcloud3_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("synced_image_pc", 10);



//         // Subscribe to topics "/zed2/zed_node/rgb/image_rect_color" for both color and depth images
//         sub_image_.subscribe(this, "/zed2/zed_node/rgb/image_rect_color", rclcpp::SensorDataQoS().get_rmw_qos_profile());
//         right_pointcloud_.subscribe(this, "/lidar_right/velodyne_points", rclcpp::SensorDataQoS().get_rmw_qos_profile());
//         left_pointcloud_.subscribe(this, "/lidar_left/velodyne_points", rclcpp::SensorDataQoS().get_rmw_qos_profile());
//         camera_pointcloud_.subscribe(this, "/zed2/zed_node/point_cloud/cloud_registered", rclcpp::SensorDataQoS().get_rmw_qos_profile());

//         // Sync the color and depth images
//         image_sync_.connectInput(sub_image_, right_pointcloud_, left_pointcloud_,camera_pointcloud_);

//         // Call the rgbd_callback function when new messages are received
//         image_sync_.registerCallback(
//             std::bind(&SyncNode::rgbd_callback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
//     };
//     ~SyncNode() {};

//     void rgbd_callback(const sensor_msgs::msg::Image::ConstSharedPtr msgRGB,
//                        const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC1,
//                        const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC2,
//                        const sensor_msgs::msg::PointCloud2::ConstSharedPtr msgPC3) {

//     std::cout << "Callback " << std::endl;
//     // Publish synchronized messages
//     image_publisher_->publish(*msgRGB);
//     pointcloud1_publisher_->publish(*msgPC1);
//     pointcloud2_publisher_->publish(*msgPC2);
//     pointcloud3_publisher_->publish(*msgPC3);
//     RCLCPP_INFO(this->get_logger(),
//                 "I heard and synchronized the following timestamps: %u, %u, %u",
//                 msgRGB->header.stamp.sec, msgPC1->header.stamp.sec, msgPC2->header.stamp.sec);
//     }

// private:
//     typedef message_filters::Subscriber<sensor_msgs::msg::Image> ImageSubscriberFilter;
//     typedef message_filters::Subscriber<sensor_msgs::msg::PointCloud2> PointCloudSubscriberFilter;
//     typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::PointCloud2, sensor_msgs::msg::PointCloud2, sensor_msgs::msg::PointCloud2> sync_policy;

//     sync_policy sync_policy_;
//     message_filters::Synchronizer<sync_policy> image_sync_;
//     ImageSubscriberFilter sub_image_, sub_depth_, sub_right_image_, sub_mono_;
//     PointCloudSubscriberFilter right_pointcloud_, left_pointcloud_, camera_pointcloud_;

//     rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
//     rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud1_publisher_;
//     rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud2_publisher_;
//     rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud3_publisher_;
// };




int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    std::shared_ptr<SyncNode> node = std::make_shared<SyncNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return EXIT_SUCCESS;
}



