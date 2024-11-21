#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <future>


void merge(std::vector<int>& arr, int left, int mid, int right) { // массив по ссылки поэтому 12 байт
   

    int n1 = mid - left + 1; //4 Байта
    int n2 = right - mid;     //4 байта
 
    std::vector<int> L(n1), R(n2); //О(н)
 
    for (int i = 0; i < n1; i++)//O("<n/2")
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)////O("<n/2") 
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;// 12 байт

    while (i < n1 && j < n2) {//<
        if (L[i] <= R[j]) {
            arr[k] = L[i];//O(1)*"<n/2"  и меньше сравнения
            i++;//O(1)*"<n/2"  и меньше прибавление
        }
        else {//аналогично предыдущему
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Аналогично линейно
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
void mergeSort(std::vector<int>& arr, int left, int right) {//Ветор передан ссылкой ,но мы посчитаем его тут ,а не в осовной программе
    //О(n) по числу инициализированных элементов
    if (left < right) {
        int mid = left + (right - left) / 2; 
        //Рекурсивные вызовы массивов на половину меньших предыдущих будет log _2 n  вызовов так как 
        //мы решаем уравнение n/(2**кол-во вызовов)=1 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        //Мы уже посчитали ,что у функции слияния линейная сложность => она тоже вызывется рекурсивно log_2 n раз
        merge(arr, left, mid, right);
    }
}//Итого: O(n+n)*O(log_2 n) => O(N)*O(log N)



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

    // Тест 3: Любой массив
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
    mergeSort(arr,0,arr.size()-1);
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


int main() {
    //// Запуск программы 100 раз и запись времени выполнения в файл
    //runTestsMultipleTimes(100);

    std::string outputFile = "C:\\Users\\admin\\Downloads\\shaker_sort_times.txt";

    // Запуск параллельной обработки массивов
    processArraysInParallel(10, outputFile);

    std::cout << "Обработка завершена. Результаты записаны в файл: " << outputFile << std::endl;

    
}

