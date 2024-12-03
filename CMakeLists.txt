set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

cmake_minimum_required(VERSION 3.10)
project(LAB4_Sorting_Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_C99=1 -D_GLIBCXX_HAS_QUICK_EXIT=0 -D_GLIBCXX_USE_CXX11_ABI=0")

set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/clang")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/clang++")

set(CUNIT_INCLUDE_DIRS "C:/msys64/mingw64/include")
set(CUNIT_LIBRARIES "C:/msys64/mingw64/lib/libcunit.a")

include_directories(${CUNIT_INCLUDE_DIRS})
link_directories(${CUNIT_LIBRARIES})

add_subdirectory(src)
add_subdirectory(test)
