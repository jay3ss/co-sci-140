cmake_minimum_required(VERSION 3.5)
project(assignment04)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(testingground testingground.cpp)
# add_executable(playground playground.cpp)
add_executable(assignment04 assignment04.cpp Question.cpp)