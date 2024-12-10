#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <cassert>
#include <algorithm>

// Удалить дублирующиеся значения из входного массива

std::vector<int> removeDuplicates(const std::vector<int>& arr) { // O(N) для выделения памяти
    std::unordered_set<int> uniqueSet; // O(1) для выделение памяти
    std::vector<int> result; // O(1) для выделение памяти

    for (int num : arr) {
        // O(N) - итерация по каждому элементу массива
        if (uniqueSet.insert(num).second) { // O(1) в среднем для добавления элемента в множество
            result.push_back(num); // O(1) - добавление элемента в конец вектора
        }
    }
    
    return result;
}

void testRemoveDuplicates() {
    // Тест 1: Пустой массив
    std::vector<int> arr1 = {};
    std::vector<int> expected1 = {};
    assert(removeDuplicates(arr1) == expected1);

    // Тест 2: Массив без дубликатов
    std::vector<int> arr2 = {10, 28, 39, 47, 51};
    std::vector<int> expected2 = {10, 28, 39, 47, 51};
    assert(removeDuplicates(arr2) == expected2);

    // Тест 3: Массив с дубликатами
    std::vector<int> arr3 = {1, 2, 2, 3, 3, 4};
    std::vector<int> expected3 = {1, 2, 3, 4};
    assert(removeDuplicates(arr3) == expected3);

    // Тест 4: Все элементы одинаковые
    std::vector<int> arr4 = {1, 1, 1, 1};
    std::vector<int> expected4 = {1};
    assert(removeDuplicates(arr4) == expected4);
    
    // Тест 5: Смешанные элементы
    std::vector<int> arr5 = {1, 2, 2, 3, 1, 5, 3, 7};
    std::vector<int> expected5 = {1, 2, 3, 5, 7};
    auto result5 = removeDuplicates(arr5);
    for (int num : expected5) {
        assert(std::find(result5.begin(), result5.end(), num) != result5.end());
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testRemoveDuplicates();

    std::ifstream inputFile("numbers.txt"); 
    
    int size;
    inputFile >> size;

    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        inputFile >> arr[i];
    }
    
    inputFile.close(); 

    std::vector<int> res = removeDuplicates(arr); // O(K), где K - количество уникальных элементов

    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i]; // O(K) - вывод K уникальных элементов
        if (i < res.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
// Сложность алгоритма составляет:
// В лучшем случае(все элементы уникальные) - O(N)
// В худшем случае(все элементы повторяются) - O(N+K)
