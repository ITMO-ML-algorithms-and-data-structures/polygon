#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <random>

// Ограничение на максимальный размер массива
const int max_size = 1e6;

// Функция для переворачивания части массива до k-го элемента
void flip(std::vector<int>& arr, int k){
	std::reverse(arr.begin(), arr.begin() + k);
}

// Функция для нахождения максимального элемента
int FindMax(std::vector<int> arr, int n) {
	int MaxIndex = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] > arr[MaxIndex]) {
			MaxIndex = i;
		}
	return MaxIndex;
}

// Основная функция сортировки
void PancakeSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int curr_size = n; curr_size > 1; curr_size--) {
        // Находим индекс максимального элемента в несортированной части
        int MaxIndex = FindMax(arr, curr_size);

        // Если максимальный элемент не на своем месте
        if (MaxIndex != curr_size - 1) {
            // Переворачиваем массив до максимального элемента, если он не на позиции 0
            if (MaxIndex != 0) {
                flip(arr, MaxIndex + 1);
            }
            // Переворачиваем массив до текущего размера
            flip(arr, curr_size);
        }
    }
}

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

void TestPancake() {
    // Тест для лучшего случая (уже отсортирован массив)
    std::vector<int> test1 = { 1, 2, 3, 4, 5 };
    std::cout << "Start array: ";
    PrintArray(test1);
    PancakeSort(test1);
    std::cout << "Sorted array: ";
    PrintArray(test1);

    // Тест для среднего случая (случайные элементы)
    std::vector<int> test2 = { 3, 1, 4, 2, 5 };
    std::cout << "Start array: ";
    PrintArray(test2);
    PancakeSort(test2);
    std::cout << "Sorted array: ";
    PrintArray(test2);

    // Тест для худшего случая (массив отсортирован в обратном порядке)
    std::vector<int> test3 = { 5, 4, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test3);
    PancakeSort(test3);
    std::cout << "Sorted array: ";
    PrintArray(test3);

    // Тест на дубликаты
    std::vector<int> test4 = { 3, 1, 2, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test4);
    PancakeSort(test4);
    std::cout << "Sorted array: ";
    PrintArray(test4);
}

int main()
{
    TestPancake();
    /*std::ofstream ofile("BoxPlotPancake5e.csv"); // Открытие файла для записи

    if (!ofile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    ofile << "VectorSize,SortTime(seconds)\n"; // Запись заголовков в файл

    for (int i = 0; i < 51; i ++) {
        int size = 100000;
        std::vector<int> arr = generateRandomVector(size); // Генерация случайного вектора
        int n = arr.size();
        if (n < 1 || n > max_size) {
            std::cerr << "Error: The size of the array must be between 1 and " << max_size << "." << std::endl;
            return 1;
        }
        auto start = std::chrono::high_resolution_clock::now(); // Начало измерения времени
        PancakeSort(arr); // Сортировка вектора
        auto end = std::chrono::high_resolution_clock::now(); // Конец измерения времени

        std::chrono::duration<double> duration = end - start; // Вычисление времени
        ofile << arr.size() << "," << duration.count() << "\n"; // Запись размеров вектора и времени в файл
    } // Сортировка и измерение времени

    ofile.close(); // Закрытие файла
    std::cout << "BoxPlotPancake.csv. is done" << std::endl;
    std::vector<int> arr = { 3, 6, 1, 5, 2, 4 };
    std::cout << "Start array: ";
    PrintArray(arr);
    PancakeSort(arr);
    std::cout << "Sorted array: ";
    PrintArray(arr);
*/
    return 0;
}
//1. Асимптотическая сложность
//Лучший случай:O(n) — если массив уже отсортирован, не требуется переворотов.
//Средний случай:O(n^2) — в общем случае, алгоритм выполняет много переворотов, особенно при случайной перестановке.
//Худший случай:O(n^2) — создаётся максимальное количество переворотов, например, когда элементы расположены в обратном порядке.

//2. Использование памяти
//Pancake Sort использует дополнительную памятьO(1): Мы не создаём дополнительные массивы, 
// только модифицируем существующий, поэтому память для внешних данных остаётся постоянной.