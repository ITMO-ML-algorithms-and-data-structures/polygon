#include <vector>
#include <iostream>
#include <cassert>
#include <time.h>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;


//СОртировка подсчетом
void СountingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int min_val = *min_element(arr.begin(), arr.end()); // O(n), 4 байта
    int max_val = *max_element(arr.begin(), arr.end()); // O(n), 4 байта

    //Создаём массив частот
    int range = max_val - min_val + 1; // O(1), 4 байта
    vector<int> count(range, 0); // O(range), 4 * range байт

    // Считаем количество вхождений для каждого числа
    for (int num : arr) { // O(n)
        count[num - min_val]++;
    }

    // Перезаписываем массив с учётом частот
    int index = 0; // O(1), 4 байта
    for (int i = 0; i < range; i++) { // O(range + n)
        while (count[i]-- > 0) {
            arr[index++] = i + min_val;
        }
    }
}


// Вывод массива
void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) { // О(n)
        cout << num << " ";
    }
}


// Тесты на правильность ответов (без проверки на скорость)
void correct_tests() {
    vector<int> excepted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> input_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    СountingSort(input_1);
    assert(input_1 == excepted);

    vector<int> input_2 = {2, 7, 8, 5, 3, 4, 6, 9, 0, 1};
    СountingSort(input_2);
    assert(input_2 == excepted);
    
    vector<int> input_3 = {6, 1, 7, 9, 4, 8, 3, 2, 0, 5};
    СountingSort(input_3);
    assert(input_3 == excepted);
    
    vector<int> input_4 = {2, 4, 1, 3, 5, 6, 8, 7, 9, 0};
    СountingSort(input_4);
    assert(input_4 == excepted);
    cout << "Correctness tests - complete" << std::endl;
}


// Тесты на время (без проверки на правильность ответов)
void time_tests() {
    std::vector<int> test_sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,};
    
    for (const int sz : test_sizes) {
        vector<int> random_vec(sz, 0);
        srand(time(0));
        generate(random_vec.begin(), random_vec.end(), rand);
        
        clock_t start = clock();
        СountingSort(random_vec);
        
        cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    vector<int> arr = {3, 9, 1, 4, 2, 8, 5, 7, 6};
    СountingSort(arr);
    printArray(arr);

    return 0;
}

