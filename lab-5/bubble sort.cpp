#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

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

void bubble_sort(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j]; // создали дополнительную переменную
            arr[j] = arr[j + 1]; // меняем местами
            arr[j + 1] = temp; // значения элементов
        }
        }
    }
    return 0;
    }

int main() {
    // for (int i = 1000; i <= 1000000; i *= 10) {
    //     std::vector<int> arr;        
    //     std::string tmp_file = std::to_string(i) + ".csv";

    //     read_csv(tmp_file, arr);
    //     int n = arr.size();

    //     auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

    //     inPlaceMergeSort(arr, 0, n - 1);

    //     auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
    //     std::chrono::duration<double> duration = end - start;
    //     std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы
    // }
//    for (int i = 1000; i <= 1000000; i *= 10) {
//         for (int j = 1; j <= 9; j ++) {
//             std::vector<int> arr;        
//             std::string tmp_file = std::to_string(i * j) + ".csv";

//             read_csv(tmp_file, arr);

//             int n = arr.size();

//             auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

//             inPlaceMergeSort(arr, 0, n - 1);

//             auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
//             std::chrono::duration<double> duration = end - start;
//             std::cout << i * j << " " << duration.count() << std::endl; // Выводим время работы
//         }
//     }
    for (int i = 1; i <= 50; i ++) {
        std::vector<int> arr;        
        std::string tmp_file = "100000_" + std::to_string(i) + ".csv";

        read_csv(tmp_file, arr);

        int n = arr.size();

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        bubble_sort(arr, n);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
    }

    return 0;
}