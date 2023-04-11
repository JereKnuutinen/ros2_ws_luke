# CMake generated Testfile for 
# Source directory: /home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins
# Build directory: /home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_sqlite_wrapper "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/test_sqlite_wrapper.gtest.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_cmake_gmock/test_sqlite_wrapper.txt" "--command" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_sqlite_wrapper" "--gtest_output=xml:/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/test_sqlite_wrapper.gtest.xml")
set_tests_properties(test_sqlite_wrapper PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_sqlite_wrapper" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;106;ament_add_test;/opt/ros/foxy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;52;_ament_add_gmock;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;86;ament_add_gmock;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(test_sqlite_storage "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/test_sqlite_storage.gtest.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_cmake_gmock/test_sqlite_storage.txt" "--command" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_sqlite_storage" "--gtest_output=xml:/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/test_sqlite_storage.gtest.xml")
set_tests_properties(test_sqlite_storage PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_sqlite_storage" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;106;ament_add_test;/opt/ros/foxy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;52;_ament_add_gmock;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;94;ament_add_gmock;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(copyright "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/copyright.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_copyright/copyright.txt" "--command" "/opt/ros/foxy/bin/ament_copyright" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/copyright.xunit.xml")
set_tests_properties(copyright PROPERTIES  LABELS "copyright;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_copyright/cmake/ament_copyright.cmake;41;ament_add_test;/opt/ros/foxy/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;18;ament_copyright;/opt/ros/foxy/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(cppcheck "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/cppcheck.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/foxy/bin/ament_cppcheck" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/cppcheck.xunit.xml" "--include_dirs" "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;61;ament_add_test;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;83;ament_cppcheck;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(cpplint "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/cpplint.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_cpplint/cpplint.txt" "--command" "/opt/ros/foxy/bin/ament_cpplint" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/cpplint.xunit.xml")
set_tests_properties(cpplint PROPERTIES  LABELS "cpplint;linter" TIMEOUT "120" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_cpplint/cmake/ament_cpplint.cmake;68;ament_add_test;/opt/ros/foxy/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;35;ament_cpplint;/opt/ros/foxy/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/lint_cmake.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/foxy/bin/ament_lint_cmake" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;41;ament_add_test;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/uncrustify.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/foxy/bin/ament_uncrustify" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;65;ament_add_test;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;34;ament_uncrustify;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/xmllint.xunit.xml" "--package-name" "rosbag2_storage_default_plugins" "--output-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/ament_xmllint/xmllint.txt" "--command" "/opt/ros/foxy/bin/ament_xmllint" "--xunit-file" "/home/mlemsalu/ros2_ws_luke/build/rosbag2_storage_default_plugins/test_results/rosbag2_storage_default_plugins/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;103;ament_package;/home/mlemsalu/ros2_ws_luke/src/rosbag2-foxy-future/rosbag2_storage_default_plugins/CMakeLists.txt;0;")
subdirs("gmock")
subdirs("gtest")
