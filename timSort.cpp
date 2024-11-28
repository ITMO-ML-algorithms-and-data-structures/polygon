#include <iostream>
#include <algorithm> // Для функции min
using namespace std;

const int RUN = 32; // Размер подмассива для Insertion Sort

// Функция сортировки вставками
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i]; // Временная переменная для вставки: 4 байта
        int j = i - 1;
        while (j >= left && arr[j] > temp) { // O(n) в худшем случае
            arr[j + 1] = arr[j]; // Сдвиг элементов: O(1)
            j--;
        }
        arr[j + 1] = temp; // Вставка элемента: O(1)
    }
    // Временная сложность: O(n^2) для подмассива длины n
    // Пространственная сложность: O(1), так как сортировка выполняется на месте
}

// Функция слияния двух отсортированных частей массива
void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2]; 
    // Временные массивы для слияния: O(len1 + len2)

    // Копирование элементов в временные массивы
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; // O(len1)
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; // O(len2)

    // Слияние двух массивов обратно в arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) { // O(len1 + len2)
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Копирование оставшихся элементов
    while (i < len1) 
        arr[k++] = left[i++]; // O(len1)
    while (j < len2) 
        arr[k++] = right[j++]; // O(len2)

    // Временная сложность: O(len1 + len2)
    // Пространственная сложность: O(len1 + len2) для временных массивов
}

// TimSort
void timSort(int arr[], int n) {
    // Сортировка подмассивов размером RUN с помощью сортировки вставками
    for (int i = 0; i < n; i += RUN) 
        insertionSort(arr, i, min((i + RUN - 1), (n - 1))); // O(RUN^2 * (n / RUN))

    // Слияние подмассивов
    for (int size = RUN; size < n; size = 2 * size) { // Логарифмический рост размера подмассивов: O(log(n / RUN))
        for (int left = 0; left < n; left += 2 * size) { // Количество слияний: O(n / size)
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right); // O(size)
        }
    }
    // Временная сложность:
    // - O(n log n) для слияния
    // - O(RUN^2 * (n / RUN)) ≈ O(n) для сортировки вставками
    // Итоговая временная сложность: O(n log n)
    // Пространственная сложность: O(n) из-за временных массивов для слияния
}

// Проверка на равенство массивов
bool areArraysEqual(int *array1, int *array2, int size1, int size2) {
    if (size1 != size2) return false; // O(1)
    for (int i = 0; i < size1; ++i) {
        if (array1[i] != array2[i]) return false; // O(n)
    }
    return true; // Пространственная сложность: O(1)
}

// Главная функция
int main() {
    int test_passed = 0; // 4 байта
    int test_failed = 0; // 4 байта

    // Тестовые данные
    int data1[] = {12, 11, 13, 5, 6, 7}; // 6 элементов: 24 байта
    int data1Size = sizeof(data1) / sizeof(data1[0]); // 4 байта
    int expected1[] = {5, 6, 7, 11, 12, 13}; // 6 элементов: 24 байта

    int data2[] = {}; // Пустой массив: 0 байт
    int data2Size = sizeof(data2) / sizeof(data2[0]); // 4 байта
    int expected2[] = {}; // Пустой массив: 0 байт

    int data3[] = {0}; // 1 элемент: 4 байта
    int data3Size = sizeof(data3) / sizeof(data3[0]); // 4 байта
    int expected3[] = {0}; // 1 элемент: 4 байта

    // Выполнение сортировки
    timSort(data1, data1Size); // O(n log n)
    timSort(data2, data2Size); // O(1)
    timSort(data3, data3Size); // O(1)

    // Проверка тестов
    if (areArraysEqual(data1, expected1, data1Size, data1Size)) {
        ++test_passed;
        cout << "[PASSED] Test 1" << endl;
    } else {
        ++test_failed;
        cout << "[NOT PASSED] Test 1" << endl;
    }
    if (areArraysEqual(data2, expected2, data2Size, data2Size)) {
        ++test_passed;
        cout << "[PASSED] Test 2" << endl;
    } else {
        ++test_failed;
        cout << "[NOT PASSED] Test 2" << endl;
    }
    if (areArraysEqual(data3, expected3, data3Size, data3Size)) {
        ++test_passed;
        cout << "[PASSED] Test 3" << endl;
    } else {
        ++test_failed;
        cout << "[NOT PASSED] Test 3" << endl;
    }

    // Вывод результатов
    cout << "Tests passed: " << test_passed << endl; // O(1)
    cout << "Tests failed: " << test_failed << endl; // O(1)

    return 0;
}
