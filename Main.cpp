#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

#include "Tests/Test.h"

#include "CUnit/Basic.h"

#include "Utils/Timer.h"

#include "SamplingArray.h"

static size_t AllocateMemory;

void* operator new(size_t size) {
    AllocateMemory += size;
    return malloc(size);
}

int main()
{
    LOG("MainTest Array Sampling...");
    Timer timer;
    std::vector<int> mainTestArray = SamplingArray(R"(your/path/to/file.txt)", 3);
    for (int value : mainTestArray) {
       std::cout << value << " ";
    }
    std::cout << std::endl;
    LOG("Sampling array...");
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    CU_pSuite pSuite = nullptr;
    pSuite = CU_add_suite("SamplingArray",  nullptr, nullptr);
    if (pSuite == nullptr)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite, "Test of ArraySize()", TestArraySize) == nullptr ||
        CU_add_test(pSuite, "Test of UniqueValue()", TestUniqueValue) == nullptr ||
        CU_add_test(pSuite, "Test of InvalidPath()", TestInvalidPath) == nullptr)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    std::cout << AllocateMemory << " Bytes Allocated in HEAP in run time of program" << std::endl;
    return CU_get_error();
}
