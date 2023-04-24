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


# img_dir = '/home/jere/imgs'
# pcl_dir = '/home/jere/pointclouds'
# if not os.path.exists(img_dir):
#     os.makedirs(img_dir)
# if not os.path.exists(pcl_dir):
#     os.makedirs(pcl_dir)
        
class ExampleNode(Node):
    def __init__(self):
        super().__init__("ExampleNode")

        self.image_sub = Subscriber(self, Image, "/zed2/zed_node/left/image_rect_color")
        # Subscribers for velodyne pointcloud
        self.plc_sub_1 = Subscriber(self, PointCloud2, "/lidar_right/velodyne_points")
        self.plc_sub_2 = Subscriber(self, PointCloud2, "/lidar_left/velodyne_points")
        
        # Subscribers for camera odom data
        self.odom_sub_cam = Subscriber(self, Odometry, "/zed2/zed_node/odom")
        self.cam_info_sub = Subscriber(self, CameraInfo, "/zed2/zed_node/left/camera_info")
        self.pose_sub_cam = Subscriber(self, PoseStamped, "/zed2/zed_node/pose")
        
        self.image_pub = self.create_publisher(Image, 'synced_img', 10)
        self.pcl_pub_1 = self.create_publisher(PointCloud2, 'synced_pc_lidar_1', 10)
        self.pcl_pub_2 = self.create_publisher(PointCloud2, 'synced_pc_lidar_2', 10)

        self.odom_pub_cam = self.create_publisher(Odometry, 'synced_odom_cam', 10)
        self.cam_info_pub = self.create_publisher(CameraInfo, 'synced_cam_info', 10)
        self.pose_pub = self.create_publisher(PoseStamped, 'synced_cam_pose', 10)
        self.sync_publisher_ = self.create_publisher(Sync, 'synced_messages', 10)  # CHANGE

        queue_size = 100
        # you can use ApproximateTimeSynchronizer if msgs dont have exactly the same timestamp
        self.ts = ApproximateTimeSynchronizer(
            [self.image_sub, self.plc_sub_1, self.plc_sub_2, self.odom_sub_cam, self.pose_sub_cam],
            queue_size,
            0.05,  # defines the delay (in seconds) with which messages can be synchronized
        )
        self.ts.registerCallback(self.callback)

    def callback(self,image_msg, pcl_msg_1, pcl_msg_2, odom_msgs_cam, pose_msgs):
        # Save the image
        # img = np.frombuffer(image_msg.data, np.uint8).reshape(image_msg.height, image_msg.width, -1)
        # img_file = os.path.join(img_dir, '{}.jpg'.format(image_msg.header.stamp))
        # cv2.imwrite(img_file, img)

        # # Save the point cloud as .pcd file
        # pcl = np.frombuffer(pcl_msg.data, dtype=np.float32).reshape(-1, 4)
        # pcl[:, 3] = 1.0  # Convert to homogeneous coordinates
        # pcd = o3d.geometry.PointCloud()
        # pcd.points = o3d.utility.Vector3dVector(pcl)
        # #pcd.colors = o3d.utility.Vector3dVector(pcl[:, 3:].astype(float) / 255.0)
        # pcd_file = os.path.join(pcl_dir, '{}.pcd'.format(pcl_msg.header.stamp))
        # o3d.io.write_point_cloud(pcd_file, pcd)
        
        #self.image_pub.publish(image_msg)
        # Publish syncronized messages for rosbag
        
        # LIDAR messages:
        self.pcl_pub_1.publish(pcl_msg_1)
        self.pcl_pub_2.publish(pcl_msg_2)

        # Camera messages:
        self.odom_pub_cam.publish(odom_msgs_cam)
        self.pose_pub.publish(pose_msgs)
        self.image_pub.publish(image_msg)


        #msg = Sync()
        #msg.synced_img = image_msg
        #msg.synced_pc_lidar_1 = pcl_msg_1
        #msg.synced_pc_lidar_2 = pcl_msg_2
        #msg.synced_odom_cam = odom_msgs_cam
        #msg.synced_cam_pose = pose_msgs
        #self.sync_publisher_.publish(msg)

        # print("Callback seems to be working")
        # print("Image timestap: ",  image_msg.header.stamp, "pointcloud timestamp: ", pcl_msg.header.stamp, "Image pointcloud timestap: ", odom_msgs_cam.header.stamp)

def main():
    print('Hi from message_sync_python.')

         
    rclpy.init()
    syncronizeri = ExampleNode()
    rclpy.spin(syncronizeri)


if __name__ == '__main__':
    main()
