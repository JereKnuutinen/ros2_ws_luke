cmake_minimum_required(VERSION 3.5)
project(message_sync_lidar_cam)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# Find dependencies
find_package(ament_cmake REQUIRED)
#find_package(OpenCV REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosbag2 REQUIRED)
find_package(sensor_msgs REQUIRED)
#find_package(cv_bridge REQUIRED)
find_package(message_filters REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Add the executable
add_executable(sync_node_lidar_cam src/sync_node_lidar_cam.cpp)

ament_target_dependencies(sync_node_lidar_cam
  "rclcpp"
  "sensor_msgs"
  "rosbag2"
  "message_filters"
  "geometry_msgs"
  "nav_msgs"
)
install(TARGETS
sync_node_lidar_cam
  DESTINATION lib/${PROJECT_NAME}
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
