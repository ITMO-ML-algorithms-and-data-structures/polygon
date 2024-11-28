#include <iostream> 
using namespace std;

// Функция для упорядочивания поддерева в структуре бинарной кучи
void adjustHeap(int array[], int size, int root) {
    int maxIndex = root; // Переменная `maxIndex`: 4 байта
    int leftChild = 2 * root + 1; // Переменная `leftChild`: 4 байта
    int rightChild = 2 * root + 2; // Переменная `rightChild`: 4 байта

    // Проверяем, больше ли левый потомок текущего узла
    if (leftChild < size && array[leftChild] > array[maxIndex]) {
        maxIndex = leftChild;
    }

    // Проверяем, больше ли правый потомок текущего узла
    if (rightChild < size && array[rightChild] > array[maxIndex]) {
        maxIndex = rightChild;
    }

    // Если наибольший элемент не является корнем, меняем их местами
    if (maxIndex != root) {
        swap(array[root], array[maxIndex]); // Операция swap: O(1)

        // Рекурсивно корректируем затронутое поддерево
        adjustHeap(array, size, maxIndex); // Рекурсия: O(log n)
    }
    // Пространственная сложность: O(1) дополнительных переменных
}

// Функция для выполнения пирамидальной сортировки
void performHeapSort(int array[], int size) {
    // Формируем структуру кучи
    for (int i = size / 2 - 1; i >= 0; i--) {
        adjustHeap(array, size, i); // Коррекция кучи для каждого поддерева: O(log n)
    }
    // Временная сложность: O(n log n) на построение кучи
    // Пространственная сложность: O(1)

    // Удаляем элементы из кучи по одному
    for (int i = size - 1; i > 0; i--) {
        // Перемещаем текущий корневой элемент в конец
        swap(array[0], array[i]); // O(1)

        // Корректируем оставшуюся часть кучи
        adjustHeap(array, i, 0); // O(log n)
    }
    // Временная сложность: O(n log n)
    // Пространственная сложность: O(1)
}

bool areArraysEqual(int *array1, int *array2, int size1, int size2) {
    // Проверка, равны ли размеры массивов
    if (size1 != size2) {
        return false; // Сравнение размеров: O(1)
    }

    // Проверка элементов массивов на равенство
    for (int i = 0; i < size1; ++i) { // Цикл: O(n)
        if (array1[i] != array2[i]) {
            return false;
        }
    }

    return true; // Пространственная сложность: O(1)
}

// Главная функция для тестирования сортировки
int main() {
    int test_passed = 0; // Переменная `test_passed`: 4 байта
    int test_failed = 0; // Переменная `test_failed`: 4 байта

    // Тестовые данные
    int data1[] = {12, 11, 13, 5, 6, 7}; // Массив: 6 элементов * 4 байта = 24 байта
    int data1Size = sizeof(data1) / sizeof(data1[0]); // Размер массива: 4 байта
    int expected1[] = {5, 6, 7, 11, 12, 13}; // Массив: 6 элементов * 4 байта = 24 байта

    int data2[] = {}; // Пустой массив: 0 байт
    int data2Size = sizeof(data2) / sizeof(data2[0]); // Размер массива: 4 байта
    int expected2[] = {}; // Пустой массив: 0 байт

    int data3[] = {0}; // Массив из одного элемента: 4 байта
    int data3Size = sizeof(data3) / sizeof(data3[0]); // Размер массива: 4 байта
    int expected3[] = {0}; // Массив из одного элемента: 4 байта

    // Выполнение сортировки
    performHeapSort(data1, data1Size); // O(n log n)
    performHeapSort(data2, data2Size); // O(n log n)
    performHeapSort(data3, data3Size); // O(n log n)

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

    return 0; // Пространственная сложность: O(1)
}
