#include <iostream>
#include <vector>

/* Функция переворота массива от начала до заданного индекса */
void flip(std::vector<int>& array, int reverse_ind) {
    int left_ind = 0; // O(1), +4 байта
    // Меняем крайние элементы, затем изменяем индексы, чтобы поменять следующую пару
    while (left_ind < reverse_ind) {
        std::swap(array[left_ind], array[reverse_ind]); // O(1)
        left_ind++; // O(1)
        reverse_ind--; // O(1)
    }
    // цикл while выполнится reverse_ind/2 раз, можно считать, что сложность цикла - O(N)
}

/* Функция нахождения индекса максимального элемента в массиве */
int find_max_index(const std::vector<int>& arr, int n) {
    int max_index = 0; // O(1), +4 байта
    for (int i = 1; i < n; i++) { // цикл имеет сложность O(N), +4 байта для i
        if (arr[i] > arr[max_index]) { // O(1)
            max_index = i; // O(1)
        }
    }
    return max_index; // O(1)
}

/* Основная функция сортировки */
void pancake_sort(std::vector<int>& array) { // вектор array: 24 + 4*N байт, где N - колво элементов в векторе
    int size = array.size(); // O(1), +4 байта

    // Проходим по всем элементам массива, N раз
    while (size > 1) {
        // Находим индекс макс элемента в неотсортированной части
        int max_index = find_max_index(array, size); // O(N), +4 байта

        // Если макс элемент не на своем месте, то переворачиваем
        if (max_index != size - 1) { // O(1)
            // Если макс элемент не первый, переворачиваем до него
            if (max_index != 0) {
                flip(array, max_index); // O(N)
            }
            // Переворачиваем весь текущий массив
            flip(array, size - 1); // O(N)
        }
        size -= 1; // O(1)
    }
    // сложность цикла while - O(N^2)
}
// итог по временной сложности pancake: O(N^2)
// O(1) дополнительной памяти, сортировка выполняется на месте
