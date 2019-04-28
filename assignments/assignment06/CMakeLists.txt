cmake_minimum_required(VERSION 3.10.1)
project(assignment06)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 11)

# Set the sources
set(BASIC_SHAPE_SRC BasicShape.h)
set(CIRCLE_SRC ${BASIC_SHAPE_SRC} Circle.cpp)
set(RECTANGLE_SRC ${BASIC_SHAPE_SRC} Rectangle.cpp)
# Create the executable
add_executable(shapestest
    shapesTest.cpp
    ${CIRCLE_SRC}
    ${RECTANGLE_SRC}
)


message("Generated with build types: ${CMAKE_BUILD_TYPE}")