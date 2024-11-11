#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

void read_csv(const std::string& filename, std::vector<int>& intArray) { // Функция чтения чисел из csv в массив
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) { // Split by comma
            try {
                int number = std::stoi(value); // Convert to int
                intArray.push_back(number); // Add to the vector
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << value << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range: " << value << std::endl;
            }
        }
    }

    file.close();
}

void cocktailShakerSort(std::vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        // Сбрасываем флаг swapped
        swapped = false;

        // Прямой проход
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Если ничего не было обменяно, массив уже отсортирован
        if (!swapped) {
            break;
        }

        // Уменьшаем конец для следующей итерации
        --end;

        // Сбрасываем флаг swapped для обратного прохода
        swapped = false;

        // Обратный проход
        for (int i = end; i > start; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }

        // Увеличиваем начало для следующей итерации
        ++start;
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    for (int i = 1000; i <= 1000000; i *= 10) {
        std::vector<int> arr;
        std::string tmp_file = std::to_string(i) + ".csv";

        read_csv(tmp_file, arr);

        // std::cout << "Input array: ";
        // printArray(arr);
        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        cocktailShakerSort(arr);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы

        // std::cout << "Sorted array: ";
        // printArray(arr);
    }

    return 0;
}