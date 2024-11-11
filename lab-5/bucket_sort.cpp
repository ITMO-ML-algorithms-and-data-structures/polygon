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

void bucketSort(std::vector<int>& arr) {
    // Создаем ведра
    int n = arr.size();
    std::vector<std::vector<int>> buckets(n);

    // Разделяем элементы на ведра
    for (int num : arr) {
        int bucketIndex = n * num; // Преобразуем число в индекс ведра
        if (bucketIndex >= n) {
            bucketIndex = n - 1; // Убедимся, что индекс не выходит за пределы
        }
        buckets[bucketIndex].push_back(num);
    }

    // Сортировка каждого ведра
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // Объединяем ведра
    arr.clear();
    for (const auto& bucket : buckets) {
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

int main() {
    for (int i = 1000; i <= 1000000; i *= 10) {
        std::vector<int> arr;        
        std::string tmp_file = std::to_string(i) + ".csv";

        read_csv(tmp_file, arr);

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        bucketSort(arr);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы
    }


    return 0;
}
