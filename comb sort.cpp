#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <random>

// Ограничение на максимальный размер массива
const int max_size = 1e6;

// Функция сортировки
void CombSort(std::vector<int>& arr) {
    int n = arr.size();
    int step = n; // начальный шаг
    bool swapped = true;

    while (step != 1 || swapped) {
        // Уменьшаем шаг
        step = std::max(1, (int)(step / 1.3));
        swapped = false;

        // Сравниваем элементы на текущем шаге
        for (int i = 0; i + step < n; i++) {
            if (arr[i] > arr[i + step]) {
                std::swap(arr[i], arr[i + step]);
                swapped = true;
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

void TestCombSort() {
    // Тест для лучшего случая (уже отсортирован массив)
    std::vector<int> test1 = { 1, 2, 3, 4, 5 };
    std::cout << "Start array: ";
    PrintArray(test1);
    CombSort(test1);
    std::cout << "Sorted array: ";
    PrintArray(test1);

    // Тест для среднего случая (случайные элементы)
    std::vector<int> test2 = { 3, 1, 4, 2, 5 };
    std::cout << "Start array: ";
    PrintArray(test2);
    CombSort(test2);
    std::cout << "Sorted array: ";
    PrintArray(test2);

    // Тест для худшего случая (массив отсортирован в обратном порядке)
    std::vector<int> test3 = { 5, 4, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test3);
    CombSort(test3);
    std::cout << "Sorted array: ";
    PrintArray(test3);

    // Тест на дубликаты
    std::vector<int> test4 = { 3, 1, 2, 3, 2, 1 };
    std::cout << "Start array: ";
    PrintArray(test4);
    CombSort(test4);
    std::cout << "Sorted array: ";
    PrintArray(test4);
}

int main() {
    TestCombSort();
    /*std::ofstream ofile("BoxPlotComb_sort5e.csv"); // Открытие файла для записи

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
        CombSort(arr); // Сортировка вектора
        auto end = std::chrono::high_resolution_clock::now(); // Конец измерения времени

        std::chrono::duration<double> duration = end - start; // Вычисление времени
        ofile << arr.size() << "," << duration.count() << "\n"; // Запись размеров вектора и времени в файл
    } // Сортировка и измерение времени

    ofile.close(); // Закрытие файла
    std::cout << "BoxPlotCombsort.csv is done" << std::endl;
    std::vector<int> arr = { 5, 3, 8, 4, 2, 7, 1, 6 };
    int n = arr.size();
    std::cout << "Unsorted array";
    PrintArray(arr);
    CombSort(arr);
    std::cout << "Sorted array: ";
    PrintArray(arr);
    */

    return 0;
}

/*1. Асимптотическая сложность
Лучший случай: O(nlogn) — если массив почти отсортирован, алгоритм работает эффективнее.
Средний случай: O(nlogn) — определяется оценкой средней стоимости обменов и сравнений на случайных данных.
Худший случай: O(n^2) — происходит, когда данные далеко от отсортированных, и массив задан в таком порядке, что происходит много обменов.
2. Использование памяти
Comb Sort использует дополнительную память O(1) : Алгоритм сортирует массив на месте,
не требуя выделения дополнительной памяти для хранения массивов.
*/