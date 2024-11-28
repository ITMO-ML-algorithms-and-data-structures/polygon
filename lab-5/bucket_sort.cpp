#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort
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

void bucketSort(std::vector<int>& arr, int n) {
    // Найти максимальное значение в массиве
    int maxValue = arr[0];
    // Поиск макс значения - O(N)
    for (int i = 1; i < n; i ++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Создать векторы (ведра) для bucket sort
    int bucketCount = maxValue / 10 + 1; // Количество ведер
    std::vector<std::vector<int>> buckets(bucketCount); // память O(k) - создаем вектор "ведер"

    // Разделить массив на ведра
    // Проходим по массиву - О(N)
    for (int i = 0; i < n; i ++) {
        int bucketIndex = arr[i] / 10; // Индекс ведра
        buckets[bucketIndex].push_back(arr[i]); // память О(N * k)
    }

    // Отсортировать каждое ведро и собрать результат
    int index = 0;
    // Проход по всем вёдрам - О(k)
    for (int i = 0; i < bucketCount; i ++) {
        // Сложность std::sort
        // Время - (N / k) * log (N / k) во всех случаях
        // Память - log (N / k) во всех случаях
        std::sort(buckets[i].begin(), buckets[i].end()); // Сортируем ведро
        // Проход по всем элементам ведра - О(N / k)
        for (int j = 0; j < buckets[i].size(); j ++) {
            arr[index++] = buckets[i][j]; // Собрать отсортированные элементы
        }
    }

    // Итого:
    // Временная сложность:
    // Лучший случай - О(N), средний и худший - О(N * k)
    // Память:
    // Во всех случаях - О(N * k)
}


int main() {
    // for (int i = 1000; i <= 1000000; i *= 10) {
    //     std::vector<int> arr;        
    //     std::string tmp_file = std::to_string(i) + ".csv";

    //     read_csv(tmp_file, arr);
    //     int n = arr.size();

    //     auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

    //     bucketSort(arr, n);

    //     auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
    //     std::chrono::duration<double> duration = end - start;
    //     std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы
    // }
    // for (int i = 1000; i <= 1000000; i *= 10) {
    //     for (int j = 1; j <= 9; j ++) {
    //         std::vector<int> arr;        
    //         std::string tmp_file = std::to_string(i * j) + ".csv";

    //         read_csv(tmp_file, arr);

    //         int n = arr.size();

    //         auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

    //         bucketSort(arr, n);

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

        bucketSort(arr, n);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
    }


    return 0;
}
