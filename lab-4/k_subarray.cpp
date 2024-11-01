#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>

void read_csv(const std::string& filename, std::vector<int>& intArray) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ';')) { // Split by comma
            try {
                int number = std::stoi(value); // Convert to int
                intArray.push_back(number); // Add to the vector
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << value << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range: " << value << std::endl;
            }
        }
    }

    file.close();
}

void get_k_subarray(const int& K, int currentLevel, const int* array, std::set<std::set<int>>& subarrays, const int& N, std::set<int> indices) {
    // Рекурсия вызывается K раз
    if (currentLevel == K) {
        int summ = 0;

        for (const int& index : indices)
            summ += array[index]; // O(1) * K - взятие по индексу

        if (summ == 0 && subarrays.find(indices) == subarrays.end()) // O(log N) - поиск по значению
            subarrays.insert(indices);
        
        return;
    }

    for (int i = 0; i < N; i ++) {
        if (indices.find(i) == indices.end()) { // O(log K) * N - поиск по значению
            std::set<int> next_indices = indices; // (32 (заголовок) + 4 * k (int-ы)) * n байт
            next_indices.insert(i);
            get_k_subarray(K, currentLevel + 1, array, subarrays, N, next_indices); 
        }
    }

    // Итоговая сложность алгоритма:
    // для O(N * log K) рекурсия вызывается K раз, следовательно сложность - O((N log K)^K), что можно апроксимировать до O(N^K)
    
    // Суммарные затраты памяти:
    // (68 + 4 * k) * n + (32 + 4 * k) * n = (100 + 8 * k) * n байт
}

int test_passed = 0;
int test_failed = 0;

void assertEqual(std::set<std::set<int>> real_result, std::set<std::set<int>> expected_result, const int& k, const bool mode, const std::string& testName) {
    bool condition = true;

    if (mode) {
        condition = (real_result == expected_result);
    }

    else {
        for (const auto& inner_set : real_result) {
            if (inner_set.size() != k)
                condition = false;
        }
    }

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
    std::cout << "Tests not passed: " << test_failed << "\n";
}

void display_set(std::set<std::set<int>> target_set) {
     for (const auto& innerSet : target_set) {
        std::cout << "{ ";
        // Iterate over the inner set
        for (const auto& elem : innerSet) {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl; // Close the brace for the inner set
    }
}

void trivial_tests() {
    std::set<int> indices;
    std::set<std::set<int>> subarrays;
    // Память для каждого вложенного множества:
    // - Заголовок = 32 байта 
    // - k int-ов = 4 * k байт
    // Итого для одного вложенного множества = 32 + 4 * k байт

    // Память для n вложенных множеств = (32 + 4 * k) * n байт
    // Заголовки для n множеств во внешнем = 32 * n байт
    // Итого: 36 * n + (32 + 4 * k) * n = (68 + 4 * k) * n байт

    int arr1[4] = {1, -1, 2, -2};
    int k = 2;

    int N = sizeof(arr1) / sizeof(arr1[0]);

    get_k_subarray(k, 0, arr1, subarrays, N, indices);

    std::set<std::set<int>> expected_result_1;
    expected_result_1.insert({0, 1});
    expected_result_1.insert({2, 3});

    assertEqual(subarrays, expected_result_1, k, true, "Test: 1");
    subarrays.clear();

    int arr2[4] = {1, -1, 2, -3};
    k = 3;

    get_k_subarray(k, 0, arr2, subarrays, N, indices);

    std::set<std::set<int>> expected_result_2;
    expected_result_2.insert({0, 2, 3});

    assertEqual(subarrays, expected_result_2, k, true, "Test: 2");
    subarrays.clear();

    int arr3[4] = {1, 1, -1, -1};
    k = 2;

    get_k_subarray(k, 0, arr3, subarrays, N, indices);

    std::set<std::set<int>> expected_result_3;
    expected_result_3.insert({0, 2});
    expected_result_3.insert({0, 3});
    expected_result_3.insert({1, 2});
    expected_result_3.insert({1, 3});

    assertEqual(subarrays, expected_result_3, k, true, "Test: 3");
    subarrays.clear();
    
    report();
}

void big_test() {
    std::vector<int> numbers;
    read_csv("../numbers.csv", numbers);

    int arr[numbers.size()];

    for (int i = 0; i < numbers.size(); i ++)
        arr[i] = numbers[i];

    std::set<int> indices;
    std::set<std::set<int>> subarrays;

    int k = 6;

    int N = sizeof(arr) / sizeof(arr[0]);

    get_k_subarray(k, 0, arr, subarrays, N, indices);

    display_set(subarrays);

    std::set<std::set<int>> expected_result_4;

    //assertEqual(subarrays, expected_result_4, k, false, "Test: 4");
}

void test_time() {
    std::set<int> indices;
    std::set<std::set<int>> subarrays;

    for (int i = 6; i <= 25; i ++) {
        int arr[i];
        for (int j = 0; j < i; j ++) {
            if (j % 2 == 0)
                arr[j] = 1;
            else
                arr[j] = -1;
        }

        int k = 6;

        int N = sizeof(arr) / sizeof(arr[0]);

        auto start = std::chrono::high_resolution_clock::now();

        get_k_subarray(k, 0, arr, subarrays, N, indices);

        auto end = std::chrono::high_resolution_clock::now();

        // Calculate the duration
        std::chrono::duration<double> duration = end - start;

        std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl;
    }
}

int main() {    
    trivial_tests();

    //big_test();

    //test_time();

    return 0;
}