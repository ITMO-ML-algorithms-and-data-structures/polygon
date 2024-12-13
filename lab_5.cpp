#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long
using namespace std;


// Comb Sort
void comb_sort(vector<ll> &arr) { // arr - O(n)
    int n = arr.size(); // n - 4 байта
    double shrink_factor = 1.3; // shrink_factor - 8 байт
    int gap = n; // gap - 4 байта
    bool sorted = false; // sorted - 1 байт

    while (!sorted) { // O(n^2) в худшем случае
        gap = floor(gap / shrink_factor); // floor - O(1)
        if (gap <= 1) { 
            gap = 1; 
            sorted = true; 
        }
        for (int i = 0; i + gap < n; i++) { // i - 4 байта, O(n)
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]); // swap - O(1)
                sorted = false;
            }
        }
    }
} // Итого: память O(n), сложность O(n^2) в худшем случае

// Binary Insertion Sort
void binary_insertion_sort(vector<ll> &arr) { // arr - O(n)
    int n = arr.size(); // n - 4 байта
    for (int i = 1; i < n; i++) { // i - 4 байта, O(n)
        ll key = arr[i]; // key - 8 байт
        int left = 0, right = i - 1; // left, right - 8 байт
        while (left <= right) { // O(log n) для поиска позиции
            int mid = left + (right - left) / 2; // mid - 4 байта
            if (arr[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--) { // j - 4 байта, O(n) в худшем случае
            arr[j + 1] = arr[j]; // копирование - O(1)
        }
        arr[left] = key;
    }
} // Итого: память O(n), сложность O(n^2) в худшем случае

// Flash Sort
void flash_sort(vector<ll> &arr) { // arr - O(n)
    int n = arr.size(); // n - 4 байта
    if (n <= 1) return;

    int m = int(0.45 * n); // m - 4 байта, количество классов
    vector<int> count(m, 0); // count - O(m)

    ll min_el = arr[0], max_el = arr[0]; // min_el, max_el - 8 байт
    int max_idx = 0; // max_idx - 4 байта

    // Найти минимум и максимум - O(n)
    for (int i = 1; i < n; i++) { // i - 4 байта
        if (arr[i] < min_el) min_el = arr[i]; // Поиск минимального значения
        if (arr[i] > max_el) { // Поиск максимального значения
            max_el = arr[i];
            max_idx = i;
        }
    }

    if (min_el == max_el) return; // Массив уже отсортирован

    // Классификация - O(n)
    double scale = double(m - 1) / (max_el - min_el); // scale - 8 байт
    for (int i = 0; i < n; i++) { // i - 4 байта
        int idx = int((arr[i] - min_el) * scale); // idx - 4 байта, вычисление класса
        if (idx >= m) idx = m - 1; // Защита от выхода за границы
        count[idx]++;
    }

    // Префиксная сумма - O(m)
    for (int i = 1; i < m; i++) count[i] += count[i - 1];

    // Перемещение элементов - O(n)
    vector<ll> temp(n); // temp - O(n)
    for (int i = n - 1; i >= 0; i--) { // i - 4 байта
        int idx = int((arr[i] - min_el) * scale); // Вычисление класса
        if (idx >= m) idx = m - 1; // Защита от выхода за границы
        temp[--count[idx]] = arr[i]; // Перемещение элемента
    }

    // Копирование обратно в исходный массив - O(n)
    for (int i = 0; i < n; i++) arr[i] = temp[i];

    // Локальная сортировка каждого класса - O(n log n) в худшем случае
    int start = 0; // start - 4 байта
    for (int i = 0; i < m; i++) { // i - 4 байта
        int end = count[i]; // end - 4 байта
        if (end - start > 1) { // Сортировать только если в классе больше одного элемента
            sort(arr.begin() + start, arr.begin() + end); // Вызов STL sort - O(n log n)
        }
        start = end;
    }
} // Итого: память O(n + m), сложность O(n) в среднем, O(n^2) в худшем случае
