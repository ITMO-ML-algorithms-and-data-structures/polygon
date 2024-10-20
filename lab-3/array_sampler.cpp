#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <vector>
#include <algorithm> // For std::shuffle
#include <chrono>
#include <cassert>
#include <string>

//TODO: optimisation and pr

std::vector<int> get_array_sample(int* array_to_sample, const int& array_size, const int& sample_size) {
    // Сэмплирование массива
    std::vector<int> sample(sample_size); // O(K) для выделения памяти (в худшем случае О(N))
    std::vector<int> available_index(array_size); // О(N) для выделения памяти

    for (int i = 0; i < array_size; i ++) {
        available_index[i] = i; // О(1) * N - присваивание по индексу
    }

    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); // O(1) - взятие текущего времени
    std::srand(static_cast<unsigned>(seed)); // О(1) - передача seed в генератор
    std::random_shuffle(available_index.begin(), available_index.end()); // О(N) - перемешивание значений в векторе

    for (int i = 0; i < sample_size; i ++) {
        int random_index = i; // О(1) * K - присваивание
        sample[i] = array_to_sample[available_index[random_index]]; // (О(1) + O(1) + O(1)) * K - два взятия по индексу и одно присваивание
        // в худшем случае * N
    }

    // Сложность алгоритма составляет:
    // О(N) в любом случае

    return sample;
}

int test_passed = 0;
int test_failed = 0;

void assertEqual(int* array, const int& array_size, std::vector<int>& sample, const int& required_size, const std::string& testName) {
    bool condition = true; // O(1) - присваивание

    // Checking size of sample
    if (sample.size() != required_size) { // O(1) - сравнение
        condition = false; // O(1) - присваивание
        std::cout << "Wrong sample size\n"; 
    }

    // Cheking if all elements of sample are in source array
    for (int i = 0; i < sample.size(); i ++) {
        int tmp_element = sample[i]; // (O(1) + O(1)) * K - присваивание и взятие по индексу
        int sample_count = 0; // O(1) * K - присваивание
        int array_count = 0; // O(1) * K - присваивание


        for (int j = 0; j < sample.size(); j ++) {
            if (sample[j] == tmp_element) // (O(1) + O(1)) * K * K - взятие по индексу и сравнение
                sample_count ++; // (O(1) + O(1)) * K * K - взятие значения и присваивание 
        }

        for (int k = 0; k < array_size; k ++) {
            if (array[k] == tmp_element) // (O(1) + O(1)) * K * N - взятие по индексу и сравнение
                array_count ++; // (O(1) + O(1)) * K * N - взятие значения и присваивание 
        }

        if (sample_count > array_count) { // O(1) * K - сравнение
            condition = false; // O(1) * K - присваивание
            std::cout << "Wrong number of element containing\n"; 
            break;
        }
    }

    // Сложность тестов составляет:
    // O(N^2) - в худшем случае
    // O(N * K) - в среднем случае, где K равномерно распределено от 1 до N
    // O(N) - в лучшем случае, когда K = 1

    if (condition) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTests passed: " << test_passed << "\n";
    std::cout << "\nTests not passed: " << test_failed << "\n";
}

int main() {
    int arr[10000];

    for (int i = 0; i < 10000; i ++) {
        arr[i] = i;
    }

    int arr_len = sizeof(arr) / sizeof(arr[0]);

    for (int k = 1; k <= 10; k ++) {
        std::vector<int> res_sample = get_array_sample(arr, 10000, k);

        assertEqual(arr, arr_len, res_sample, k, "Test: " + std::to_string(k));

        for (auto i : res_sample)
            std::cout << i << ' ';

        std::cout << '\n';
    }

    report();

    return 0;
}