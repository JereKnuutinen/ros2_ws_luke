import rclpy
from rclpy.node import Node
from rclpy.serialization import serialize_message
#import cv2
import numpy as np
import os
#import open3d as o3d

from rclpy.qos import qos_profile_sensor_data
from message_filters import ApproximateTimeSynchronizer, Subscriber
from sensor_msgs.msg import Image, PointCloud2, CameraInfo
from nav_msgs.msg import Odometry
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from custom_msgs.msg import Sync                         


        
class LidarLidarSyncNode(Node):
    def __init__(self):
        super().__init__("LidarLidarSyncNode")

        # Subscribers for velodyne pointcloud
        self.plc_sub_1 = Subscriber(self, PointCloud2, "/lidar_right/velodyne_points", qos_profile=qos_profile_sensor_data)
        self.plc_sub_2 = Subscriber(self, PointCloud2, "/lidar_left/velodyne_points", qos_profile=qos_profile_sensor_data)
        
        self.pcl_pub_1 = self.create_publisher(PointCloud2, 'synced_pc_lidar_1', 10)
        self.pcl_pub_2 = self.create_publisher(PointCloud2, 'synced_pc_lidar_2', 10)


        queue_size = 100
        # you can use ApproximateTimeSynchronizer if msgs dont have exactly the same timestamp
        self.ts = ApproximateTimeSynchronizer(
            [self.plc_sub_1, self.plc_sub_2],
            queue_size,
            0.05,  # defines the delay (in seconds) with which messages can be synchronized
        )
        self.ts.registerCallback(self.callback)

    def callback(self, pcl_msg_1, pcl_msg_2):
        
        # LIDAR messages:
        self.pcl_pub_1.publish(pcl_msg_1)
        self.pcl_pub_2.publish(pcl_msg_2)


        print("Callback seems to be working")
        # print("Image timestap: ",  image_msg.header.stamp, "pointcloud timestamp: ", pcl_msg.header.stamp, "Image pointcloud timestap: ", odom_msgs_cam.header.stamp)

def main():
    print('Hi from message_sync_python_lidar2lidar.')

         
    rclpy.init()
    syncronizeri = LidarLidarSyncNode()
    rclpy.spin(syncronizeri)


if __name__ == '__main__':
    main()
