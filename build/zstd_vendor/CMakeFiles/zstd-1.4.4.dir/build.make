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
CMAKE_SOURCE_DIR = /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/zstd_vendor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mlemsalu/ros2_ws_luke/build/zstd_vendor

# Utility rule file for zstd-1.4.4.

# Include the progress variables for this target.
include CMakeFiles/zstd-1.4.4.dir/progress.make

CMakeFiles/zstd-1.4.4: CMakeFiles/zstd-1.4.4-complete


CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-install
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-mkdir
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-update
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-patch
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-build
CMakeFiles/zstd-1.4.4-complete: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'zstd-1.4.4'"
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles
	/usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles/zstd-1.4.4-complete
	/usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-done

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-install: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'zstd-1.4.4'"
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && $(MAKE) install
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && /usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-install

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'zstd-1.4.4'"
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/tmp
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src
	/usr/bin/cmake -E make_directory /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp
	/usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-mkdir

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-urlinfo.txt
zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'zstd-1.4.4'"
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src && /usr/bin/cmake -P /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/download-zstd-1.4.4.cmake
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src && /usr/bin/cmake -P /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/verify-zstd-1.4.4.cmake
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src && /usr/bin/cmake -P /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/extract-zstd-1.4.4.cmake
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src && /usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-update: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'zstd-1.4.4'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-update

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-patch: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Performing patch step for 'zstd-1.4.4'"
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4 && patch -p1 -d . < /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/zstd_vendor/cmake_minimum_required_2.8.12.patch && patch -p1 -d . < /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/zstd_vendor/no_internal_headers.patch
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4 && /usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-patch

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure: zstd-1.4.4-prefix/tmp/zstd-1.4.4-cfgcmd.txt
zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-update
zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'zstd-1.4.4'"
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && /usr/bin/cmake -DCMAKE_INSTALL_PREFIX=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd_vendor_install -DZSTD_BUILD_STATIC=OFF -DZSTD_BUILD_SHARED=ON -DZSTD_BUILD_PROGRAMS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=/usr/bin/c++ -DCMAKE_CXX_FLAGS= "-GUnix Makefiles" /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4/build/cmake
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && /usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure

zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-build: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'zstd-1.4.4'"
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && $(MAKE)
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-build && /usr/bin/cmake -E touch /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-build

zstd-1.4.4: CMakeFiles/zstd-1.4.4
zstd-1.4.4: CMakeFiles/zstd-1.4.4-complete
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-install
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-mkdir
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-download
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-update
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-patch
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-configure
zstd-1.4.4: zstd-1.4.4-prefix/src/zstd-1.4.4-stamp/zstd-1.4.4-build
zstd-1.4.4: CMakeFiles/zstd-1.4.4.dir/build.make

.PHONY : zstd-1.4.4

# Rule to build all files generated by this target.
CMakeFiles/zstd-1.4.4.dir/build: zstd-1.4.4

.PHONY : CMakeFiles/zstd-1.4.4.dir/build

CMakeFiles/zstd-1.4.4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zstd-1.4.4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zstd-1.4.4.dir/clean

CMakeFiles/zstd-1.4.4.dir/depend:
	cd /home/mlemsalu/ros2_ws_luke/build/zstd_vendor && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/zstd_vendor /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/zstd_vendor /home/mlemsalu/ros2_ws_luke/build/zstd_vendor /home/mlemsalu/ros2_ws_luke/build/zstd_vendor /home/mlemsalu/ros2_ws_luke/build/zstd_vendor/CMakeFiles/zstd-1.4.4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zstd-1.4.4.dir/depend
