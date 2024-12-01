cmake_minimum_required(VERSION 3.13)  # Минимальная версия CMake
project(SortingTests)  # Название проекта (можно изменить)

find_package(GTest REQUIRED)  # Найти Google Test

add_executable(sorting_tests sorting.cpp unit_test.cpp) # Создать исполняемый файл

target_link_libraries(sorting_tests GTest::gtest_main) # Подключить Google Test
