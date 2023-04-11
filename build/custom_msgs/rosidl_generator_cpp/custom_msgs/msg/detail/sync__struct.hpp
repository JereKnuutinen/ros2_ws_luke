// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'synced_img'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'synced_pc_lidar'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"
// Member 'synced_odom_cam'
#include "nav_msgs/msg/detail/odometry__struct.hpp"
// Member 'synced_cam_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__Sync __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__Sync __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sync_
{
  using Type = Sync_<ContainerAllocator>;

  explicit Sync_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : synced_img(_init),
    synced_pc_lidar(_init),
    synced_odom_cam(_init),
    synced_cam_pose(_init)
  {
    (void)_init;
  }

  explicit Sync_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : synced_img(_alloc, _init),
    synced_pc_lidar(_alloc, _init),
    synced_odom_cam(_alloc, _init),
    synced_cam_pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _synced_img_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _synced_img_type synced_img;
  using _synced_pc_lidar_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _synced_pc_lidar_type synced_pc_lidar;
  using _synced_odom_cam_type =
    nav_msgs::msg::Odometry_<ContainerAllocator>;
  _synced_odom_cam_type synced_odom_cam;
  using _synced_cam_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _synced_cam_pose_type synced_cam_pose;

  // setters for named parameter idiom
  Type & set__synced_img(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->synced_img = _arg;
    return *this;
  }
  Type & set__synced_pc_lidar(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->synced_pc_lidar = _arg;
    return *this;
  }
  Type & set__synced_odom_cam(
    const nav_msgs::msg::Odometry_<ContainerAllocator> & _arg)
  {
    this->synced_odom_cam = _arg;
    return *this;
  }
  Type & set__synced_cam_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->synced_cam_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::Sync_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::Sync_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::Sync_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::Sync_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Sync_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Sync_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Sync_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Sync_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::Sync_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::Sync_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__Sync
    std::shared_ptr<custom_msgs::msg::Sync_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__Sync
    std::shared_ptr<custom_msgs::msg::Sync_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sync_ & other) const
  {
    if (this->synced_img != other.synced_img) {
      return false;
    }
    if (this->synced_pc_lidar != other.synced_pc_lidar) {
      return false;
    }
    if (this->synced_odom_cam != other.synced_odom_cam) {
      return false;
    }
    if (this->synced_cam_pose != other.synced_cam_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sync_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sync_

// alias to use template instance with default allocator
using Sync =
  custom_msgs::msg::Sync_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SYNC__STRUCT_HPP_
