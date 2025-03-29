cmake_minimum_required(VERSION 3.5)

add_executable(realsense_cam_feed test_camera.cpp)
target_link_libraries(realsense_cam_feed PUBLIC realsense_lib)
