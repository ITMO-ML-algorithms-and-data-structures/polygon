#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <time.h>
#include <cmath>


// Функция для получения i-й цифры числа
int getDigit(int number, int digitPosition) {
    return (number / (int)pow(10, digitPosition)) % 10; 
}


// Функция сортировки, использующая Counting Sort на основании разряда
void countingSort(std::vector<int>& arr, int digitPosition) {
    const int base = 10; // Мы используем десятичную систему, 4 байта
    int n = arr.size(); // 4 байта
    
    std::vector<int> output(n); // Временный вектор для отсортированных значений, 24 + 4п байт
    std::vector<int> count(base, 0); // Вектор счетчиков для каждой цифры, 24 + 4 * 10 = 64 байта
    
    // Подсчитываем количество элементов по текущему разряду
    for (int i = 0; i < n; i++) { // О(n)
        int digit = getDigit(arr[i], digitPosition);
        count[digit]++;
    }
    
    // Изменяем count[i] так, чтобы count[i] содержал позицию этого разряда в выходном массиве
    for (int i = 1; i < base; i++) { // всего 9 итераций
        count[i] += count[i - 1];
    }
    
    // Строим выходной массив
    for (int i = n - 1; i >= 0; i--) { // О(n)
        int digit = getDigit(arr[i], digitPosition); // 4 байта
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    
    // Копируем отсортированные элементы обратно в исходный массив
    for (int i = 0; i < n; i++) { // О(n)
        arr[i] = output[i];
    }
}


// Основная функция Radix Sort
void radixSort(std::vector<int>& arr) {
    // Найдем максимальное число, чтобы знать, сколько разрядов нам нужно сортировать
    int maxElement = *max_element(arr.begin(), arr.end()); // О(п)
    
    // Определим количество разрядов
    int digitPosition = 0;
    while (maxElement > 0) { // О(maxElement / 10)
        countingSort(arr, digitPosition);
        maxElement /= 10;
        digitPosition++;
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
    std::vector<int> excepted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::vector<int> input_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    radixSort(input_1);
    assert(input_1 == excepted);

    std::vector<int> input_2 = {2, 7, 8, 5, 3, 10, 4, 6, 9, 0, 1};
    radixSort(input_2);
    assert(input_2 == excepted);
    
    std::vector<int> input_3 = {6, 1, 7, 9, 4, 10, 8, 3, 2, 0, 5};
    radixSort(input_3);
    assert(input_3 == excepted);
    
    std::vector<int> input_4 = {2, 4, 1, 3, 5, 6, 8, 7, 10, 9, 0};
    radixSort(input_4);
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
        radixSort(random_vec);
        
        std::cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << std::endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    std::vector<int> array = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(array);
    printArray(array);
    return 0;
}