#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "lab.c"  // Подключаем основной файл с функцией

// Тест для функции isAscendingSorted
void test_isAscendingSorted(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {1, 1, 2, 2, 3};
    int arr4[] = {1, 3, 2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    CU_ASSERT_TRUE(isAscendingSorted(arr1, 5)); // Массив отсортирован
    CU_ASSERT_FALSE(isAscendingSorted(arr2, 5)); // Массив не отсортирован
    CU_ASSERT_TRUE(isAscendingSorted(arr3, 5)); // Повторяющиеся значения, но по возрастанию
    CU_ASSERT_FALSE(isAscendingSorted(arr4, 5)); // Массив не отсортирован
}

// Главная функция для запуска тестов
int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("lab_test_suite", 0, 0);
    CU_add_test(suite, "test_isAscendingSorted", test_isAscendingSorted);

    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
