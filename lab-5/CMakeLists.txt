cmake_minimum_required(VERSION 3.20)
project(sorts)

set(CMAKE_CXX_STANDARD 17)

# Основные файлы сортировок
add_library(comb_sort comb.cpp)
add_library(timsort timsort.cpp)
add_library(introsort introsort.cpp)

# Добавляем директорию с googletest
add_subdirectory(googletest)

# Юнит-тесты и отчет
add_executable(test_sorts
        test_sorts.cpp)
add_executable(otchet otchet.cpp)

target_link_libraries(otchet comb_sort timsort introsort)
target_link_libraries(test_sorts comb_sort timsort introsort gtest gtest_main)

# Настройка тестов
enable_testing()
add_test(NAME SortingTests COMMAND test_sorts)



