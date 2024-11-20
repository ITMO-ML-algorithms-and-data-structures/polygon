#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <future>
#include <algorithm> 
#include <sstream>



// Функция для создания сбалансированного массива
void generateBalancedArray(std::vector<int>&arr, int start, int end) {
    if (start > end) {
        return;
    }
    int mid = (start + end) / 2;
    arr.push_back(mid);  // Добавляем средний элемент

    generateBalancedArray(arr, start, mid - 1);  // Левое поддерево
    generateBalancedArray(arr, mid + 1, end);   // Правое поддерево
}

// Функция для создания несбалансированного массива (по возрастанию)
void generateUnbalancedArray(std::vector<int>& arr, int start, int end) {
    for (int i = start; i <= end; ++i) {
        arr.push_back(i);  // Добавляем элементы в порядке возрастания
    }
}

// Функция для создания обратного несбалансированного массива (по убыванию)
void generateReverseUnbalancedArray(std::vector<int>& arr, int start, int end) {
    for (int i = end; i >= start; --i) {
        arr.push_back(i);  // Добавляем элементы в порядке убывания
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
    std::vector<int> balancedArray;
    std::vector<int> reverseUnbalancedArray;
    std::vector<int> unbalancedArray;

    int n = arr.size();
    generateBalancedArray(balancedArray, 0, n - 1);
    generateReverseUnbalancedArray(reverseUnbalancedArray, 0, n - 1);
    generateUnbalancedArray(unbalancedArray, 0, n - 1);
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    // Тест 1: Проверка сбалансированного массива
    std::sort(balancedArray.begin(), balancedArray.end());
    assertEqual(balancedArray == sortedArr, "Balanced array sort check");

    // Тест 2: Проверка обратного несбалансированного массива
    std::sort(reverseUnbalancedArray.begin(), reverseUnbalancedArray.end());
    assertEqual(reverseUnbalancedArray == sortedArr, "Reverse unbalanced array sort check");

    // Тест 3: Проверка несбалансированного массива
    std::sort(unbalancedArray.begin(), unbalancedArray.end());
    assertEqual(unbalancedArray == sortedArr, "Unbalanced array sort check");

    report();
}

class TreeNode {
public:
    int value;           // Значение узла
    TreeNode* left;      // Указатель на левое поддерево
    TreeNode* right;     // Указатель на правое поддерево

    // Конструктор для инициализации узла с заданным значением
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;  // Корневой узел дерева

    BinarySearchTree() : root(nullptr) {}  // Конструктор по умолчанию

    // Вставка элемента в дерево
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Инфиксный обход дерева (сортировка)
    void inorderTraversal(std::vector<int>& sortedArr) {
        inorderRec(root, sortedArr);
    }
private:
    // Рекурсивная функция для вставки элемента
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == nullptr) {  // Если нашли пустое место, создаем новый узел
            return new TreeNode(value);
        }

        if (value < node->value) {  // Идем в левое поддерево
            node->left = insertRec(node->left, value);
        }
        else {  // Идем в правое поддерево
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    // Рекурсивная функция для инфиксного обхода
    void inorderRec(TreeNode* node, std::vector<int>& sortedArr) {
        if (node == nullptr) {  // Базовый случай рекурсии: узел пуст
            return;
        }

        inorderRec(node->left, sortedArr);  // Обходим левое поддерево
        sortedArr.push_back(node->value);  // Сохраняем значение узла
        inorderRec(node->right, sortedArr);  // Обходим правое поддерево
    }
};



void treeSort(std::vector<int>& arr) {
    BinarySearchTree bst;

    // Вставляем все элементы в дерево
    for (int val : arr) {
        bst.insert(val);
    }

    // Получаем отсортированные элементы с помощью инфиксного обхода
    std::vector<int> sortedArr;
    bst.inorderTraversal(sortedArr);

    // Копируем отсортированные элементы обратно в исходный массив
    arr = sortedArr;
}


//// Функция для генерации массива случайных чисел
//std::vector<int> generateRandomArray(int size) {
//    std::vector<int> arr(size);
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(0, 10000);
//
//    for (int i = 0; i < size; ++i) {
//        arr[i] = dis(gen);
//    }
//    return arr;
//}

//// Функция для измерения времени сортировки
//double measureSortTime(std::vector<int>& arr) {
//    auto start = std::chrono::high_resolution_clock::now();
//    treeSort(arr);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = end - start;
//    return duration.count();
//}
//
//// Функция, которая генерирует массив и измеряет время сортировки
//void processArrayAndSaveTime(int size, const std::string& outputFile) {
//    // Генерация массива
//    std::vector<int> arr = generateRandomArray(size);
//
//    // Измерение времени сортировки
//    double duration = measureSortTime(arr);
//
//    // Запись времени выполнения в файл
//    std::ofstream outFile(outputFile, std::ios::app);
//    if (outFile.is_open()) {
//        outFile << size << " " << duration << "\n";
//        outFile.close();
//    }
//    else {
//        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
//    }
//}
//
//// Функция для параллельной обработки массивов
//void processArraysInParallel(int numArrays, const std::string& outputFile) {
//    std::vector<std::future<void>> futures;
//
//    for (int i = 1; i <= numArrays; ++i) {
//        int size = i * 100000; // Размер массива = i * 100000
//        futures.push_back(std::async(std::launch::async, processArrayAndSaveTime, size, outputFile));
//
//        // Ограничиваем количество параллельных потоков (например, 4 потока одновременно)
//        if (futures.size() >= 4) {
//            for (auto& fut : futures) {
//                fut.get(); // Ждем завершения всех потоков
//            }
//            futures.clear(); // Очищаем список
//        }
//    }
//
//    // Ждем завершения всех оставшихся потоков
//    for (auto& fut : futures) {
//        fut.get();
//    }
//}



// Функция считывающая датасет 1e4 или 1e5
std::vector<int> load_data() {
    std::vector<int> data;
    std::ifstream file("C:\\Users\\admin\\polygon\\1e5.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        while (std::getline(ss, item, '\t')) {
            int item1 = std::stoi(item);
            data.push_back(item1);
        }
    }
    return data;
}



// Функция для запуска основной программы numRuns  раз с датасетом в 1е4 и 1е5 и записи времени выполнения в файл.
//Нужно чтоб получить данные для построения таблицы 
void runTestsMultipleTimes(int numRuns) {
    std::ofstream outputFile("C:\\Users\\admin\\Downloads\\tree_execution_time1e6.txt", std::ios::out | std::ios::trunc);

    if (!outputFile) {
        std::cerr << "Ошибка открытия файла для записи.\n";
        return;
    }

    for (int i = 0; i < numRuns; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        // Загружаем данные
        std::vector<int> arr = load_data();
        treeSort(arr);
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
    // Запуск программы 100 раз и запись времени выполнения в файл
    runTestsMultipleTimes(100);
   


    //std::string outputFile = "C:\\Users\\admin\\Downloads\\shaker_sort_times.txt";

    //// Запуск параллельной обработки массивов
    //processArraysInParallel(10, outputFile);

    //std::cout << "Обработка завершена. Результаты записаны в файл: " << outputFile << std::endl;

    return 0;
}


