#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/bucket_sort.cpp"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_bucket_sort_best_case() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bucketSort(arr);
    CU_ASSERT_EQUAL(memcmp(arr.data(), expected.data(), expected.size() * sizeof(int)), 0);
}

void test_bucket_sort_average_case() {
    std::vector<int> arr = {7, 3, 5, 8, 10, 2, 4, 9, 6, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bucketSort(arr);
    CU_ASSERT_EQUAL(memcmp(arr.data(), expected.data(), expected.size() * sizeof(int)), 0);
}

void test_bucket_sort_worst_case() {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bucketSort(arr);
    CU_ASSERT_EQUAL(memcmp(arr.data(), expected.data(), expected.size() * sizeof(int)), 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite pSuite = CU_add_suite("Bucket Sort Tests", init_suite, clean_suite);

    CU_add_test(pSuite, "Best Case", test_bucket_sort_best_case);
    CU_add_test(pSuite, "Average Case", test_bucket_sort_average_case);
    CU_add_test(pSuite, "Worst Case", test_bucket_sort_worst_case);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
