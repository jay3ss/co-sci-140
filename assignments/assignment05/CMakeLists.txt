cmake_minimum_required(VERSION 3.5.1)
project(assignment05)
set(CMAKE_CXX_STANDARD 11)

#######################################
# Sources for assignment05 executable #
#######################################
set(SOURCES
    assignment05.cpp
    FeetInches.cpp
)
add_executable(assignment05 ${SOURCES})