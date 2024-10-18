cmake_minimum_required(VERSION 3.21)
project(PolygonLabelEncoder)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("googletest")

add_executable(PolygonLabelEncoder main.cpp
        label_encoder.cpp)

# Тесты
add_executable(PolygonLabelEncoderTests tests.cpp
        label_encoder.cpp)

# Линкуем Google Test библиотеки с тестами
target_link_libraries(PolygonLabelEncoderTests gtest_main gtest)

# Включаем тестирование
enable_testing()
add_test(NAME PolygonLabelEncoderTests COMMAND PolygonLabelEncoderTests)

