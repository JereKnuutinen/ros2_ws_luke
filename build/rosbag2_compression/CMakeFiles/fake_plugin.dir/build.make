# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mlemsalu/ros2_ws_luke/build/rosbag2_compression

# Include any dependencies generated for this target.
include CMakeFiles/fake_plugin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fake_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fake_plugin.dir/flags.make

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o: CMakeFiles/fake_plugin.dir/flags.make
CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o: /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_compressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mlemsalu/ros2_ws_luke/build/rosbag2_compression/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o -c /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_compressor.cpp

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_compressor.cpp > CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.i

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_compressor.cpp -o CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.s

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o: CMakeFiles/fake_plugin.dir/flags.make
CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o: /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_decompressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mlemsalu/ros2_ws_luke/build/rosbag2_compression/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o -c /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_decompressor.cpp

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_decompressor.cpp > CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.i

CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression/test/rosbag2_compression/fake_decompressor.cpp -o CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.s

# Object files for target fake_plugin
fake_plugin_OBJECTS = \
"CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o" \
"CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o"

# External object files for target fake_plugin
fake_plugin_EXTERNAL_OBJECTS =

libfake_plugin.so: CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_compressor.cpp.o
libfake_plugin.so: CMakeFiles/fake_plugin.dir/test/rosbag2_compression/fake_decompressor.cpp.o
libfake_plugin.so: CMakeFiles/fake_plugin.dir/build.make
libfake_plugin.so: librosbag2_compression.so
libfake_plugin.so: /home/mlemsalu/ros2_ws_luke/install/rosbag2_cpp/lib/librosbag2_cpp.so
libfake_plugin.so: /home/mlemsalu/ros2_ws_luke/install/rosbag2_storage/lib/librosbag2_storage.so
libfake_plugin.so: /opt/ros/foxy/lib/librclcpp.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librcl_logging_spdlog.so
libfake_plugin.so: /usr/lib/x86_64-linux-gnu/libspdlog.so.1.5.0
libfake_plugin.so: /opt/ros/foxy/lib/librcl_yaml_param_parser.so
libfake_plugin.so: /opt/ros/foxy/lib/libyaml.so
libfake_plugin.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libtracetools.so
libfake_plugin.so: /opt/ros/foxy/lib/librmw_implementation.so
libfake_plugin.so: /opt/ros/foxy/lib/librmw.so
libfake_plugin.so: /opt/ros/foxy/lib/librosidl_typesupport_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librosidl_typesupport_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librosidl_runtime_c.so
libfake_plugin.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so
libfake_plugin.so: /opt/ros/foxy/opt/yaml_cpp_vendor/lib/libyaml-cpp.so.0.6.2
libfake_plugin.so: /opt/ros/foxy/lib/libament_index_cpp.so
libfake_plugin.so: /opt/ros/foxy/lib/libclass_loader.so
libfake_plugin.so: /opt/ros/foxy/lib/x86_64-linux-gnu/libconsole_bridge.so.1.0
libfake_plugin.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
libfake_plugin.so: /opt/ros/foxy/lib/librcpputils.so
libfake_plugin.so: /opt/ros/foxy/lib/librcutils.so
libfake_plugin.so: CMakeFiles/fake_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/rosbag2_compression/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libfake_plugin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fake_plugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fake_plugin.dir/build: libfake_plugin.so

.PHONY : CMakeFiles/fake_plugin.dir/build

CMakeFiles/fake_plugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fake_plugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fake_plugin.dir/clean

CMakeFiles/fake_plugin.dir/depend:
	cd /home/mlemsalu/ros2_ws_luke/build/rosbag2_compression && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_compression /home/mlemsalu/ros2_ws_luke/build/rosbag2_compression /home/mlemsalu/ros2_ws_luke/build/rosbag2_compression /home/mlemsalu/ros2_ws_luke/build/rosbag2_compression/CMakeFiles/fake_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fake_plugin.dir/depend

