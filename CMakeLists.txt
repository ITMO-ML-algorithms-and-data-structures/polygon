cmake_minimum_required(VERSION 3.10)

# Название проекта
project(SortingTests)

# Добавляем подкаталог для Google Test
add_subdirectory(C:/Users/Admin/Desktop/labs_algos/googletest)

# Основная программа
add_executable(SortingMain main.cpp sort_algorithms.cpp)

# Тесты
add_executable(SortingTests test_example.cpp sort_algorithms.cpp)
target_link_libraries(SortingTests gtest gtest_main)
