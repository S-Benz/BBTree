cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BBtree.h.h BBTree.cpp)
add_executable(bbtree ${SOURCE_FILES})