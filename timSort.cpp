#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <time.h>

// Размер "бега", для сортировки вставками
const int RUN = 32;

// Функция сортировки вставками для сортировки небольших массивов
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) { // O(right - left + 1)
        int key = arr[i]; // 4 байта
        int j = i - 1; // 4 байта

        // Вставляем arr[i] в отсортированную часть
        while (j >= left && arr[j] > key) { // О(right - left + 1)
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция слияния двух отсортированных "бегов"
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Находим размеры двух подсортированных массивов
    int len1 = mid - left + 1; 
    int len2 = right - mid; 
    // Все по 4 байта
     
    // Создаем временные массивы
    std::vector<int> leftArray(len1);
    std::vector<int> rightArray(len2);
    // Все по 24 + 4n байт

    // Заполняем временные массивы
    for (int i = 0; i < len1; i++) // O(len1)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < len2; j++) // O(len2)
        rightArray[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в основной массив
    int i = 0; // Начальный индекс первого подмассива
    int j = 0; // Начальный индекс второго подмассива
    int k = left; // Начальный индекс для слияния
    // Все по 4 байта

    while (i < len1 && j < len2) { // O(len1 + len2)
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы, если есть
    while (i < len1) { // O(len1)
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < len2) { // O(len2)
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Основная функция Timsort
void timSort(std::vector<int>& arr) {
    int n = arr.size(); // 4 байта

    // Сортировка подмассивов (бегов) длины RUN
    for (int start = 0; start < n; start += RUN) { // О(n)
        int end = std::min(start + RUN - 1, n - 1); // 4 байта
        insertionSort(arr, start, end);
    }

    // Слияние подмассивов в порядке возрастания
    for (int size = RUN; size < n; size *= 2) { // О(log(n))
        for (int left = 0; left < n; left += 2 * size) { // O(n)
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min((left + 2 * size - 1), (n - 1));

            // Слияние подмассивов
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
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
    timSort(input_1);
    assert(input_1 == excepted);

    std::vector<int> input_2 = {2, -1, 7, -5, 8, -4, -6, 5, -10, -8, 3, 10, -9, -3, 4, 6, 9, 0, -2, 1, -7};
    timSort(input_2);
    assert(input_2 == excepted);
    
    std::vector<int> input_3 = {-3, -9, 6, -5, -8, -2, -1, 1, -6, -4, 7, -7, 9, 4, 10, 8, 3, 2, -10, 0, 5};
    timSort(input_3);
    assert(input_3 == excepted);
    
    std::vector<int> input_4 = {0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10};
    timSort(input_4);
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
        timSort(random_vec);
        
        std::cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << std::endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    std::vector<int> array = { 15, 41, 543, 12, 523, 12, 5, 0, -21, -412, 532 };
    timSort(array);
    printArray(array);
    return 0;
}