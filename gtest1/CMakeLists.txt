cmake_minimum_required(VERSION 3.10)
project(gtest1)
set(CMAKE_CXX_STANDARD 14)

##　找到gtest的头文件,并加入到directories中
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
##　将可执行文件executeTests与gtest的库文件关联
add_executable(executeTests sqrt_test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)