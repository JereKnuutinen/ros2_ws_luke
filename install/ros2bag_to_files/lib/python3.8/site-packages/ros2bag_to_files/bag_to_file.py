from rosbags.rosbag2 import Reader
from rosbags.serde import deserialize_cdr
import rclpy
from sensor_msgs.msg import PointCloud2

def main():
    print('Hi from ros2bag_to_files.')
    # create reader instance and open for reading
    with Reader('/home/jere/thesis/ROS_BAGS/Sync_test_vanha') as reader:
        # topic and msgtype information is available on .connections list
        for connection in reader.connections:
            print(connection.topic, connection.msgtype)

        # # iterate over messages
        for connection, timestamp, rawdata in reader.messages():
            # if connection.topic == '/synced_cam_pose':
            #     msg = deserialize_cdr(rawdata, connection.msgtype)
            #     print(msg.pose.orientation.x)
            if connection.topic == '/synced_pc_lidar':
                msg = deserialize_cdr(rawdata, connection.msgtype)
                print(msg.data)
                pcl_msg = pcl_conversions.msg_to_pointcloud2(msg)
                pcl_cloud = pcl.PointCloud.PointXYZRGB()
                pcl.fromROSMsg(pcl_msg, pcl_cloud)
                pcl.save(pcl_cloud, "/path/to/your/pcd/file.pcd")


if __name__ == '__main__':
    main()
