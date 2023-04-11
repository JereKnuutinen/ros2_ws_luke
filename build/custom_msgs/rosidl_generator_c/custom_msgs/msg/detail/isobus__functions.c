// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/Isobus.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/isobus__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
custom_msgs__msg__Isobus__init(custom_msgs__msg__Isobus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_msgs__msg__Isobus__fini(msg);
    return false;
  }
  // priority
  // page
  // pgn
  // sa
  // pf
  // ps
  // data
  return true;
}

void
custom_msgs__msg__Isobus__fini(custom_msgs__msg__Isobus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // priority
  // page
  // pgn
  // sa
  // pf
  // ps
  // data
}

bool
custom_msgs__msg__Isobus__are_equal(const custom_msgs__msg__Isobus * lhs, const custom_msgs__msg__Isobus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // priority
  if (lhs->priority != rhs->priority) {
    return false;
  }
  // page
  if (lhs->page != rhs->page) {
    return false;
  }
  // pgn
  if (lhs->pgn != rhs->pgn) {
    return false;
  }
  // sa
  if (lhs->sa != rhs->sa) {
    return false;
  }
  // pf
  if (lhs->pf != rhs->pf) {
    return false;
  }
  // ps
  if (lhs->ps != rhs->ps) {
    return false;
  }
  // data
  for (size_t i = 0; i < 8; ++i) {
    if (lhs->data[i] != rhs->data[i]) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Isobus__copy(
  const custom_msgs__msg__Isobus * input,
  custom_msgs__msg__Isobus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // priority
  output->priority = input->priority;
  // page
  output->page = input->page;
  // pgn
  output->pgn = input->pgn;
  // sa
  output->sa = input->sa;
  // pf
  output->pf = input->pf;
  // ps
  output->ps = input->ps;
  // data
  for (size_t i = 0; i < 8; ++i) {
    output->data[i] = input->data[i];
  }
  return true;
}

custom_msgs__msg__Isobus *
custom_msgs__msg__Isobus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Isobus * msg = (custom_msgs__msg__Isobus *)allocator.allocate(sizeof(custom_msgs__msg__Isobus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__Isobus));
  bool success = custom_msgs__msg__Isobus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__Isobus__destroy(custom_msgs__msg__Isobus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__Isobus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__Isobus__Sequence__init(custom_msgs__msg__Isobus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Isobus * data = NULL;

  if (size) {
    data = (custom_msgs__msg__Isobus *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__Isobus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__Isobus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__Isobus__fini(&data[i - 1]);
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
custom_msgs__msg__Isobus__Sequence__fini(custom_msgs__msg__Isobus__Sequence * array)
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
      custom_msgs__msg__Isobus__fini(&array->data[i]);
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

custom_msgs__msg__Isobus__Sequence *
custom_msgs__msg__Isobus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Isobus__Sequence * array = (custom_msgs__msg__Isobus__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__Isobus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__Isobus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__Isobus__Sequence__destroy(custom_msgs__msg__Isobus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__Isobus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__Isobus__Sequence__are_equal(const custom_msgs__msg__Isobus__Sequence * lhs, const custom_msgs__msg__Isobus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__Isobus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Isobus__Sequence__copy(
  const custom_msgs__msg__Isobus__Sequence * input,
  custom_msgs__msg__Isobus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__Isobus);
    custom_msgs__msg__Isobus * data =
      (custom_msgs__msg__Isobus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__Isobus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__Isobus__fini(&data[i]);
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
    if (!custom_msgs__msg__Isobus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
