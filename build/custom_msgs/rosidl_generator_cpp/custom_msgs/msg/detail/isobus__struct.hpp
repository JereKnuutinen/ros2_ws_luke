// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/Isobus.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__Isobus __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__Isobus __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Isobus_
{
  using Type = Isobus_<ContainerAllocator>;

  explicit Isobus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->priority = 0;
      this->page = false;
      this->pgn = 0;
      this->sa = 0;
      this->pf = 0;
      this->ps = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  explicit Isobus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->priority = 0;
      this->page = false;
      this->pgn = 0;
      this->sa = 0;
      this->pf = 0;
      this->ps = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _priority_type =
    uint8_t;
  _priority_type priority;
  using _page_type =
    bool;
  _page_type page;
  using _pgn_type =
    uint16_t;
  _pgn_type pgn;
  using _sa_type =
    uint8_t;
  _sa_type sa;
  using _pf_type =
    uint8_t;
  _pf_type pf;
  using _ps_type =
    uint8_t;
  _ps_type ps;
  using _data_type =
    std::array<uint8_t, 8>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__priority(
    const uint8_t & _arg)
  {
    this->priority = _arg;
    return *this;
  }
  Type & set__page(
    const bool & _arg)
  {
    this->page = _arg;
    return *this;
  }
  Type & set__pgn(
    const uint16_t & _arg)
  {
    this->pgn = _arg;
    return *this;
  }
  Type & set__sa(
    const uint8_t & _arg)
  {
    this->sa = _arg;
    return *this;
  }
  Type & set__pf(
    const uint8_t & _arg)
  {
    this->pf = _arg;
    return *this;
  }
  Type & set__ps(
    const uint8_t & _arg)
  {
    this->ps = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<uint8_t, 8> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::Isobus_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::Isobus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::Isobus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::Isobus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Isobus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Isobus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Isobus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Isobus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::Isobus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::Isobus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__Isobus
    std::shared_ptr<custom_msgs::msg::Isobus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__Isobus
    std::shared_ptr<custom_msgs::msg::Isobus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Isobus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->priority != other.priority) {
      return false;
    }
    if (this->page != other.page) {
      return false;
    }
    if (this->pgn != other.pgn) {
      return false;
    }
    if (this->sa != other.sa) {
      return false;
    }
    if (this->pf != other.pf) {
      return false;
    }
    if (this->ps != other.ps) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Isobus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Isobus_

// alias to use template instance with default allocator
using Isobus =
  custom_msgs::msg::Isobus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_HPP_
