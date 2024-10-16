#include <vector>
#include <iostream>
#include <fstream>
#include <random>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Source/doctest.h"

/*

Алгоритм "перемешивания" элементов массива - берем последний элемент и меняем его местами со случайным элементом,
затем берем предпоследний элемент и меняем его местами со случайным элементом, не включая последний элемент.
Таким образом, в процессе работы алгоритма будет увеличиваться "перемешанный хвост", а по его завершении массив будет равномерно перемешан

*/

std::vector<long long> shuffle(const std::string& path) {

    // Формат файла с массивом: первое число - длина массива (n), далее n строк с одним числом в каждой

    std::ifstream file(path); // O(1) + О(1) инициализация и открытие файла
    size_t size; file >> size; // О(1) + О(1) + О(1) выделение памяти, считывание значения, присваивание

    std::random_device rd; // О(1) инициализация
    std::mt19937 gen(rd()); // О(1) инициализация

    std::vector<long long> array(size); // О(N) выделение памяти
    for (size_t i = 0; i < size; i++) // О(1) + О(1) + О(1) + О(1) выделение памяти, присваивание, сравнение, изменение значения

        // О(N) в любом случае

        file >> array[i]; // О(1) + О(1) + О(1) считывание значения, взятие элемента по индексу, присваивание

    for (int i = size - 1; i >= 0; i--) { // О(1) + О(1) + О(1) + О(1) выделение памяти, присваивание, сравнение, изменение значения

        // О(N) в любом случае

        std::uniform_int_distribution<> dist(0, i); // О(1) инициализация
        size_t random_index = dist(gen); // О(1) + О(1) + О(1) выделение памяти, генерация числа, присваивание 

        std::swap(array[i], array[random_index]); // 8 * О(1) выделение памяти на временную переменную, взятие элемента по индексу,
                                                  // присваивание значение array[i] для этой переменной, взятие элемента по индексу х2, присваивание значение array[random_index] для array[i],
                                                  // взятие элемента по индексу, присваивание значения временной переменной для array[random_index] 

    }

    // Сложность алгоритма составляет О(N) в любом случае

    return array;

}

// Тесты

TEST_CASE("Testing the shuffle() function") {

    std::string 
        path1 = "./Tests/shuffle/test_shuffle_1.csv", // Пустой файл
        path2 = "./Tests/shuffle/test_shuffle_2.csv", // Файл с обычным массивом
        path3 = "./Tests/shuffle/test_shuffle_3.csv", // Файл с одинаковыми числами
        path4 = "./Tests/shuffle/test_shuffle_4.csv"; // файл с одним числом
            
    CHECK(shuffle(path1) == std::vector<long long> {});
    CHECK(shuffle(path2) != shuffle(path2)); // Могут быть равны лишь в одном случае, который крайне маловероятен
    CHECK(shuffle(path3) == std::vector<long long> {1, 1, 1, 1, 1, 1});
    CHECK(shuffle(path4) == std::vector<long long> {178236});

}