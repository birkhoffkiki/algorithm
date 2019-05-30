cmake_minimum_required(VERSION 3.14)
project(Algorithm_Introduction)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Algorithm_Introduction
        src/sort.cpp
        src/sort.h
        Algorithm_Introduction.cpp)
