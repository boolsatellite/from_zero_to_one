cmake_minimum_required(VERSION 3.16)
project(zero_thread)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(
        main.cc
        zero_thread.cc main.cc)
