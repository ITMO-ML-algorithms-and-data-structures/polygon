#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <time.h>


void shakerSort(std::vector<int>& arr) {
    int left = 0; // Начало массива, 4 байта
    int right = arr.size() - 1; // Конец массива, 4 байта
    bool swapped; // Флаг, указывающий на то, было ли произведено обмен, 1 байт

    do { // O(n) в худшем случае
        swapped = false;

        // Проходим по массиву слева направо
        for (int i = left; i < right; ++i) { // О(n) в худшем случае
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]); // Обмен элементов
                swapped = true; // Установим флаг, если произошел обмен
            }
        }
        // Уменьшаем правую границу, так как последний элемент уже на месте
        right--;

        // Если не было обменов, массив уже отсортирован
        if (!swapped) {
            break;
        }

        swapped = false;

        // Проходим по массиву справа налево
        for (int i = right; i > left; --i) { // О(n) в худшем случае
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]); // Обмен элементов
                swapped = true; // Установим флаг, если произошел обмен
            }
        }
        // Увеличиваем левую границу, так как первый элемент уже на месте
        left++;

    } while (left <= right); // Повторяем, пока левая граница не превысит правую
}


// Вывод массива
void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) { // О(n)
        std::cout << num << " ";
    }
}


// Тесты на правильность ответов (без проверки на скорость)
void correct_tests() {
    std::vector<int> excepted = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::vector<int> input_1 = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shakerSort(input_1);
    assert(input_1 == excepted);

    std::vector<int> input_2 = {2, -1, 7, -5, 8, -4, -6, 5, -10, -8, 3, 10, -9, -3, 4, 6, 9, 0, -2, 1, -7};
    shakerSort(input_2);
    assert(input_2 == excepted);
    
    std::vector<int> input_3 = {-3, -9, 6, -5, -8, -2, -1, 1, -6, -4, 7, -7, 9, 4, 10, 8, 3, 2, -10, 0, 5};
    shakerSort(input_3);
    assert(input_3 == excepted);
    
    std::vector<int> input_4 = {0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10};
    shakerSort(input_4);
    assert(input_4 == excepted);
    std::cout << "Correctness tests - complete" << std::endl;
}


// Тесты на время (без проверки на правильность ответов)
void time_tests() {
    std::vector<int> test_sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
    
    for (const int sz : test_sizes) {
        std::vector<int> random_vec(sz, 0);
        srand(time(0));
        generate(random_vec.begin(), random_vec.end(), rand);
        
        clock_t start = clock();
        shakerSort(random_vec);
        
        std::cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << std::endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    std::vector<int> array = { 15, 41, 543, 12, 523, 12, 5, 0, -21, -412, 532 };
    shakerSort(array);
    printArray(array);
    return 0;
}