cmake_minimum_required(VERSION 3.29)
project(4hw)

set(CMAKE_CXX_STANDARD 14)

add_executable(4hw
    binary_insertion_sort.cpp
    execute_sort.cpp
    ../execute.cpp
        binary_insertion_sort.h
        smooth_sort.cpp
        "counting sort.cpp"
        "counting sort.h")