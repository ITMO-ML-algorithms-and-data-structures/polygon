cmake_minimum_required(VERSION 3.10)

project(ClusterizationProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()