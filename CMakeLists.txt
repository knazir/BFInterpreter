cmake_minimum_required(VERSION 3.6)
project(BFInterpreter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES bf.cpp)
add_executable(BFInterpreter ${SOURCE_FILES})