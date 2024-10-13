cmake_minimum_required(VERSION 3.29)
project(polygon)

set(CMAKE_CXX_STANDARD 14)

add_executable(LabelEncoder main.cpp)


find_package(GTest REQUIRED)

add_executable(LabelEncoderTests tests.cpp)



target_link_libraries(LabelEncoderTests GTest::GTest GTest::Main pthread)

enable_testing()
add_test(NAME LabelEncoderTests COMMAND LabelEncoderTests)


