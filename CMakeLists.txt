cmake_minimum_required(VERSION 3.26)
project(pilocal)

set(CMAKE_CXX_STANDARD 20)
include_directories("/home/polya/cppLocal/msgpack-c-cpp_master/include")
include_directories("/usr/local/include/eigen-3.4.0")

add_executable(mc main.cpp
            )


add_executable(read read.cpp)