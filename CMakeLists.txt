cmake_minimum_required(VERSION 3.5)

project(Realsense_CPP)

find_package(OpenCV REQUIRED)

add_library(realsense_lib SHARED src/realsense.cpp)
target_link_libraries(realsense_lib PUBLIC ${OpenCV_LIBS} realsense2)
target_include_directories(realsense_lib PUBLIC include)


add_subdirectory(demo)

