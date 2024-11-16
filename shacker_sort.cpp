#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

// Функция сортировки шейкер-сортом
void shakerSort(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}

// Функция считывающая датасет
std::vector<int> load_data() {
    std::vector<int> data;
    std::ifstream file("C:\\Users\\R1300-W-1-Stud\\Documents\\ata.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        while (std::getline(ss, item, '\t')) {
            int item1 = std::stoi(item); // Используем int, так как массив должен быть типа int
            data.push_back(item1);
        }
    }
    return data;
}

// Тесты
int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED] " << testName << "\n";
        test_passed++;
    }
    else {
        std::cout << "[NOT PASSED] " << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTests passed total: " << test_passed << "\n";
    std::cout << "Tests not passed total: " << test_failed << "\n";
}

// Функция тестирования
void test(std::vector<int>& arr) {
    // Тест 1: Проверка размера массива
    assertEqual(arr.size() <= 1e6, "Test input data by condition (size <= 1e6)");

    // Копируем массив для дальнейших проверок
    std::vector<int> arr_sorted = arr;
    std::vector<int> arr_reverse = arr;

    // Сортировка для проверки
    std::sort(arr_sorted.begin(), arr_sorted.end());
    std::sort(arr_reverse.begin(), arr_reverse.end(), std::greater<int>());

    // Тест 2: Массив уже отсортирован
    shakerSort(arr);
    assertEqual(arr == arr_sorted, "Test: Array is already sorted, shakerSort should not change it");

    // Тест 3: Массив отсортирован в обратном порядке
    shakerSort(arr_reverse);
    assertEqual(arr_reverse == arr_sorted, "Test: Array is sorted in reverse order, shakerSort should sort it");

    report();
}

// Функция для запуска основной программы несколько раз и записи времени выполнения в файл
void runTestsMultipleTimes(int numRuns) {
    std::ofstream outputFile("C:\\Users\\R1300-W-1-Stud\\Documents\\execution_times.txt", std::ios::out | std::ios::trunc);

    if (!outputFile) {
        std::cerr << "Ошибка открытия файла для записи.\n";
        return;
    }

    for (int i = 0; i < numRuns; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        // Загружаем данные
        std::vector<int> arr = load_data();

        // Вызов функции тестирования
        test(arr);

        // Вычисление времени выполнения
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        // Записываем время выполнения в файл
        outputFile << diff.count() << " \n";
    }

    outputFile.close();
    std::cout << "Execution times have been saved to execution_times.txt.\n";
}

int main() {
    // Запуск программы 50 раз и запись времени выполнения в файл
    runTestsMultipleTimes(50);

    return 0;
}
