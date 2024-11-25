#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "sort_algs.cpp"

void benchmark1(void (*sortFunc)(std::vector<int>&), const std::string& sortName, int maxSize, int step,
                std::ofstream& outFile) {
    // генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int size = 1000; size <= maxSize; size += step) {
        // создание массива случайных чисел
        std::vector<int> arr(size);
        for (int& x : arr) {
            x = dis(gen);
        }

        // замер времени
        auto start = std::chrono::high_resolution_clock::now();
        sortFunc(arr);
        auto end = std::chrono::high_resolution_clock::now();

        // вычисление времени и запись в файл
        std::chrono::duration<double> duration = end - start;
        outFile << sortName << "," << size << "," << duration.count() << "\n";
        std::cout << sortName << " - Size: " << size << " - Time: " << duration.count() << "s\n";
    }
}

void benchmark2(void (*sortFunc)(std::vector<int>&), const std::string& sortName, int size, int repetitions,
                std::ofstream& outFile) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < repetitions; ++i) {
        std::vector<int> arr(size);
        for (int& x : arr) {
            x = dis(gen);
        }

        auto start = std::chrono::high_resolution_clock::now();
        sortFunc(arr);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        outFile << sortName << "," << size << "," << duration.count() << "\n";
        std::cout << sortName << " - Size: " << size << " - Time: " << duration.count() << "s\n";
    }
}

int main() {
    int maxSize = 1000000;
    int step = 1000;

    std::ofstream outFile("benchmark1.csv");
    outFile << "Algorithm,Size,Time\n";

    benchmark1(combSort, "Comb Sort", maxSize, step, outFile);
    // криптография да да)
    benchmark1([](std::vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort", maxSize, step,
               outFile);
    benchmark1(timSort, "Tim Sort", maxSize, step, outFile);

    outFile.close();

    int repetitions = 50;
    std::vector<int> sizes = {10000, 100000};

    std::ofstream outFile("benchmark2.csv");
    outFile << "Algorithm,Size,Time\n";

    for (int size : sizes) {
        benchmark2(combSort, "Comb Sort", size, repetitions, outFile);
        benchmark2([](std::vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort", size,
                   repetitions, outFile);
        benchmark2(timSort, "Tim Sort", size, repetitions, outFile);
    }

    outFile.close();
}