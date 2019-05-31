cmake_minimum_required(VERSION 3.10.1)
project(finalexam LANGUAGES CXX)
# project(finalexam)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(charinput CharInput.hpp)
add_library(final Final.hpp)
set_target_properties(charinput final PROPERTIES LINKER_LANGUAGE CXX)

add_executable(finalexam finalexam.cpp)
target_link_libraries(finalexam charinput final)


add_executable(testcharinput testcharinput.cpp)
