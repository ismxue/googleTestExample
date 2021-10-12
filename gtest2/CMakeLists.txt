cmake_minimum_required(VERSION 3.10)
project(gtest2)

set(CMAKE_CXX_STANDARD 14)
#加载相关的头文件和库文件
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

##单独测试加法
#add_executable(exec1 Addition_Test.cpp)
#target_link_libraries(exec1 ${GTEST_LIBRARIES} pthread)
##单独测试乘法
#add_executable(exec2 Multiply_Test.cpp)
#target_link_libraries(exec2 ${GTEST_LIBRARIES} pthread)
#加法和乘法都测试
add_executable(executeTests Main_TestAll.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)