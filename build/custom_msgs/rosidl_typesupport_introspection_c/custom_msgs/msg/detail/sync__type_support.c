// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msgs:msg/Sync.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msgs/msg/detail/sync__rosidl_typesupport_introspection_c.h"
#include "custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msgs/msg/detail/sync__functions.h"
#include "custom_msgs/msg/detail/sync__struct.h"


// Include directives for member types
// Member `synced_img`
#include "sensor_msgs/msg/image.h"
// Member `synced_img`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `synced_pc_lidar`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `synced_pc_lidar`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"
// Member `synced_odom_cam`
#include "nav_msgs/msg/odometry.h"
// Member `synced_odom_cam`
#include "nav_msgs/msg/detail/odometry__rosidl_typesupport_introspection_c.h"
// Member `synced_cam_pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `synced_cam_pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Sync__rosidl_typesupport_introspection_c__Sync_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msgs__msg__Sync__init(message_memory);
}

void Sync__rosidl_typesupport_introspection_c__Sync_fini_function(void * message_memory)
{
  custom_msgs__msg__Sync__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Sync__rosidl_typesupport_introspection_c__Sync_message_member_array[4] = {
  {
    "synced_img",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__Sync, synced_img),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "synced_pc_lidar",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__Sync, synced_pc_lidar),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "synced_odom_cam",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__Sync, synced_odom_cam),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "synced_cam_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__Sync, synced_cam_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Sync__rosidl_typesupport_introspection_c__Sync_message_members = {
  "custom_msgs__msg",  // message namespace
  "Sync",  // message name
  4,  // number of fields
  sizeof(custom_msgs__msg__Sync),
  Sync__rosidl_typesupport_introspection_c__Sync_message_member_array,  // message members
  Sync__rosidl_typesupport_introspection_c__Sync_init_function,  // function to initialize message memory (memory has to be allocated)
  Sync__rosidl_typesupport_introspection_c__Sync_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Sync__rosidl_typesupport_introspection_c__Sync_message_type_support_handle = {
  0,
  &Sync__rosidl_typesupport_introspection_c__Sync_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, Sync)() {
  Sync__rosidl_typesupport_introspection_c__Sync_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  Sync__rosidl_typesupport_introspection_c__Sync_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  Sync__rosidl_typesupport_introspection_c__Sync_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Odometry)();
  Sync__rosidl_typesupport_introspection_c__Sync_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!Sync__rosidl_typesupport_introspection_c__Sync_message_type_support_handle.typesupport_identifier) {
    Sync__rosidl_typesupport_introspection_c__Sync_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Sync__rosidl_typesupport_introspection_c__Sync_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
