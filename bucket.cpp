#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>

#include "heapsort.cpp"
#include "tests.cpp"


void bucket_sort(std::vector<int> &arr, int fixed_length = 0) 
{
    std::vector<std::vector<int>> baskets = {};
    int length = size(arr);
    int min = INT_MAX;
    int max = INT_MIN;
    int k = fixed_length > 1 ? fixed_length : pow(length, 0.5);
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            continue;
        }
        if(arr[i] < min)
        {
            min = arr[i];
            continue;
        }
        if (counter < k)
        {
            counter += 1;
            baskets.push_back({});          
        }
    }

    int metrics = max - min;
    if (k >= metrics || metrics == 0 || metrics == 1)
    {
        baskets = {};
    } 

    for (int i = 0; i < length; i++)
    {
        if (size(baskets) != 0)
        {
            int position = arr[i] / metrics;
            baskets[position].push_back(arr[i]);
        }
        else
        {
            baskets.push_back(arr);
            break;
        }
    }

    int size_buckets = size(baskets);
    for (int i = 0; i < size_buckets; i++)
    {
        if (size(baskets[i]) > 1)
        {
            baskets[i] = heap_sort_array(baskets[i]);
        }
    }
    for (int i =0; i < size(baskets); i++)
    {
        if (size(baskets[i]) == 0)
        {
            baskets.erase(baskets.begin() + i);
        }
    }
    arr.clear();
    for (int i =0; i < size(baskets); i++)
    {
        if (size(baskets[i]) == 0)
        {
            baskets.erase(baskets.begin() + i);
            continue;
        }
        for (int j=0; j < size(baskets[i]); j++)
        {
            arr.push_back(baskets[i][j]);
        }
    }
}

void test_bucket_best()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::shuffle(src.begin(), src.end(), _tests_random);
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    bucket_sort(src, size(src)); // Uses bucket size 1
    check_results(src, expected, "Bucket best case");
}

void test_bucket_common()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::shuffle(src.begin(), src.end(), _tests_random);
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    bucket_sort(src, 0); // 0 - switches to dynamic bucket size calculation
    check_results(src, expected, "Bucket common case");
}

void test_bucket_worst()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::shuffle(src.begin(), src.end(), _tests_random);
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    bucket_sort(src, 2); // Worst nontrivial case, 1 - would be reduced to underlying sort complexity
    check_results(src, expected, "Bucket worst case");
}

void test_bucket_large_stat(int iterations = 50)
{
    std::cout << "[test_bucket_large_stat] STARTED" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    for(int i = 0; i < iterations; i++) 
    {
        std::vector<int> src = get_data_for_sort();
        start = std::chrono::high_resolution_clock::now();
        bucket_sort(src);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << std::to_string(duration.count()) << std::endl;
    }
    std::cout << "[test_bucket_large_stat] ENDED" << std::endl;
}