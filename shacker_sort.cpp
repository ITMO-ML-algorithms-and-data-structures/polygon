#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <future>

// Функция сортировки шейкер-сортом
void shakerSort(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    bool swapped = true;

    while (left < right&& swapped) {
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

////Функция для создания среднего по сложности случая (массив на половину отсортирован на половину осортирован по убыванию)
//void sortArrayHalves(std::vector<int>& arr) {
//    // Находим середину массива
//    size_t mid = arr.size() / 2;
//
//    // Сортируем первую половину (по возрастанию)
//    std::sort(arr.begin(), arr.begin() + mid);
//
//    // Сортируем вторую половину (по убыванию)
//    std::sort(arr.begin() + mid, arr.end(), std::greater<int>());
//}
//
//
//// Тесты
//int test_passed = 0;
//int test_failed = 0;
//
//void assertEqual(bool condition, const std::string& testName) {
//    if (condition) {
//        std::cout << "[PASSED] " << testName << "\n";
//        test_passed++;
//    }
//    else {
//        std::cout << "[NOT PASSED] " << testName << "\n";
//        test_failed++;
//    }
//}
//
//void report() {
//    std::cout << "\nTests passed total: " << test_passed << "\n";
//    std::cout << "Tests not passed total: " << test_failed << "\n";
//}
//
//// Функция тестирования в худшем и лучшем случае работы алгоритма
//void test(std::vector<int>& arr) {
//    // Тест 1: Проверка размера массива
//    assertEqual(arr.size() <= 1e6, "Test input data by condition (size <= 1e6)");
//
//    // Копируем массив для дальнейших проверок
//    std::vector<int> arr_sorted = arr;
//    std::vector<int> arr_reverse = arr;
//    std::vector<int> arr_mid_reverse = arr;
//
//    // Сортировка для проверки
//    std::sort(arr_sorted.begin(), arr_sorted.end());
//    std::sort(arr_reverse.begin(), arr_reverse.end(), std::greater<int>());
//    sortArrayHalves(arr_mid_reverse);
//
//    // Тест 2: Массив уже отсортирован
//    shakerSort(arr);
//    assertEqual(arr == arr_sorted, "Test: Array is already sorted, shakerSort should not change it");
//
//    // Тест 3: Массив отсортирован в обратном порядке
//    shakerSort(arr_reverse);
//    assertEqual(arr_reverse == arr_sorted, "Test: Array is sorted in reverse order, shakerSort should sort it");
//
//    //Тест 4: Половина массива по возрастанию ,половина по убыванию
//    shakerSort(arr_mid_reverse);
//    assertEqual(arr_mid_reverse == arr_sorted, "Test: Array is sorted in reverse on middle order, shakerSort should sort it");
//    report();
//}

// Функция для генерации массива случайных чисел
std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10000);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Функция для измерения времени сортировки
double measureSortTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    shakerSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция, которая генерирует массив и измеряет время сортировки
void processArrayAndSaveTime(int size, const std::string& outputFile) {
    // Генерация массива
    std::vector<int> arr = generateRandomArray(size);

    // Измерение времени сортировки
    double duration = measureSortTime(arr);

    // Запись времени выполнения в файл
    std::ofstream outFile(outputFile, std::ios::app);
    if (outFile.is_open()) {
        outFile << size << " " << duration << "\n";
        outFile.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
    }
}

// Функция для параллельной обработки массивов
void processArraysInParallel(int numArrays, const std::string& outputFile) {
    std::vector<std::future<void>> futures;

    for (int i = 1; i <= numArrays; ++i) {
        int size = i * 100000; // Размер массива = i * 100000
        futures.push_back(std::async(std::launch::async, processArrayAndSaveTime, size, outputFile));

        // Ограничиваем количество параллельных потоков (например, 4 потока одновременно)
        if (futures.size() >= 4) {
            for (auto& fut : futures) {
                fut.get(); // Ждем завершения всех потоков
            }
            futures.clear(); // Очищаем список
        }
    }

    // Ждем завершения всех оставшихся потоков
    for (auto& fut : futures) {
        fut.get();
    }
}



//// Функция считывающая датасет 1e4 или 1e5
//std::vector<int> load_data() {
//    std::vector<int> data;
//    std::ifstream file("C:\\Users\\admin\\polygon\\1e4.txt");
//    std::string line;
//    while (std::getline(file, line)) {
//        std::istringstream ss(line);
//        std::string item;
//        while (std::getline(ss, item, '\t')) {
//            int item1 = std::stoi(item);
//            data.push_back(item1);
//        }
//    }
//    return data;
//}



//// Функция для запуска основной программы numRuns  раз с датасетом в 1е4 и 1е5 и записи времени выполнения в файл.
////Нужно чтоб получить данные для построения таблицы 
//void runTestsMultipleTimes(int numRuns) {
//    std::ofstream outputFile("C:\\Users\\admin\\Downloads\\shaker_execution_time1e4.txt", std::ios::out | std::ios::trunc);
//
//    if (!outputFile) {
//        std::cerr << "Ошибка открытия файла для записи.\n";
//        return;
//    }
//
//    for (int i = 0; i < numRuns; ++i) {
//        auto start = std::chrono::high_resolution_clock::now();
//
//        // Загружаем данные
//        std::vector<int> arr = load_data();
//        shakerSort(arr);
//
//        // Вычисление времени выполнения
//        auto end = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> diff = end - start;
//
//        // Записываем время выполнения в файл
//        outputFile << diff.count() << " \n";
//    }
//
//    outputFile.close();
//    std::cout << "Execution times have been saved to execution_times.txt.\n";
//}

int main() {
    //// Запуск программы 50 раз и запись времени выполнения в файл
    //runTestsMultipleTimes(100);

    std::string outputFile = "C:\\Users\\admin\\Downloads\\shaker_sort_times.txt";

    // Запуск параллельной обработки массивов
    processArraysInParallel(10, outputFile);

    std::cout << "Обработка завершена. Результаты записаны в файл: " << outputFile << std::endl;

    return 0;
}
