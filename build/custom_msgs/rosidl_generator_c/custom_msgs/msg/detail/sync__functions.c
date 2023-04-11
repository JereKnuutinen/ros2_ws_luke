// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/sync__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `synced_img`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `synced_pc_lidar`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"
// Member `synced_odom_cam`
#include "nav_msgs/msg/detail/odometry__functions.h"
// Member `synced_cam_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
custom_msgs__msg__Sync__init(custom_msgs__msg__Sync * msg)
{
  if (!msg) {
    return false;
  }
  // synced_img
  if (!sensor_msgs__msg__Image__init(&msg->synced_img)) {
    custom_msgs__msg__Sync__fini(msg);
    return false;
  }
  // synced_pc_lidar
  if (!sensor_msgs__msg__PointCloud2__init(&msg->synced_pc_lidar)) {
    custom_msgs__msg__Sync__fini(msg);
    return false;
  }
  // synced_odom_cam
  if (!nav_msgs__msg__Odometry__init(&msg->synced_odom_cam)) {
    custom_msgs__msg__Sync__fini(msg);
    return false;
  }
  // synced_cam_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->synced_cam_pose)) {
    custom_msgs__msg__Sync__fini(msg);
    return false;
  }
  return true;
}

void
custom_msgs__msg__Sync__fini(custom_msgs__msg__Sync * msg)
{
  if (!msg) {
    return;
  }
  // synced_img
  sensor_msgs__msg__Image__fini(&msg->synced_img);
  // synced_pc_lidar
  sensor_msgs__msg__PointCloud2__fini(&msg->synced_pc_lidar);
  // synced_odom_cam
  nav_msgs__msg__Odometry__fini(&msg->synced_odom_cam);
  // synced_cam_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->synced_cam_pose);
}

bool
custom_msgs__msg__Sync__are_equal(const custom_msgs__msg__Sync * lhs, const custom_msgs__msg__Sync * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // synced_img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->synced_img), &(rhs->synced_img)))
  {
    return false;
  }
  // synced_pc_lidar
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->synced_pc_lidar), &(rhs->synced_pc_lidar)))
  {
    return false;
  }
  // synced_odom_cam
  if (!nav_msgs__msg__Odometry__are_equal(
      &(lhs->synced_odom_cam), &(rhs->synced_odom_cam)))
  {
    return false;
  }
  // synced_cam_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->synced_cam_pose), &(rhs->synced_cam_pose)))
  {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__Sync__copy(
  const custom_msgs__msg__Sync * input,
  custom_msgs__msg__Sync * output)
{
  if (!input || !output) {
    return false;
  }
  // synced_img
  if (!sensor_msgs__msg__Image__copy(
      &(input->synced_img), &(output->synced_img)))
  {
    return false;
  }
  // synced_pc_lidar
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->synced_pc_lidar), &(output->synced_pc_lidar)))
  {
    return false;
  }
  // synced_odom_cam
  if (!nav_msgs__msg__Odometry__copy(
      &(input->synced_odom_cam), &(output->synced_odom_cam)))
  {
    return false;
  }
  // synced_cam_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->synced_cam_pose), &(output->synced_cam_pose)))
  {
    return false;
  }
  return true;
}

custom_msgs__msg__Sync *
custom_msgs__msg__Sync__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Sync * msg = (custom_msgs__msg__Sync *)allocator.allocate(sizeof(custom_msgs__msg__Sync), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__Sync));
  bool success = custom_msgs__msg__Sync__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__Sync__destroy(custom_msgs__msg__Sync * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__Sync__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__Sync__Sequence__init(custom_msgs__msg__Sync__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Sync * data = NULL;

  if (size) {
    data = (custom_msgs__msg__Sync *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__Sync), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__Sync__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__Sync__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__Sync__Sequence__fini(custom_msgs__msg__Sync__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__Sync__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__Sync__Sequence *
custom_msgs__msg__Sync__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Sync__Sequence * array = (custom_msgs__msg__Sync__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__Sync__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__Sync__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__Sync__Sequence__destroy(custom_msgs__msg__Sync__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__Sync__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__Sync__Sequence__are_equal(const custom_msgs__msg__Sync__Sequence * lhs, const custom_msgs__msg__Sync__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__Sync__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Sync__Sequence__copy(
  const custom_msgs__msg__Sync__Sequence * input,
  custom_msgs__msg__Sync__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__Sync);
    custom_msgs__msg__Sync * data =
      (custom_msgs__msg__Sync *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__Sync__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__Sync__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__Sync__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
