import os
import yaml

import ament_index_python.packages
from launch import LaunchDescription
from launch_ros.actions import Node

#velodyne_1
def generate_launch_description():
    ld = LaunchDescription()

    driver_share_dir_1 = ament_index_python.packages.get_package_share_directory('velodyne_driver')
    driver_params_file_1 = os.path.join(driver_share_dir_1, 'config', 'vlp_1.yaml')
    velodyne_driver_node_1 = Node(
        package="velodyne_driver",
        executable="velodyne_driver_node",
        name="velodyne_driver_node_1",
        parameters=[driver_params_file_1],
        remappings=[
            ("velodyne_packets", "velodyne_packets_1")
        ]
    )

    convert_share_dir_1 = ament_index_python.packages.get_package_share_directory('velodyne_pointcloud')
    convert_params_file_1 = os.path.join(convert_share_dir_1, 'config', 'VLP16-velodyne_convert_node-params.yaml')
    with open(convert_params_file_1, 'r') as f:
        convert_params_1 = yaml.safe_load(f)['velodyne_convert_node']['ros__parameters']
    convert_params_1['calibration'] = os.path.join(convert_share_dir_1, 'params', 'VLP16db.yaml')
    velodyne_convert_node_1 = Node(
        package="velodyne_pointcloud",
        executable="velodyne_convert_node",
        name="velodyne_convert_node_1",
        parameters=[convert_params_1],
        remappings=[
            ("velodyne_packets", "velodyne_packets_1"),
            ("velodyne_points", "velodyne_points_1")
        ]
    )

    laserscan_share_dir_1 = ament_index_python.packages.get_package_share_directory('velodyne_laserscan')
    laserscan_params_file_1 = os.path.join(laserscan_share_dir_1, 'config', 'default-velodyne_laserscan_node-params.yaml')
    velodyne_laserscan_node_1 = Node(
        package="velodyne_laserscan",
        executable="velodyne_laserscan_node",
        name="velodyne_laserscan_node_1",
        parameters=[laserscan_params_file_1],
        remappings=[
            ("velodyne_points", "velodyne_points_1"),
            ("scan", "scan_1")
        ]
    )

    #velodyne_2
    driver_share_dir_2 = ament_index_python.packages.get_package_share_directory('velodyne_driver')
    driver_params_file_2 = os.path.join(driver_share_dir_2, 'config', 'vlp_2.yaml')
    velodyne_driver_node_2 = Node(
        package="velodyne_driver",
        executable="velodyne_driver_node",
        name="velodyne_driver_node_2",
        parameters=[driver_params_file_2],
        remappings=[
            ("velodyne_packets", "velodyne_packets_2")
        ]
    )

    convert_share_dir_2 = ament_index_python.packages.get_package_share_directory('velodyne_pointcloud')
    convert_params_file_2 = os.path.join(convert_share_dir_2, 'config', 'VLP16-velodyne_convert_node-params.yaml')
    with open(convert_params_file_2, 'r') as f:
        convert_params_2 = yaml.safe_load(f)['velodyne_convert_node']['ros__parameters']
    convert_params_2['calibration'] = os.path.join(convert_share_dir_2, 'params', 'VLP16db.yaml')
    velodyne_convert_node_2 = Node(
        package="velodyne_pointcloud",
        executable="velodyne_convert_node",
        name="velodyne_convert_node_2",
        parameters=[convert_params_2],
        remappings=[
            ("velodyne_packets", "velodyne_packets_2"),
            ("velodyne_points", "velodyne_points_2")
        ]
    )

    laserscan_share_dir_2 = ament_index_python.packages.get_package_share_directory('velodyne_laserscan')
    laserscan_params_file_2 = os.path.join(laserscan_share_dir_2, 'config', 'default-velodyne_laserscan_node-params.yaml')
    velodyne_laserscan_node_2 = Node(
        package="velodyne_laserscan",
        executable="velodyne_laserscan_node",
        name="velodyne_laserscan_node_2",
        parameters=[laserscan_params_file_2],
        remappings=[
            ("velodyne_points", "velodyne_points_2"),
            ("scan", "scan_2")
        ]
    )     

    ld.add_action(velodyne_driver_node_1)
    ld.add_action(velodyne_convert_node_1)
    ld.add_action(velodyne_laserscan_node_1)
    ld.add_action(velodyne_driver_node_2)
    ld.add_action(velodyne_convert_node_2)
    ld.add_action(velodyne_laserscan_node_2)
    return ld