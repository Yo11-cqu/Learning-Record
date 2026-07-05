cmake_minimum_required(VERSION 3.10)

project(opencv_learning)

find_package(OpenCV REQUIRED)

add_executable(video src/video_operation.cpp)

target_link_libraries(video ${OpenCV_LIBS})