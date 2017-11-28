cmake_minimum_required(VERSION 3.8)
project(graph_scheme_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Input.h Tag.h Module.h)
add_executable(graph_scheme_cpp ${SOURCE_FILES})