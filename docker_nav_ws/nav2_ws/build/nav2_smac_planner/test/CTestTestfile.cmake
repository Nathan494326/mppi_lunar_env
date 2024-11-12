# CMake generated Testfile for 
# Source directory: /workstation/nav2_ws/src/navigation2/nav2_smac_planner/test
# Build directory: /workstation/nav2_ws/build/nav2_smac_planner/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_costmap_downsampler "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_costmap_downsampler.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_costmap_downsampler.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_costmap_downsampler" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_costmap_downsampler.gtest.xml")
set_tests_properties(test_costmap_downsampler PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_costmap_downsampler" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;2;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_node2d "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_node2d.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_node2d.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_node2d" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_node2d.gtest.xml")
set_tests_properties(test_node2d PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_node2d" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;13;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_nodehybrid "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_nodehybrid.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_nodehybrid.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_nodehybrid" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_nodehybrid.gtest.xml")
set_tests_properties(test_nodehybrid PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_nodehybrid" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;24;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_nodebasic "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_nodebasic.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_nodebasic.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_nodebasic" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_nodebasic.gtest.xml")
set_tests_properties(test_nodebasic PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_nodebasic" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;35;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_collision_checker "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_collision_checker.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_collision_checker.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_collision_checker" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_collision_checker.gtest.xml")
set_tests_properties(test_collision_checker PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_collision_checker" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;46;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_a_star "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_a_star.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_a_star.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_a_star" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_a_star.gtest.xml")
set_tests_properties(test_a_star PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_a_star" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;57;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_smac_hybrid "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_hybrid.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_smac_hybrid.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_hybrid" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_hybrid.gtest.xml")
set_tests_properties(test_smac_hybrid PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_hybrid" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;68;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_smac_2d "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_2d.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_smac_2d.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_2d" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_2d.gtest.xml")
set_tests_properties(test_smac_2d PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_2d" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;79;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_smac_lattice "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_lattice.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_smac_lattice.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_lattice" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smac_lattice.gtest.xml")
set_tests_properties(test_smac_lattice PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smac_lattice" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;90;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_smoother "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smoother.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_smoother.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smoother" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_smoother.gtest.xml")
set_tests_properties(test_smoother PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_smoother" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;101;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
add_test(test_lattice_node "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_lattice_node.gtest.xml" "--package-name" "nav2_smac_planner" "--output-file" "/workstation/nav2_ws/build/nav2_smac_planner/ament_cmake_gtest/test_lattice_node.txt" "--command" "/workstation/nav2_ws/build/nav2_smac_planner/test/test_lattice_node" "--gtest_output=xml:/workstation/nav2_ws/build/nav2_smac_planner/test_results/nav2_smac_planner/test_lattice_node.gtest.xml")
set_tests_properties(test_lattice_node PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workstation/nav2_ws/build/nav2_smac_planner/test/test_lattice_node" TIMEOUT "60" WORKING_DIRECTORY "/workstation/nav2_ws/build/nav2_smac_planner/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;114;ament_add_gtest;/workstation/nav2_ws/src/navigation2/nav2_smac_planner/test/CMakeLists.txt;0;")
subdirs("../gtest")