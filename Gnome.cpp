#include <iostream>
#include <cassert>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

// Гномья сортировка
void GnomeSort(vector<int>& arr) {
    int n = arr.size(); // O(1), 4 байта
    int index = 0; // O(1), 4 байта
    
    // Дополнительной памяти нет, так как массив изменяется на месте.

    // Проходимся по массиву
    while (index < n) { // В худшем случае: O(n^2)
        //Если порядок двух соседних элементов правильный идем дальше
        if (index==0 || arr[index] >= arr[index - 1]) {
            index++; // O(1)
        } 
        else {
            //меняем соседние элементы местами и отходим назад по индексу
            swap(arr[index], arr[index-1]); // O(1)
            index--; // O(1)
        }
    }
}


//Вывод массива
void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) { // О(n)
        cout << num << " ";
    }
}


// Тесты на правильность ответов (без проверки на скорость)
void correct_tests() {
    vector<int> excepted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> input_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    GnomeSort(input_1);
    assert(input_1 == excepted);

    vector<int> input_2 = {2, 7, 8, 5, 3, 4, 6, 9, 0, 1};
    GnomeSort(input_2);
    assert(input_2 == excepted);
    
    vector<int> input_3 = {6, 1, 7, 9, 4, 8, 3, 2, 0, 5};
    GnomeSort(input_3);
    assert(input_3 == excepted);
    
    vector<int> input_4 = {2, 4, 1, 3, 5, 6, 8, 7, 9, 0};
    GnomeSort(input_4);
    assert(input_4 == excepted);
    cout << "Correctness tests - complete" << std::endl;
}


// Тесты на время (без проверки на правильность ответов)
void time_tests() {
    std::vector<int> test_sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, };
    
    for (const int sz : test_sizes) {
        vector<int> random_vec(sz, 0);
        srand(time(0));
        generate(random_vec.begin(), random_vec.end(), rand);
        
        clock_t start = clock();
        GnomeSort(random_vec);
        
        cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    vector<int> arr = {3, 9, 1, 4, 2, 8, 5, 7, 6};
    GnomeSort(arr);
    printArray(arr);

    return 0;
}