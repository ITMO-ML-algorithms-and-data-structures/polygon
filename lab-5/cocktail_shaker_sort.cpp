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

    // Количество проходов:
    // Лучший случай - О(1)
    // Худший и средий случай - О(N)
    while (swapped) {
        // Сбрасываем флаг swapped
        swapped = false;

        // Прямой проход
        // Количество проходов - в среднем О(N / 2)
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]); // память O(1) - меняем местами значения в веторе
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
        // Количество проходов - в среднем О(N / 2)
        for (int i = end; i > start; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]); // память O(1) - меняем местами значения в веторе
                swapped = true;
            }
        }

        // Увеличиваем начало для следующей итерации
        ++start;
    }

    // Итого:
    // Временная сложность:
    // Лучший случай - О(N), средний и худший - О(N ^ 2)
    // Память:
    // Во всех случаях - О(1), т.к. только меняем местами 2 значения
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // for (int i = 1000; i <= 1000000; i *= 10) {
    //     std::vector<int> arr;
    //     std::string tmp_file = std::to_string(i) + ".csv";

    //     read_csv(tmp_file, arr);

    //     auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

    //     cocktailShakerSort(arr);

    //     auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
    //     std::chrono::duration<double> duration = end - start;
    //     std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы
    // }
    //  for (int i = 1000; i <= 1000000; i *= 10) {
    //     for (int j = 1; j <= 9; j ++) {
    //         std::vector<int> arr;        
    //         std::string tmp_file = std::to_string(i * j) + ".csv";

    //         read_csv(tmp_file, arr);

    //         auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

    //         cocktailShakerSort(arr);

    //         auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
    //         std::chrono::duration<double> duration = end - start;
    //         std::cout << i * j << " " << duration.count() << std::endl; // Выводим время работы
    //     }
    // }
    for (int i = 1; i <= 50; i ++) {
        std::vector<int> arr;        
        std::string tmp_file = "100000_" + std::to_string(i) + ".csv";

        read_csv(tmp_file, arr);

        int n = arr.size();

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        cocktailShakerSort(arr);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
    }

    return 0;
}