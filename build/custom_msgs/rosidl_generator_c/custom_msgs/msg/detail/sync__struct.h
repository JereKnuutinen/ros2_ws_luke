// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'synced_img'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'synced_pc_lidar'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"
// Member 'synced_odom_cam'
#include "nav_msgs/msg/detail/odometry__struct.h"
// Member 'synced_cam_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

// Struct defined in msg/Sync in the package custom_msgs.
typedef struct custom_msgs__msg__Sync
{
  sensor_msgs__msg__Image synced_img;
  sensor_msgs__msg__PointCloud2 synced_pc_lidar;
  nav_msgs__msg__Odometry synced_odom_cam;
  geometry_msgs__msg__PoseStamped synced_cam_pose;
} custom_msgs__msg__Sync;

// Struct for a sequence of custom_msgs__msg__Sync.
typedef struct custom_msgs__msg__Sync__Sequence
{
  custom_msgs__msg__Sync * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Sync__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_H_
