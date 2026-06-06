cmake_minimum_required(VERSION 3.0)

project(student_doc_system)

#PROJECT_BINARY_DIR是指当前的执行目录，我们准备在build目录里面执行，所以这样写
#也可以用PROJECT_SOURCE_DIR,也就是根目录
#将src目录里面的所有源文件打包成SRC_LIST变量
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST )

include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_executable(student_doc_system ${SRC_LIST})

