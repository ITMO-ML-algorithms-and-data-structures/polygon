#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Функция для нахождения уникальных элементов в списке
std::vector<int> find_unique(std::vector<int>& elements, int size) {
    std::vector<int> unique_arr; // Используется для хранения уникальных значений
    int maxPositive = *std::max_element(elements.begin(), elements.end()); // Память под maxPositive: 4 байта
    int minNegative = *std::min_element(elements.begin(), elements.end()); // Память под minNegative: 4 байта
    int maxAbs = std::max(std::abs(maxPositive), std::abs(minNegative)); // Память под maxAbs: 4 байта

    // Создаем вектор флагов для отслеживания уникальности (каждому значению нужен флаг)
    std::vector<bool> seen(maxAbs * 2 + 1, false); // Память под seen: (maxAbs * 2 + 1) байт

    // Цикл для проверки уникальности каждого элемента
    for (int num : elements) { // Память под num: 4 байта
        if (!seen[num + maxAbs]) { // Используем смещение num + maxAbs, чтобы покрыть диапазон отрицательных значений
            unique_arr.push_back(num); // Добавляем уникальный элемент в unique_arr
            seen[num + maxAbs] = true; // Помечаем элемент как встречавшийся
        }
    }

    // Возвращаем вектор с уникальными значениями
    return unique_arr; // Память под unique_arr зависит от количества уникальных значений
}

int main() {
    // Тест 1: Список с одним элементом
    std::vector<int> singleElementList = {1}; // Память под singleElementList: 4 * 1 байт
    std::vector<int> expectedSingleElementList = {1}; // Память под expectedSingleElementList: 4 * 1 байт
    std::vector<int> resultSingleElementList = find_unique(singleElementList, 1); // Результат вызова функции
    assert(resultSingleElementList == expectedSingleElementList);

    // Тест 2: Список с повторяющимися элементами
    std::vector<int> duplicateList = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4}; // Память под duplicateList: 4 * 10 байт
    std::vector<int> expectedDuplicateList = {1, 2, 3, 4}; // Память под expectedDuplicateList: 4 * 4 байта
    std::vector<int> resultDuplicateList = find_unique(duplicateList, 10);
    assert(resultDuplicateList == expectedDuplicateList);

    // Тест 3: Список с отрицательными элементами
    std::vector<int> negativeList = {-1, -2, -3, -3, -2, -1, 1, 2, 0}; // Память под negativeList: 4 * 9 байт
    std::vector<int> expectedNegativeList = {-1, -2, -3, 1, 2, 0}; // Память под expectedNegativeList: 4 * 6 байт
    std::vector<int> resultNegativeList = find_unique(negativeList, 10);
    assert(resultNegativeList == expectedNegativeList);

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
