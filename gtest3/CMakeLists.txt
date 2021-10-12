cmake_minimum_required(VERSION 3.10)
project(gtest3)
set(CMAKE_CXX_STANDARD 14)
#加载gtest相关的头文件和库文件
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 简单的TEST用例
add_executable(demo1 demo1_test.cpp)
target_link_libraries(demo1 ${GTEST_LIBRARIES} pthread)

add_executable(demo2 demo2_bank.cpp)
target_link_libraries(demo2 ${GTEST_LIBRARIES} pthread)


