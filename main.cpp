//
// Created by Тимур Сурин on 22.11.2024.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1}; // Исходный массив
    set<int> s;

    // Добавляем элементы массива во множество
    for (int num : arr) {
        s.insert(num);
    }

    // Выводим уникальные элементы
    cout << "Уникальные элементы массива: ";
    for (const int& elem : s) {
        cout << elem << ' ';
    }
    cout << endl;

    return 0;
}