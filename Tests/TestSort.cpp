#include "TestSort.h"

#include <vector>

template<typename Func>
void TestSort(Func sortFunction)
{
    std::vector<int> data;

    // Тест 1: Пустой массив
    data = {};
    sortFunction(data);
    CU_ASSERT(data.empty());

    // Тест 2: Уже отсортированный массив
    data = {1, 2, 3, 4, 5};
    sortFunction(data);
    CU_ASSERT(data == std::vector<int>({1, 2, 3, 4, 5}));

    // Тест 3: Обратно упорядоченный массив
    data = {5, 4, 3, 2, 1};
    sortFunction(data);
    CU_ASSERT(data == std::vector<int>({1, 2, 3, 4, 5}));

    // Тест 4: Массив с дублирующимися элементами
    data = {3, 1, 2, 1, 3};
    sortFunction(data);
    CU_ASSERT(data == std::vector<int>({1, 1, 2, 3, 3}));

    // Тест 5: Произвольный массив
    data = {8, -3, 7, 0, 2};
    sortFunction(data);
    CU_ASSERT(data == std::vector<int>({-3, 0, 2, 7, 8}));
}

void TestCocktailShakerSort()
{
    TestSort(Sort::CocktailShaker);
}

void TestHeapSort()
{
    TestSort(Sort::Heap);
}

void TestBucketSort()
{
    std::vector<int> data;

    // Тест 1: Пустой массив
    data = {};
    Sort::Bucket(data, 5);
    CU_ASSERT(data.empty());

    // Тест 2: Уже отсортированный массив
    data = {1, 2, 3, 4, 5};
    Sort::Bucket(data, 5);
    CU_ASSERT(data == std::vector<int>({1, 2, 3, 4, 5}));

    // Тест 3: Обратно упорядоченный массив
    data = {5, 4, 3, 2, 1};
    Sort::Bucket(data, 5);
    CU_ASSERT(data == std::vector<int>({1, 2, 3, 4, 5}));

    // Тест 4: Массив с дублирующимися элементами
    data = {3, 1, 2, 1, 3};
    Sort::Bucket(data, 5);
    CU_ASSERT(data == std::vector<int>({1, 1, 2, 3, 3}));

    // Тест 5: Произвольный массив
    data = {8, -3, 7, 0, 2};
    Sort::Bucket(data, 5);
    CU_ASSERT(data == std::vector<int>({-3, 0, 2, 7, 8}));
}