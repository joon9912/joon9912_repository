cmake_minimum_required(VERSION 3.23)
project(myProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(myProject main.cpp)

set(CMAKE_C_FLAGS "-fexec-charset=CP949")