#include <iostream>
#include <vector>

#include "Tests/TestSort.h"

void PrintVector(const std::vector<int>& vector)
{
    for (int value : vector)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

int main()
{
#ifndef NDEBUG
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = CU_add_suite("Sorting_Test_Suite", 0, 0);
    if (!pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (!CU_add_test(pSuite, "Test CocktailShaker Sort", TestCocktailShakerSort) ||
        !CU_add_test(pSuite, "Test Heap Sort", TestHeapSort) ||
        !CU_add_test(pSuite, "Test Bucket Sort", TestBucketSort)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
#endif
    std::cout << "Release MOD..." << std::endl;
}