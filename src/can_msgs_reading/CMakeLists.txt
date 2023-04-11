cmake_minimum_required(VERSION 3.5)
project(can_msgs_reading)

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
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(custom_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
include_directories(${tf2_ros_INCLUDE_DIRS})
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(can_cpp_node src/can_cpp_node.cpp)
#add_executable(NMEA2000_node src/NMEA2000_node.cpp)

ament_target_dependencies(can_cpp_node
  "rclcpp"
  "std_msgs"
  "custom_msgs"
  "tf2"
  "tf2_ros"
  "geometry_msgs"
  "sensor_msgs"
)

#ament_target_dependencies(NMEA2000_node
#  "rclcpp"
 # "std_msgs"
#  "custom_msgs"
#)

target_include_directories(can_cpp_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)


##target_include_directories(NMEA2000_node PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#  $<INSTALL_INTERFACE:include>)

install(TARGETS can_cpp_node
  DESTINATION lib/${PROJECT_NAME})

 # install(TARGETS NMEA2000_node
 # DESTINATION lib/${PROJECT_NAME})

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
