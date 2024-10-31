#include <iostream>
#include <vector>
#include <set>

std::set<std::set<int>> subarrays;

void get_k_subarray(const int& K, int currentLevel, const int* array, const int& N, std::set<int> indices) {
    if (currentLevel == K) {
        int summ = 0;

        for (const int& index : indices)
            summ += array[index];

        if (summ == 0 && subarrays.find(indices) == subarrays.end())
            subarrays.insert(indices);
        
        return;
    }

    for (int i = 0; i < N; i ++) {
        if (indices.find(i) == indices.end()) {
            std::set<int> next_indices = indices;
            next_indices.insert(i);
            get_k_subarray(K, currentLevel + 1, array, N, next_indices); 
        }
    }
    
}

int test_passed = 0;
int test_failed = 0;

void assertEqual(std::set<std::set<int>> real_result, std::set<std::set<int>> expected_result, const int& k, const bool mode, const std::string& testName) {
    bool condition = true; // O(1) - присваивание

    if (mode) {
        condition = (real_result == expected_result);
    }

    else {
        for (const auto& inner_set : real_result) {
            if (inner_set.size() != k)
                condition = false;
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
    std::cout << "Tests not passed: " << test_failed << "\n";
}

int main() {
    std::set<int> indices;

    int arr1[4] = {1, -1, 2, -2};
    int k = 2;

    int N = sizeof(arr1) / sizeof(arr1[0]);

    get_k_subarray(k, 0, arr1, N, indices);

    std::set<std::set<int>> expected_result_1;
    expected_result_1.insert({0, 1});
    expected_result_1.insert({2, 3});

    assertEqual(subarrays, expected_result_1, k, true, "Test: 1");
    subarrays.clear();

    int arr2[4] = {1, -1, 2, -3};
    k = 3;

    get_k_subarray(k, 0, arr2, N, indices);

    std::set<std::set<int>> expected_result_2;
    expected_result_2.insert({0, 2, 3});

    assertEqual(subarrays, expected_result_2, k, true, "Test: 2");
    subarrays.clear();

    int arr3[4] = {1, 1, -1, -1};
    k = 2;

    get_k_subarray(k, 0, arr3, N, indices);

    std::set<std::set<int>> expected_result_3;
    expected_result_3.insert({0, 2});
    expected_result_3.insert({0, 3});
    expected_result_3.insert({1, 2});
    expected_result_3.insert({1, 3});

    assertEqual(subarrays, expected_result_3, k, true, "Test: 3");
    subarrays.clear();
    
    report();

    return 0;
}