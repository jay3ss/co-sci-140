cmake_minimum_required(VERSION 3.10.1)
project(assignment08)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 11)

add_executable(intlisttest intListTest.cpp)

message("Generated with build types: ${CMAKE_BUILD_TYPE}")
