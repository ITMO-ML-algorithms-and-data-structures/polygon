cmake_minimum_required(VERSION 3.21)
project(polygon)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(label_encoder_test tests/label_encoder_tests.cpp)

add_executable(polygon main.cpp)

target_link_libraries(
        label_encoder_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(label_encoder_test)
