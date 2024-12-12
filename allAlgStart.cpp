#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "CombSort/CombSort.cpp"
#include "TreeSort/TreeSort.cpp"
#include "BeadSort/BeadSort.cpp"

using namespace std;
using namespace chrono;

template <typename Sort>
void timeSort(Sort sortFunc, vector<int> a, const string& sortName) {
    cout << "Массив размером: " << a.size() << endl;
    auto start = high_resolution_clock::now();
    sortFunc(a); // Вызываем сортировочную функцию
    auto end = high_resolution_clock::now();
    duration<double> duration_sec = end - start;
    cout << sortName << " завершен за: " << duration_sec.count() << " секунд" << endl;
}

int main() {
    ifstream inputFile("E:/СLabs/lab1/polygon/generateArr/f.txt");

    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
        return 1;
    }
    
    vector<int> a;
    int value;

    // Считывание данных из файла
    while (inputFile >> value) {
        a.push_back(value);
    }
    
    inputFile.close();

    // Запуск Comb Sort
    timeSort(combSort, a, "Comb Sort");

    // Запуск Tree Sort
    timeSort(treeSort, a, "Tree Sort");

    // Запуск Bead Sort
    timeSort(beadSort, a, "Bead Sort");

    return 0;
}

