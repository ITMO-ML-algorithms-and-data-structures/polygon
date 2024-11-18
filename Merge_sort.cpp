#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

// Функция для проверки отсортированности массива
bool isSorted(const std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Функция для слияния двух отсортированных частей
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Проверка отсортированности подмассива перед слиянием
    if (isSorted(arr, left, right)) {
        std::cout << "Subarray from " << left << " to " << right << " is already sorted, skipping merge.\n";
        return;  // Если отсортировано, пропускаем слияние
    }

    int n1 = mid - left + 1;  // Размер левого подмассива
    int n2 = right - mid;     // Размер правого подмассива

    // Создаем временные массивы для левой и правой части
    std::vector<int> L(n1), R(n2);

    // Копируем данные в временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Индексы для левый, правой части и основного массива
    int i = 0, j = 0, k = left;

    // Слияние временных массивов обратно в основной массив arr[]
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

    // Копирование оставшихся элементов в arr[], если они есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Рекурсивная функция сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Находим середину массива

        // Рекурсивно сортируем левую и правую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
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


void test(std::vector<int>& arr) {
    // Тест 1: Проверка размера массива
    assertEqual(arr.size() <= 1e6, "Test input data by condition (size <= 1e6)");

    // Копируем массив для дальнейших проверок
    std::vector<int> arr_sorted = arr;
    std::vector<int> arr_r = arr;
    
    // Сортировка для проверки
    std::sort(arr_sorted.begin(), arr_sorted.end());
   
    

    // Тест 2: Массив уже отсортирован
    mergeSort(arr, 0, arr.size() - 1);
    assertEqual(arr == arr_sorted, "Test: Array is already sorted, shakerSort should not change it");

    // Тест 3: Л
    mergeSort(arr, 0, arr.size() - 1);
    assertEqual(arr_r == arr_sorted, "Test: All class array");

    report();
}

//
//
//// Функция считывающая датасет 1e4 или 1e5
//std::vector<int> load_data() {
//    std::vector<int> data;
//    std::ifstream file("C:\\Users\\admin\\polygon\\1e5.txt");
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
//
//
//
//// Функция для запуска основной программы numRuns  раз с датасетом в 1е4 и 1е5 и записи времени выполнения в файл.
////Нужно чтоб получить данные для построения таблицы 
//void runTestsMultipleTimes(int numRuns) {
//    std::ofstream outputFile("C:\\Users\\admin\\Downloads\\merge_execution_time1e5.txt", std::ios::out | std::ios::trunc);
//
//    if (!outputFile) {
//        std::cerr << "ERROR.\n";
//        return;
//    }
//
//    for (int i = 0; i < numRuns; ++i) {
//        auto start = std::chrono::high_resolution_clock::now();
//
//        // Загружаем данные
//        std::vector<int> arr = load_data();
//        mergeSort(arr, 0, arr.size() - 1);
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



// Функция для чтения данных из CSV файла и измерения времени сортировки каждой строки
void processFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile, std::ios::app);

    // Проверяем, открылись ли файлы успешно
    if (!inFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << inputFile << std::endl;
        return;
    }
    if (!outFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << outputFile << std::endl;
        return;
    }

    std::string line; // Переменная для чтения строк из файла

    // Чтение строк из входного CSV файла
    while (std::getline(inFile, line)) {
        // Разбираем строку на числа, разделенные запятыми
        std::istringstream lineStream(line);
        std::string item;
        std::vector<int> arr;

        // Разбиваем строку на элементы и добавляем в вектор
        while (std::getline(lineStream, item, ',')) {
            int number = std::stoi(item);
            arr.push_back(number);
        }

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        outFile << arr.size() << ' ' << duration.count() << std::endl;
    }

    // Закрытие файлов
    inFile.close();
    outFile.close();

    std::cout << "Обработка завершена. Результаты записаны в файл: " << outputFile << std::endl;
}


int main() {
    //// Запуск программы 100 раз и запись времени выполнения в файл
    //runTestsMultipleTimes(100);

    std::string inputFile = "C:\\Users\\R1300-W-1-Stud\\PycharmProjects\\pythonProject\\random_numbers.csv";
    std::string outputFile = "C:\\Users\\R1300-W-1-Stud\\Downloads\\time_line_char.txt";

    processFile(inputFile, outputFile);

    return 0;
}

