cmake_minimum_required(VERSION 3.8)
project(ros2_parameters)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Create executable
add_executable(param_node src/param_node.cpp)

# Link dependencies
ament_target_dependencies(param_node rclcpp)

# Install executable
install(TARGETS
  param_node
  DESTINATION lib/${PROJECT_NAME}
)

# Testing (MUST come before ament_package)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

