#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
//сложность выполняемого алгоритма - О(n*log n)
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

void heapify(std::vector<int>& arr, int n, int i) {
    // находим наибольший элемент среди корня, левого потомка и правого
    int largest = i;
    int l = 2 * i + 1; //левый потомок 
    int r = 2 * i + 2; //правый потомок
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    // если корень не является наибольшим, меняем элементы и продолжаем упорядочивание
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// основная функция для выполнения Heap Sort
void heapSort(std::vector<int>& arr, int n) {
    // упорядочиваем массив
    for (int i = (n / 2) - 1; i >= 0; i--) heapify(arr, n, i);
    // по одному извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0],arr[i]);  // текущий корень перемещён в конец
        heapify(arr, i, 0);  // снова вызываем функцию heapify для уменьшенной неотсортированной части
    }
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

        heapSort(arr, n);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
    }

    return 0;
}
