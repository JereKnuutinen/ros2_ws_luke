// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Isobus.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/Isobus in the package custom_msgs.
typedef struct custom_msgs__msg__Isobus
{
  std_msgs__msg__Header header;
  uint8_t priority;
  bool page;
  uint16_t pgn;
  uint8_t sa;
  uint8_t pf;
  uint8_t ps;
  uint8_t data[8];
} custom_msgs__msg__Isobus;

// Struct for a sequence of custom_msgs__msg__Isobus.
typedef struct custom_msgs__msg__Isobus__Sequence
{
  custom_msgs__msg__Isobus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Isobus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__ISOBUS__STRUCT_H_
