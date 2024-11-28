#include <iostream>
#include <vector>
using namespace std;

// Функция для сортировки пузырьком
void bubbleSort(vector<float> &v) {
    int n = v.size(); // Переменная `n`: 4 байта
    for (int i = 0; i < n - 1; i++) { // Внешний цикл: O(n)
        for (int j = 0; j < n - i - 1; j++) { // Внутренний цикл: O(n - i)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]); // Сравнение и обмен: O(1)
        }
    }
    // Временная сложность: O(n^2)
    // Пространственная сложность: O(1), так как сортировка выполняется на месте
}

// Функция для выполнения блочной сортировки
void bucketSort(float arr[], int n) {
    vector<float> b[n]; 
    // `b`: массив векторов, каждый вектор имеет размер O(k), где k — среднее количество элементов в блоке
    // Пространственная сложность: O(n), так как в худшем случае все элементы могут попасть в один блок

    // Распределение элементов по блокам
    for (int i = 0; i < n; i++) { // Цикл: O(n)
        int bi = n * arr[i]; // Вычисление индекса блока: O(1)
        b[bi].push_back(arr[i]); // Добавление элемента в блок: O(1) амортизировано
    }

    // Сортировка каждого блока
    for (int i = 0; i < n; i++) { // Цикл: O(n)
        bubbleSort(b[i]); // Сортировка блока: O(k^2), где k — количество элементов в блоке
    }
    // В худшем случае суммарное время сортировки блоков: O(n^2)

    // Сборка отсортированных элементов обратно в массив
    int index = 0; // Переменная `index`: 4 байта
    for (int i = 0; i < n; i++) { // Цикл: O(n)
        for (int j = 0; j < b[i].size(); j++) { // Итерация по каждому блоку: O(k)
            arr[index++] = b[i][j]; // Копирование элемента: O(1)
        }
    }
    // Итоговая временная сложность: O(n^2) в худшем случае
    // Пространственная сложность: O(n)
}

bool areArraysEqual(float *array1, float *array2, int size1, int size2) {
    // Проверка, равны ли размеры массивов
    if (size1 != size2) { // Сравнение размеров: O(1)
        return false;
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
    float data1[] = {0.11, 0.05, 0.15, 0.25, 0.04, 0.99}; // Массив: 6 элементов * 4 байта = 24 байта
    int data1Size = sizeof(data1) / sizeof(data1[0]); // Размер массива: 4 байта
    float expected1[] = {0.04, 0.05, 0.11, 0.15, 0.25, 0.99}; // Массив: 6 элементов * 4 байта = 24 байта

    float data2[] = {}; // Пустой массив: 0 байт
    int data2Size = sizeof(data2) / sizeof(data2[0]); // Размер массива: 4 байта
    float expected2[] = {}; // Пустой массив: 0 байт

    float data3[] = {0.01}; // Массив из одного элемента: 4 байта
    int data3Size = sizeof(data3) / sizeof(data3[0]); // Размер массива: 4 байта
    float expected3[] = {0.01}; // Массив из одного элемента: 4 байта

    // Выполнение сортировки
    bucketSort(data1, data1Size); // O(n^2) в худшем случае
    bucketSort(data2, data2Size); // O(n^2) в худшем случае
    bucketSort(data3, data3Size); // O(n^2) в худшем случае

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
