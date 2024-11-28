#include <iostream>
#include <vector>
#include <algorithm>

void pigeonhole_sort(std::vector<int>& array) { // вектор array: 24 + 4*N байт, где N - колво элементов в векторе
    int n = array.size(); // O(1), +4 байта

    // Находим минимальное и максимальное значения
    int min_elem = *std::min_element(array.begin(), array.end()); // O(N), поиск минимального, +4 байта
    int max_elem = *std::max_element(array.begin(), array.end()); // O(N), поиск максимального, +4 байта

    // Получаем диапазон значений, создаём соответствующий вектор с ячейками
    int size = max_elem - min_elem + 1; // O(1), +4 байта
    std::vector<std::vector<int>> holes(size); // O(size), +24 + 24*size байт, создаём вектор размера size

    // Проходимся по исходному массиву, размещаем элементы в ячейки согласно их значениям
    for (int i = 0; i < n; i++) { // цикл: O(N), +4 байт для счётчика
        holes[array[i] - min_elem].push_back(array[i]); // O(1), +4 байт для вектора holes
    }

    // Собираем исходный массив, но уже в отсортированном виде
    int index = 0; // O(1), +4 байт
    for (int i = 0; i < size; i++) { // цикл: O(size), +4 байта на счётчик
        for (int j = 0; j < holes[i].size(); j++) { // цикл: O(K), K - размер ячейки, +4 байта на счётчик
            array[index] = holes[i][j]; // O(1)
            index++; // O(1)
        }
    }
}
// итог по временной сложности pigeonhole: O(N + size)
// O(size) дополнительной памяти за счёт создания доп. вектора с ячейками под элементы