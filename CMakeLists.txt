cmake_minimum_required(VERSION 3.8)
project(cpp_notes)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(notes)
add_executable(main main.cpp)
