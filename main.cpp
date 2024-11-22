#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>
#include "lab4.cpp"

void runTests() {
    std::vector<double> arr = {99.5, -1.1, 101};
    int k = 2;
    std::vector<std::vector<double>> ans_ex1 = { {99.5, 101}, {-1.1} };
    std::vector<std::vector<double>> partition = generateAndFindBestPartition(arr, k);
    assert(partition == ans_ex1);
    std::cout << "Test {99.5, -1.1, 101} passed"<< std::endl;

    arr = {1, 10, 9, 2, 3, 8};
    k = 2;
    std::vector<std::vector<double>> ans_ex2 = { {1, 2, 3}, {10, 9, 8} };
    partition = generateAndFindBestPartition(arr, k);
    assert(partition == ans_ex2);
    std::cout << "Test {1, 10, 9, 2, 3, 8} passed"<< std::endl;

    arr = {1, 2, 3, 4, 5, 6};
    k = 2;
    std::vector<std::vector<double>> ans_ex3 = { {1, 2, 3}, {4, 5, 6} };
    partition = generateAndFindBestPartition(arr, k);
    assert(partition == ans_ex3);
    std::cout << "Test {1, 10, 9, 2, 3, 8} passed"<< std::endl;

    arr = {1, 2, 3, 4, 5, 6, 7};
    k = 7;
    std::vector<std::vector<double>> ans_1 = { {1}, {2}, {3}, {4}, {5}, {6}, {7} };
    partition = generateAndFindBestPartition(arr, k);
    assert(partition == ans_1);
    std::cout << "Test {1, 2, 3, 4, 5, 6, 7} passed"<< std::endl;

    arr = {99.5, -1.1, 101, 1, 10, 9, 2, 3, 8, 12};
    k = 7;
    std::vector<std::vector<double>> ans_2 = { {99.5}, {-1.1}, {101}, {1, 2, 3}, {10}, {9, 8}, {12} };
    partition = generateAndFindBestPartition(arr, k);
    assert(partition == ans_2);
    std::cout << "Test {99.5, -1.1, 101, 1, 10, 9, 2, 3, 8, 12} passed"<< std::endl;
}

int main() {
    runTests();
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::vector<double> arr = {99.5, -1.1, 101};
    int numSubsets = 2;

    auto t1 = high_resolution_clock::now();
    std::vector<std::vector<double>> partition = generateAndFindBestPartition(arr, numSubsets);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;

    for (const auto& subset : partition) {
        std::cout << "[";
        bool first = true;
        for (const double& val : subset) {
            if (first) {
                first = false;
            } else {
                std::cout << ", ";    
            }
            std::cout << val;
        }
        std::cout << "] ";
    }
    std::cout << "#" << arr.size() << " - ";
    std::cout << ms_double.count() << "ms";
    return 0;
}

