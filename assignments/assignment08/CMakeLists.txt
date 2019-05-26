cmake_minimum_required(VERSION 3.10.1)
project(assignment08)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(node Node.cpp)
add_library(intlist IntList.cpp)
target_link_libraries(intlist node)

add_executable(testnode testNode.cpp)
target_link_libraries(testnode node)

add_executable(intlisttest intListTest.cpp)
target_link_libraries(intlisttest intlist)

message("Generated with build types: ${CMAKE_BUILD_TYPE}")
