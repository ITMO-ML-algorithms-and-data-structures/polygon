#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> find_unique(std::vector<int>& elements, int size) {
    std::vector<int> unique_arr;

    // Определение максимального и минимального значений: O(n)
    int maxPositive = *std::max_element(elements.begin(), elements.end());
    int minNegative = *std::min_element(elements.begin(), elements.end());

    // Определение наибольшего абсолютного значения и создание вектора seen: O(maxAbs)
    int maxAbs = std::max(std::abs(maxPositive), std::abs(minNegative));
    std::vector<bool> seen(maxAbs * 2 + 1, false);

    // Основной цикл для проверки на уникальность: O(n)
    for (int num : elements) {
        if (!seen[num + maxAbs]) { 
            unique_arr.push_back(num); // Добавляем уникальный элемент в unique_arr
            seen[num + maxAbs] = true; // Отмечаем элемент как увиденный
        }
    }

    return unique_arr;
    // Итоговая сложность: O(n)
}

int main() {
    // Тест 1: Список с одним элементом
    std::vector<int> singleElementList = {1};
    std::vector<int> expectedSingleElementList = {1};
    std::vector<int> resultSingleElementList = find_unique(singleElementList, 1);
    assert(resultSingleElementList == expectedSingleElementList);

    // Тест 2: Список с повторяющимися элементами
    std::vector<int> duplicateList = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    std::vector<int> expectedDuplicateList = {1, 2, 3, 4};
    std::vector<int> resultDuplicateList = find_unique(duplicateList, 10);
    assert(resultDuplicateList == expectedDuplicateList);

    // Тест 3: Список с отрицательными элементами
    std::vector<int> negativeList = {-1, -2, -3, -3, -2, -1, 1, 2, 0};
    std::vector<int> expectedNegativeList = {-1, -2, -3, 1, 2, 0};
    std::vector<int> resultNegativeList = find_unique(negativeList, 10);
    assert(resultNegativeList == expectedNegativeList);

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}