#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& array) { // O(n + k), где k - диапазон значений
    if (array.empty()) return; // O(1)

    int maxValue = *max_element(array.begin(), array.end()); // O(n), память O(1)
    vector<int> count(maxValue + 1, 0); // O(k), память O(k)

    // Подсчет частоты элементов
    for (int num : array) { // O(n)
        count[num]++; // O(1)
    }

    int index = 0; // O(1)
    for (int i = 0; i <= maxValue; i++) { // O(k)
        while (count[i] > 0) { // O(n)
            array[index++] = i; // O(1)
            count[i]--; // O(1)
        }
    }
}
/*
Сложности:
- Поиск максимального элемента: O(n).
- Подсчет частоты элементов: O(n).
- Заполнение отсортированного массива: O(n + k), где k — максимальное значение в массиве.

Общая сложность: O(n + k), где n — размер массива, k — максимальное значение. Для эффективного выполнения требуется, чтобы k было небольшим по сравнению с n.

Память:
- Хранение массива: O(n).
- Вектор счетчиков: O(k).

Чистая память: O(n + k).
*/

vector<int> readArrayFromFile(const string& fileName) { // O(n)
    ifstream inFile(fileName);
    assert(inFile.is_open() && "Не удалось открыть файл!");
    vector<int> array;
    int number;

    while (inFile >> number) { // O(n)
        array.push_back(number); // O(1)
    }
    inFile.close(); // O(1)
    return array; // O(1)
}

void test() {
    {
        vector<int> arr1 = { 5, 3, 8, 4, 2 };
        countingSort(arr1);
        assert((arr1 == vector<int>{2, 3, 4, 5, 8}));
    }
    {
        vector<int> arr2 = { 1, 2, 3, 4 };
        countingSort(arr2);
        assert((arr2 == vector<int>{1, 2, 3, 4}));
    }
    {
        vector<int> arr3 = { 2, 1 };
        countingSort(arr3);
        assert((arr3 == vector<int>{1, 2}));
    }
    {
        vector<int> arr4 = {};
        countingSort(arr4);
        assert(arr4.empty());
    }
    {
        vector<int> arr5 = { 3, 3, 3 };
        countingSort(arr5);
        assert((arr5 == vector<int>{3, 3, 3}));
    }

}

int main() {
    // Тесты 
    test();
    cout << "All right!" << '\n';

    // Чтение массива из файла
    vector<int> array = readArrayFromFile("1000.txt");

    // Сортировка
    auto start = chrono::high_resolution_clock::now();
    countingSort(array); // O(n + k)
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << duration.count() / 1e6 << '\n';
    return 0;
}
