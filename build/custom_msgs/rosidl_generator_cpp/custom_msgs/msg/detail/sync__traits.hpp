// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SYNC__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SYNC__TRAITS_HPP_

#include "custom_msgs/msg/detail/sync__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'synced_img'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'synced_pc_lidar'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"
// Member 'synced_odom_cam'
#include "nav_msgs/msg/detail/odometry__traits.hpp"
// Member 'synced_cam_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::msg::Sync>()
{
  return "custom_msgs::msg::Sync";
}

template<>
inline const char * name<custom_msgs::msg::Sync>()
{
  return "custom_msgs/msg/Sync";
}

template<>
struct has_fixed_size<custom_msgs::msg::Sync>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value && has_fixed_size<nav_msgs::msg::Odometry>::value && has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct has_bounded_size<custom_msgs::msg::Sync>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value && has_bounded_size<nav_msgs::msg::Odometry>::value && has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct is_message<custom_msgs::msg::Sync>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__SYNC__TRAITS_HPP_
