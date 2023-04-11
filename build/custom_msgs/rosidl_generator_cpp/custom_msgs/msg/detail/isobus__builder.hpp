// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Isobus.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__ISOBUS__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__ISOBUS__BUILDER_HPP_

#include "custom_msgs/msg/detail/isobus__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Isobus_data
{
public:
  explicit Init_Isobus_data(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Isobus data(::custom_msgs::msg::Isobus::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_ps
{
public:
  explicit Init_Isobus_ps(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_data ps(::custom_msgs::msg::Isobus::_ps_type arg)
  {
    msg_.ps = std::move(arg);
    return Init_Isobus_data(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_pf
{
public:
  explicit Init_Isobus_pf(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_ps pf(::custom_msgs::msg::Isobus::_pf_type arg)
  {
    msg_.pf = std::move(arg);
    return Init_Isobus_ps(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_sa
{
public:
  explicit Init_Isobus_sa(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_pf sa(::custom_msgs::msg::Isobus::_sa_type arg)
  {
    msg_.sa = std::move(arg);
    return Init_Isobus_pf(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_pgn
{
public:
  explicit Init_Isobus_pgn(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_sa pgn(::custom_msgs::msg::Isobus::_pgn_type arg)
  {
    msg_.pgn = std::move(arg);
    return Init_Isobus_sa(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_page
{
public:
  explicit Init_Isobus_page(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_pgn page(::custom_msgs::msg::Isobus::_page_type arg)
  {
    msg_.page = std::move(arg);
    return Init_Isobus_pgn(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_priority
{
public:
  explicit Init_Isobus_priority(::custom_msgs::msg::Isobus & msg)
  : msg_(msg)
  {}
  Init_Isobus_page priority(::custom_msgs::msg::Isobus::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_Isobus_page(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

class Init_Isobus_header
{
public:
  Init_Isobus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Isobus_priority header(::custom_msgs::msg::Isobus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Isobus_priority(msg_);
  }

private:
  ::custom_msgs::msg::Isobus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Isobus>()
{
  return custom_msgs::msg::builder::Init_Isobus_header();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__ISOBUS__BUILDER_HPP_
