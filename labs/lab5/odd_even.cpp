#include <iostream>
#include <vector>

// Функция выполнения этапа сортировки по чётности индекса
bool sort_step(std::vector<int>& array, bool is_odd, bool is_sorted) {
    int size = array.size(); // O(1), +4 байта
    // Определяем начальный индекс в зависимости от четности шага (odd нечёт, even чёт)
    int start = is_odd ? 1 : 0; // O(1), +4 байта

    // Проходим по всем элементам массива с шагом 2
    for (int i = start; i < size - 1; i += 2) { // O(N/2), +4 байта
        // Если текущий элемент больше следующего, меняем их местами
        if (array[i] > array[i + 1]) { // O(1)
            std::swap(array[i], array[i + 1]); // O(1)
            is_sorted = false; // O(1)
        }
    }
    return is_sorted; // O(1)
}

// Основная функция сортировки
void odd_even_sort(std::vector<int>& array) {  // вектор array: 24 + 4*N байт, где N - колво элементов в векторе
    bool sorted = false; // Флаг того, отсортирован ли массив. O(1), +1 байт

    while (!sorted) { // O(M), M - число проходов, в среднем случае можно считать за O(N)
        sorted = true; // Полагаем, что массив отсортирован, если это правда, то sorted не изменится. O(1)

        // Выполняем шаги сортировки по четным индексам и нечетным
        sorted = sort_step(array, false, sorted); // O(N/2)
        sorted = sort_step(array, true, sorted); // O(N/2)
    }
}
// итог по временной сложности odd-even: O(N^2)
// O(1) дополнительной памяти, сортировка выполняется на месте
