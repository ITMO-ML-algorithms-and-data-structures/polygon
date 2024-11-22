cmake_minimum_required(VERSION 3.10)
project(polygon)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

add_subdirectory(libs/indicators)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests tests/tests.cpp)
add_executable(main main.cpp)
add_executable(tmp tmp.cpp)

target_link_libraries(main armadillo indicators)
target_link_libraries(tests GTest::gtest_main armadillo indicators)
target_link_libraries(tmp armadillo)

include(GoogleTest)
gtest_discover_tests(tests)