#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <random>

// Ограничение на максимальный размер массива
const int max_size = 1e6;

// Выбор размера run
int GetMinrun(int n)
{
    int r = 0;           // станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой 
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}  

// Функция сортировки вставками для небольших частей массива
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Перемещаем элементы, которые больше ключа, на одну позицию вперед
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция слияния двух отсортированных подмассивов
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Находим размеры двух подмассивов для слияния
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Копируем данные во временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Сливаем временные массивы обратно в arr[left..right]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = left; // Индекс слияния

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Основная функция Timsort
void timSort(std::vector<int>& arr) {
    int n = arr.size();
    int run = GetMinrun(n);
    // Сортировка всех подмассивов размером run
    for (int start = 0; start < n; start += run) {
        int end = std::min(start + run - 1, n - 1);
        insertionSort(arr, start, end);
    }

    // Слияние отсортированных подмассивов в размером RUN
    for (int size = run; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);      // Середина
            int right = std::min((left + 2 * size - 1), (n - 1)); // Правый край

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Функция для вывода массива
void PrintArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
    std::mt19937 rng(std::random_device{}()); // Инициализация генератора случайных чисел
    std::uniform_int_distribution<int> distrib(0, 1000000); // Распределение от 0 до 1,000,000

    for (int i = 0; i < size; ++i) {
        vec[i] = distrib(rng); // Генерация случайного числа
    }
    return vec;
}

void Test_timSort() {
    // Тест для лучшего случая (уже отсортирован массив)
    std::vector<int> test1 = { 1, 2, 3, 4, 5 };
    std::cout << "Start array: ";
    PrintArray(test1);
    timSort(test1);
    std::cout << "Sorted array: ";
    PrintArray(test1);

    // Тест для среднего случая (случайные элементы)
    std::vector<int> test2 = { 3, 1, 4, 2, 5 };
    std::cout << "Start array: ";
    PrintArray(test2);
    timSort(test2);
    std::cout << "Sorted array: ";
    PrintArray(test2);

    // Тест для худшего случая (массив отсортирован в обратном порядке)
    std::vector<int> test3 = { 5, 4, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test3);
    timSort(test3);
    std::cout << "Sorted array: ";
    PrintArray(test3);

    // Тест на дубликаты
    std::vector<int> test4 = { 3, 1, 2, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test4);
    timSort(test4);
    std::cout << "Sorted array: ";
    PrintArray(test4);
}


int main() {
    Test_timSort();
    /*std::ofstream ofile("BoxPlotTimsort5e.csv"); // Открытие файла для записи

    if (!ofile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    ofile << "VectorSize,SortTime(seconds)\n"; // Запись заголовков в файл

    for (int i = 0; i < 51; i++) {
        int size = 100000;
        std::vector<int> arr = generateRandomVector(size); // Генерация случайного вектора
        int n = arr.size();
        if (n < 1 || n > max_size) {
            std::cerr << "Error: The size of the array must be between 1 and " << max_size << "." << std::endl;
            return 1;
        }
        auto start = std::chrono::high_resolution_clock::now(); // Начало измерения времени
        timSort(arr); // Сортировка вектора
        auto end = std::chrono::high_resolution_clock::now(); // Конец измерения времени

        std::chrono::duration<double> duration = end - start; // Вычисление времени
        ofile << arr.size() << "," << duration.count() << "\n"; // Запись размеров вектора и времени в файл
    } // Сортировка и измерение времени

    ofile.close(); // Закрытие файла
    std::cout << "BoxPlotTimsort.csv. is done" << std::endl;
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7, 100, 1 };
    std::cout << "Unsorted array: ";
    PrintArray(arr);
    timSort(arr);
    PrintArray(arr);
    std::cout << "Sorted array: ";
    */
    return 0;
}

/* 1. Асимптотическая сложность
Лучший случай:  O(n) — если массив уже отсортирован, Timsort будет проходить по массиву один раз и не будет выполнять слияний.
Средний случай: O(nlogn) — это сложность обычного слияния сортировок, так как Timsort основан на принципах сортировки слиянием и вставками.
Худший случай: O(nlogn) — в худшем случае, слияния происходят для всех подмассивов.
2. Использование памяти
O(n) : Для временных массивов, которые создаются во время процесса слияния. 
Это значит, что память потребляется в зависимости от размеров подмассивов.
*/