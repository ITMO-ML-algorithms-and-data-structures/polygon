#include <iostream>
#include <vector>

#include "Lab_1/CountVectorizer.h"
#include "Lab_1/TestCV.h"

#define LOG(x) std::cout << x << "\n"

template<typename T>
void PrintMatrix(std::vector<std::vector<T>> matrix)
{
    for (std::vector<int>& row : matrix)
    {
        for (int element : row)
        {
            std::cout << element << " ";
        }
        LOG("");
    }
}

int main()
{
    LOG("CountVectorizer Algorithm:");
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("CountVectorizer", NULL, NULL);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((CU_add_test(pSuite, "Test of SplittingWords()", TestSplittingWords) == NULL) ||
        (CU_add_test(pSuite, "Test of BuildUnique()", TestBuildUnique) == NULL) ||
        (CU_add_test(pSuite, "Test of BuildCountMatrix()", TestBuildCountMatrix) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}