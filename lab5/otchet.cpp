#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include "comb_sort.h"
#include "timsort.h"
#include "introsort.h"

using namespace std;

// Генерация случайного массива
vector<int> generateRandomArray(size_t size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Измерение времени выполнения функции
template <typename SortFunction>
double measureTime(SortFunction sortFunc, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    ofstream linePlotFile("line_plot_data.csv");
    ofstream boxPlotFile1("box_plot_data_1e4.csv");
    ofstream boxPlotFile2("box_plot_data_1e5.csv");

    linePlotFile << "ArraySize,CombSortTime,TimsortTime,IntrosortTime\n";
    boxPlotFile1 << "Algorithm,Run,Time\n";
    boxPlotFile2 << "Algorithm,Run,Time\n";

    // Линейный график: массивы от 1000 до 1e6 с шагом 1000
    for (size_t size = 1000; size <= 1000000; size += 1000) {
        vector<int> ar = generateRandomArray(size);

        double combTime = measureTime(combSort, ar);
        double timTime = measureTime(timSort, ar);
        double introTime = measureTime(introSort, ar);

        linePlotFile << size << "," << combTime << "," << timTime << "," << introTime << "\n";
    }

    // Box plot для массива 1e4 (50 запусков)
    for (int run = 1; run <= 50; ++run) {
        vector<int> ar = generateRandomArray(10000);
        boxPlotFile1 << "CombSort," << run << "," << measureTime(combSort, ar) << "\n";
        boxPlotFile1 << "Timsort," << run << "," << measureTime(timSort, ar) << "\n";
        boxPlotFile1 << "Introsort," << run << "," << measureTime(introSort, ar) << "\n";
    }

    // Box plot для массива 1e5 (50 запусков)
    for (int run = 1; run <= 50; ++run) {
        vector<int> ar = generateRandomArray(100000);

        boxPlotFile2 << "CombSort," << run << "," << measureTime(combSort, ar) << "\n";
        boxPlotFile2 << "Timsort," << run << "," << measureTime(timSort, ar) << "\n";
        boxPlotFile2 << "Introsort," << run << "," << measureTime(introSort, ar) << "\n";
    }

    linePlotFile.close();
    boxPlotFile1.close();
    boxPlotFile2.close();

    cout << "Data collection complete. Files saved.\n";
    return 0;
}

