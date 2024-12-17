cmake_minimum_required(VERSION 3.10)

project(SortProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(sort1 sort1.cpp)
add_executable(sort2 sort2.cpp)
add_executable(sort3 sort3.cpp)

enable_testing()
add_executable(my_test test.cpp)
add_test(NAME test1 COMMAND my_test)