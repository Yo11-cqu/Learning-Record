cmake_minimum_required(VERSION 3.10)

project(opencv_learning)

find_package(OpenCV REQUIRED)

add_executable(image_read src/Img_operation.cpp)
add_executable(video_read src/Video_operation.cpp)

target_link_libraries(image_read ${OpenCV_LIBS})
target_link_libraries(video_read ${OpenCV_LIBS})