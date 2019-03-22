cmake_minimum_required(VERSION 3.5)
project(chapter14notes)
set(CMAKE_CXX_STANDARD 11)

# To allow separation of definition and implementation
include_directories(${PROJECT_SOURCE_DIR})

add_executable(treeStaticMemberFunctionProg treeStaticMemberFunctionProg.cpp Tree.h)
add_executable(budgetStaticMemberFunctionProg budgetStaticMemberFunctionProg.cpp Auxil.cpp Budget.cpp)