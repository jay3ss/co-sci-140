cmake_minimum_required(VERSION 3.5.1)
project(midterm)
set(CMAKE_CXX_STANDARD 11)

##################################
# Sources for midterm executable #
##################################
set(SOURCES
    midterm.cpp
    Student.cpp
    # add more as necessary
)
add_executable(midterm ${SOURCES})