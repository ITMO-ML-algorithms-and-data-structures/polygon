#include <iostream> // 0
#include <vector> // 0
#include <unordered_set> // 0
#include <cstdlib> // 0
#include <ctime> // 0
#include <fstream> // 0
#include <algorithm> // 0

// Функция для выборки K случайных элементов из массива
std::vector<int> sampleArray(const std::vector<int>& arr, int K) { // 0
    if (K > arr.size()) { // 0
        throw std::invalid_argument("K не может быть больше размера массива!"); // 0
    }

    std::unordered_set<int> selectedIndices; // 32 (в зависимости от реализации unordered_set)
    std::vector<int> result; // 24

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // 0

    // Генерация случайных индексов
    while (result.size() < K) { // 0
        int idx = std::rand() % arr.size(); // 4

        if (selectedIndices.find(idx) == selectedIndices.end()) { // 0
            selectedIndices.insert(idx); // 0
            result.push_back(arr[idx]); // 8-16
        }
    }

    return result; // 0
}

// Функция тестирования sampleArray
void runTests() {
    // Тест 1: Тест выборки 5 элементов из массива 10 элементов
    std::vector<int> testArray1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 24
    try { // 0
        std::vector<int> sampled1 = sampleArray(testArray1, 5); // 24. 0
        std::cout << "Тест 1 пройден: "; // 0
        for (int num : sampled1) { // 0
            std::cout << num << " "; // 0
        }
        std::cout << std::endl; // 0
    } catch (const std::exception& e) { // 0
        std::cerr << "Тест 1 не пройден: " << e.what() << std::endl; // 0
    }

    // Тест 2: Тест выборки 10 элементов из массива 10 элементов
    try { // 0
        std::vector<int> sampled2 = sampleArray(testArray1, 10); // 0
        std::cout << "Тест 2 пройден: "; // 0
        for (int num : sampled2) { // 0
            std::cout << num << " "; // 0
        }
        std::cout << std::endl; // 0
    } catch (const std::exception& e) { // 0
        std::cerr << "Тест 2 не пройден: " << e.what() << std::endl; // 0
    }

    // Тест 3: Тест выборки 0 элементов
    try { // 0
        std::vector<int> sampled3 = sampleArray(testArray1, 0); // 0
        std::cout << "Тест 3 пройден (ожидается пустой результат): "; // 0
        for (int num : sampled3) { // 0
            std::cout << num << " "; // 0
        }
        std::cout << std::endl; // 0
    } catch (const std::exception& e) { // 0
        std::cerr << "Тест 3 не пройден: " << e.what() << std::endl; // 0
    }

    // Тест 4: Тест выборки больше, чем размер массива
    try { // 0
        std::vector<int> sampled4 = sampleArray(testArray1, 11); // 0
        std::cerr << "Тест 4 не пройден: ожидается исключение" << std::endl; // 0
    } catch (const std::invalid_argument& e) { // 0
        std::cout << "Тест 4 пройден: " << e.what() << std::endl; // 0
    }

    // Тест 5: Проверка, что результат содержит только уникальные элементы
    try { // 0
        std::vector<int> sampled5 = sampleArray(testArray1, 5); // 0
        std::unordered_set<int> uniqueElements(sampled5.begin(), sampled5.end()); // 32
        if (uniqueElements.size() == sampled5.size()) { // 0
            std::cout << "Тест 5 пройден: Все элементы уникальны." << std::endl; // 0
        } else { // 57. 0 байт
            std::cerr << "Тест 5 не пройден: Найдены дубликаты." << std::endl; // 0
        }
    } catch (const std::exception& e) { // 0
        std::cerr << "Тест 5 не пройден: " << e.what() << std::endl; // 0
    }
}

int main() {
    std::ifstream file(R"(C:\Users\227ad\CLionProjects\LAB2\dataset.txt)");
    if (!file.is_open()) { // 0 байт
        std::cerr << "Не удается открыть файл!" << std::endl; // 0
        return 1; // 0
    }

    std::vector<int> numbers; // 24
    int number; // 4
    while (file >> number) { // 0
        numbers.push_back(number); // 8-16
    }

    runTests(); // 0

    int K = 3; // 4

    std::vector<int> sampled = sampleArray(numbers, K); // 0
    for (int num : sampled) { // 0
        std::cout << num << " "; // 0
    }
    std::cout << std::endl; // 0

    return 0; // 0
}

// Асимптотика sampleArray:
// Проверка, что K не больше размера массива: O(1).
// Инициализация unordered_set для хранения уникальных индексов: O(1).
// Цикл, который выполняется, пока не выбрано K уникальных индексов:
//        Генерация случайного индекса: O(1).
//        Проверка уникальности в unordered_set: O(1) в среднем.
//        Если индекс уникален, то вставка: O(1) в среднем.

// Общая асимптотическая сложность алгоритма выбора K уникальных элементов из массива
// в худшем случае будет O(n), однако в среднем случае, когда K значительно меньше n, сложность будет O(K).