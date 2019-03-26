cmake_minimum_required(VERSION 3.5.1)
project(assignment05)
set(CMAKE_CXX_STANDARD 11)

##########################
# MagicBox class-related #
##########################
set(SOURCES
    assignment05.cpp
)
add_executable(assignment05 ${SOURCES})
target_include_directories(assignment05
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)