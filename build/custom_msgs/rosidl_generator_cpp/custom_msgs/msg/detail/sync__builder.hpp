// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SYNC__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SYNC__BUILDER_HPP_

#include "custom_msgs/msg/detail/sync__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Sync_synced_cam_pose
{
public:
  explicit Init_Sync_synced_cam_pose(::custom_msgs::msg::Sync & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Sync synced_cam_pose(::custom_msgs::msg::Sync::_synced_cam_pose_type arg)
  {
    msg_.synced_cam_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Sync msg_;
};

class Init_Sync_synced_odom_cam
{
public:
  explicit Init_Sync_synced_odom_cam(::custom_msgs::msg::Sync & msg)
  : msg_(msg)
  {}
  Init_Sync_synced_cam_pose synced_odom_cam(::custom_msgs::msg::Sync::_synced_odom_cam_type arg)
  {
    msg_.synced_odom_cam = std::move(arg);
    return Init_Sync_synced_cam_pose(msg_);
  }

private:
  ::custom_msgs::msg::Sync msg_;
};

class Init_Sync_synced_pc_lidar
{
public:
  explicit Init_Sync_synced_pc_lidar(::custom_msgs::msg::Sync & msg)
  : msg_(msg)
  {}
  Init_Sync_synced_odom_cam synced_pc_lidar(::custom_msgs::msg::Sync::_synced_pc_lidar_type arg)
  {
    msg_.synced_pc_lidar = std::move(arg);
    return Init_Sync_synced_odom_cam(msg_);
  }

private:
  ::custom_msgs::msg::Sync msg_;
};

class Init_Sync_synced_img
{
public:
  Init_Sync_synced_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sync_synced_pc_lidar synced_img(::custom_msgs::msg::Sync::_synced_img_type arg)
  {
    msg_.synced_img = std::move(arg);
    return Init_Sync_synced_pc_lidar(msg_);
  }

private:
  ::custom_msgs::msg::Sync msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Sync>()
{
  return custom_msgs::msg::builder::Init_Sync_synced_img();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SYNC__BUILDER_HPP_
