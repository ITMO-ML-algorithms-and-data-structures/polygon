#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tests.cpp"


void coctail(std::vector<int> &matrix) 
{
    int end = size(matrix);
    int start = 0;
    bool swapped_elements = true;
    int middle = 0;
    while (swapped_elements)
    {
        swapped_elements = false;
        for (int i=start; i<end; i++) {
            if (matrix[i] > matrix[i+1] && i+1<size(matrix))
            {
                middle = matrix[i];
                matrix[i] = matrix[i+1];
                matrix[i+1] = middle;
                
                swapped_elements = true;
            }
        }
        if (swapped_elements == false) 
        {
            break;
        }
        end = end - 1;
        for (int i=end; start<i; i--) 
        {
            if (matrix[i] < matrix[i-1]) 
            {
                middle = matrix[i];
                matrix[i] = matrix[i-1];
                matrix[i-1] = middle;
                swapped_elements = true;
            }
        }
        start = start + 1;
    }
}

void test_cocktail_best()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    coctail(src);
    check_results(src, expected, "Cocktail best case");
}

void test_cocktail_common()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::shuffle(src.begin(), src.end(), _tests_random);
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    coctail(src);
    check_results(src, expected, "Cocktail common case");
}

void test_cocktail_worst()
{
    std::vector<int> src = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    std::reverse(src.begin(), src.end());
    std::vector<int> expected = {1,2,3,4,6,8,9, 10, 12, 13,16,20, 100, 102, 150, 250, 251, 252, 1000, 1001, 1512, 1900, 2000, 2001, 2050, 2051, 2052, 2053, 2054, 2055, 4000, 4001, 4002, 4003, 4008, 5005, 5009, 6000};
    coctail(src);
    check_results(src, expected, "Cocktail worst case");
}

void test_cocktail_large_stat(int iterations = 50)
{
    std::cout << "[test_cocktail_large_stat] STARTED" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    for(int i = 0; i < iterations; i++) 
    {
        std::vector<int> src = get_data_for_sort();
        start = std::chrono::high_resolution_clock::now();
        coctail(src);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << std::to_string(duration.count()) << std::endl;
    }
    std::cout << "[test_cocktail_large_stat] ENDED" << std::endl;
}