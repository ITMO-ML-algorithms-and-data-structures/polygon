#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Функция для получения уникальных элементов из вектора
// Временная сложность: O(n), где n — количество элементов
// Потребление памяти:
// - Вектор исходных данных: 4 * size байт
// - Массив `seen`: 4 * maxValue байт
// - Результирующий вектор: 4 * uniqueCount байт (где uniqueCount — количество уникальных элементов)
std::vector<int> find_unique(std::vector<int>& elements, int size) {
    std::vector<int> unique_arr;
    int maxValue = *std::max_element(elements.begin(), elements.end());    // Максимальное значение в массиве (4 байта)
    std::vector<bool> seen(maxValue + 1, false);                          // Массив `seen` для проверки уникальности (4 байта на элемент)

    for (int num : elements) {
        // Проверяем, был ли этот элемент уже обработан
        if (!seen[num]) { 
            unique_arr.push_back(num);       // Добавляем в результат
            seen[num] = true;                // Отмечаем элемент как обработанный
        }
    }

    return unique_arr;
}

int main() {
    // Тест 1: Уникальные положительные числа
    // Память: вектор исходных данных (4 * 7 байт), массив `seen` (4 * 11 байт), результирующий вектор (4 * 4 байт)
    std::vector<int> positiveList = {8, 6, 8, 10, 6, 7, 10};
    std::vector<int> expectedPositiveList = {8, 6, 10, 7};
    std::vector<int> resultPositiveList = find_unique(positiveList, 7);
    assert(resultPositiveList == expectedPositiveList);

    // Тест 2: Последовательные числа
    // Память: вектор исходных данных (4 * 5 байт), массив `seen` (4 * 6 байт), результирующий вектор (4 * 5 байт)
    std::vector<int> sequentialList = {1, 2, 3, 4, 5};
    std::vector<int> expectedSequentialList = {1, 2, 3, 4, 5};
    std::vector<int> resultSequentialList = find_unique(sequentialList, 5);
    assert(resultSequentialList == expectedSequentialList);

    // Тест 3: Повторяющиеся числа
    // Память: вектор исходных данных (4 * 8 байт), массив `seen` (4 * 6 байт), результирующий вектор (4 * 3 байт)
    std::vector<int> repeatedList = {3, 3, 3, 4, 4, 4, 5, 5};
    std::vector<int> expectedRepeatedList = {3, 4, 5};
    std::vector<int> resultRepeatedList = find_unique(repeatedList, 8);
    assert(resultRepeatedList == expectedRepeatedList);

    std::cout << "Все тесты успешно пройдены!" << std::endl;
    return 0;
}
