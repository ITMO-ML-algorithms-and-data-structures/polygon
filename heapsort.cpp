#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "tests.cpp"

#ifndef LAB_HEAPSORT_H
#define LAB_HEAPSORT_H

void heap_sort(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heap_sort(arr, n, largest);
    }
}

std::vector<int> heap_sort_array(std::vector<int> arr) {
    int n = size(arr);

    for (int i = n / 2 - 1; i >= 0; i--)
        heap_sort(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        heap_sort(arr, i, 0);
    }

    return arr;
}

void test_heap_best()
{
    std::vector<int> src = {6000,5009,4000,5005,2000,2052,2055,4008,1000,1512,1900,2050,2051,2054,150,4002,4003,252,12,1001,13,6,16,2001,20,8,100,2053,102,9,3,4001,250,10,251,4,2,1};
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    src = heap_sort_array(src);
    check_results(src, expected, "Heap best case");
}

void test_heap_common()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::shuffle(src.begin(), src.end(), _tests_random);
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    src = heap_sort_array(src);
    check_results(src, expected, "Heap common case");
}

void test_heap_worst()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    src = heap_sort_array(src);
    check_results(src, expected, "Heap worst case");
}

void test_heap_large_stat(int iterations = 50)
{
    std::cout << "[test_heap_large_stat] STARTED" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    for(int i = 0; i < iterations; i++) 
    {
        std::vector<int> src = get_data_for_sort();
        start = std::chrono::high_resolution_clock::now();
        heap_sort_array(src);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << std::to_string(duration.count()) << std::endl;
    }
    std::cout << "[test_heap_large_stat] ENDED" << std::endl;
}

#endif