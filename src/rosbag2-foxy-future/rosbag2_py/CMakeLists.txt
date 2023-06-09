cmake_minimum_required(VERSION 3.5)
project(rosbag2_py)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rosbag2_compression REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(rosbag2_storage REQUIRED)

# Find python before pybind11
find_package(python_cmake_module REQUIRED)
find_package(PythonExtra REQUIRED)
if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Set the python debug interpreter.
  # pybind11 will setup the build for debug now.
  set(PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE_DEBUG}")
endif()

find_package(pybind11 REQUIRED)

if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  # pybind11 logic for setting up a debug build when both a debug and release
  # python interpreter are present in the system seems to be pretty much broken.
  # This works around the issue.
  set(PYTHON_LIBRARIES "${PYTHON_DEBUG_LIBRARIES}")
endif()

function(clean_windows_flags target)
  # Hack to avoid pybind11 issue.
  #
  # TODO(ivanpauno):
  # This can be deleted when we update `pybind11_vendor` to a version including
  # https://github.com/pybind/pybind11/pull/2590.
  #
  # They are enabling /LTCG on Windows to reduce binary size,
  # but that doesn't play well with MSVC incremental linking (default for Debug/RelWithDebInfo).
  #
  # See:
  # - https://docs.microsoft.com/en-us/cpp/build/reference/incremental-link-incrementally?view=vs-2019
  # - https://docs.microsoft.com/en-us/cpp/build/reference/ltcg-link-time-code-generation?view=vs-2019

  if(MSVC AND "${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    get_target_property(target_link_libraries ${target} LINK_LIBRARIES)
    list(REMOVE_ITEM target_link_libraries "$<$<NOT:$<CONFIG:Debug>>:-LTCG>")
    set_target_properties(${target} PROPERTIES LINK_LIBRARIES "${target_link_libraries}")

    get_target_property(target_compile_options ${target} COMPILE_OPTIONS)
    list(REMOVE_ITEM target_compile_options "$<$<NOT:$<CONFIG:Debug>>:/GL>")
    set_target_properties(${target} PROPERTIES COMPILE_OPTIONS "${target_compile_options}")
  endif()
endfunction()

function(reorder_pybind_include_directories _target)
  # Hack to fix overlay workspace include directories order
  # Needs to be removed/revised after https://github.com/ros2/ros2/issues/1150 gets fixed
  # Needs to be called instead of ament_target_dependencies for all targets created via pybind11_add_module
  #
  # Ros uses its own pybind11 library. It is installed to /opt/ros/foxy folder, so INCLUDE_DIRECTORIES property
  # of target created via pybind11_add_module is polluted with /opt/ros/foxy/include
  # All includes found in that directory are used instead of local workspace

  # Get all values from INCLUDE_DIRECTORIES property
  get_property(_pybind_include_directories TARGET ${_target} PROPERTY INCLUDE_DIRECTORIES)
  # Clear all values from INCLUDE_DIRECTORIES property
  set_property(TARGET ${_target} PROPERTY INCLUDE_DIRECTORIES "")
  # Add ament dependencies
  ament_target_dependencies(${_target} PUBLIC ${ARGN})
  # Restore INCLUDE_DIRECTORIES property
  set_property(TARGET ${_target} APPEND PROPERTY INCLUDE_DIRECTORIES ${_pybind_include_directories})
endfunction()

ament_python_install_package(${PROJECT_NAME})

pybind11_add_module(_reader SHARED SYSTEM
  src/rosbag2_py/_reader.cpp
)
reorder_pybind_include_directories(_reader
  "rosbag2_compression"
  "rosbag2_cpp"
  "rosbag2_storage"
)
clean_windows_flags(_reader)

pybind11_add_module(_storage SHARED SYSTEM
  src/rosbag2_py/_storage.cpp
  src/rosbag2_py/format_bag_metadata.cpp
)
reorder_pybind_include_directories(_storage
  "rosbag2_cpp"
  "rosbag2_storage"
)
clean_windows_flags(_storage)

pybind11_add_module(_writer SHARED SYSTEM
  src/rosbag2_py/_writer.cpp
)
reorder_pybind_include_directories(_writer
  "rosbag2_compression"
  "rosbag2_cpp"
  "rosbag2_storage"
)
clean_windows_flags(_writer)

pybind11_add_module(_info SHARED SYSTEM
  src/rosbag2_py/_info.cpp
)
reorder_pybind_include_directories(_info
  "rosbag2_cpp"
  "rosbag2_storage"
)
clean_windows_flags(_info)

# Install cython modules as sub-modules of the project
install(
  TARGETS
    _reader
    _storage
    _writer
    _info
  DESTINATION "${PYTHON_INSTALL_DIR}/${PROJECT_NAME}"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
  find_package(ament_cmake_pytest REQUIRED)

  set(_PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE}")
  if(WIN32 AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(_PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE_DEBUG}")
  endif()
  set(other_environment_vars)
  if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Work around a rtti bug when using class_loader from a
    # python extension built with libc++.
    set(other_environment_vars "ROSBAG2_PY_TEST_WITH_RTLD_GLOBAL=True")
  endif()
  ament_add_pytest_test(test_sequential_reader_py "test/test_sequential_reader.py"
    PYTHON_EXECUTABLE "${_PYTHON_EXECUTABLE}"
    APPEND_ENV
      PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}
      ${other_environment_vars}
  )
  ament_add_pytest_test(test_sequential_writer_py
    "test/test_sequential_writer.py"
    PYTHON_EXECUTABLE "${_PYTHON_EXECUTABLE}"
    APPEND_ENV "PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}" ${other_environment_vars}
  )
endif()

ament_package()
