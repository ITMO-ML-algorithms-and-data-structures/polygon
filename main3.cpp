#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// функция поиска уникальных элементов
// O(N); N - размер вектора
std::vector<int> find_unique(std::vector<int>& elements, int size) {
    std::vector<int> unique_arr;
    int maxPositive = *std::max_element(elements.begin(), elements.end()); // максимальное положительное число - 4 байта
    int minNegative = *std::min_element(elements.begin(), elements.end()); // минимальное отрицательное число - 4 байта
    int maxAbs = std::max(std::abs(maxPositive), std::abs(minNegative)); // максимальное значение модуля - 4 байта
    std::vector<bool> seen(maxAbs * 2 + 1, false); // вектор seen для отслеживания встречавшихся эл-тов - 4 байта

    for (int num : elements) {
        // проверка, встречался ли такой эл-т ранее
        if (!seen[num + maxAbs]) { 
            unique_arr.push_back(num); // добавление в unique_arr
            seen[num + maxAbs] = true; 
        }
    }

    return unique_arr;
}

int main() {
    // тест 1: список с одним эл-том (каждый вектор:  8 + 4*n  байт, где n - кол-во эл-тов в векторе)
    std::vector<int> singleElementList = {1};
    std::vector<int> expectedSingleElementList = {1};
    std::vector<int> resultSingleElementList = find_unique(singleElementList, 1);
    assert(resultSingleElementList == expectedSingleElementList);

    // тест 2: список с повторяющимися эл-тами
    std::vector<int> duplicateList = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    std::vector<int> expectedDuplicateList = {1, 2, 3, 4};
    std::vector<int> resultDuplicateList = find_unique(duplicateList, 10);
    assert(resultDuplicateList == expectedDuplicateList);

    // тест 3: список с отрицательными эл-тами
    std::vector<int> negativeList = {-1, -2, -3, -3, -2, -1};
    std::vector<int> expectedNegativeList = {-1, -2, -3};
    std::vector<int> resultNegativeList = find_unique(negativeList, 6);
    assert(resultNegativeList == expectedNegativeList);

    std::cout << "Тесты успешно пройдены" << std::endl;
    return 0;
}
