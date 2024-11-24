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
    std::vector<std::string> data_samples = {"1000", "2000", "3000", "4000", "5000", "6000", "7000", "8000", "9000", 
                                           "10000", "20000", "30000", "40000", "50000", "60000", "70000", "80000", "90000", "100000",
                                           "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "900000", "1000000"};
//    std::vector<std::string> data_samples = {"100000"};
    std::vector<float> corr_median_time;
    std::cout << data_samples.size() << std::endl;
    for(int i=0; i < data_samples.size(); i++){
        float sum_time = 0;
        for (int j = 1; j <= 10; j ++) {
        std::vector<int> arr;        
        std::string tmp_file = data_samples[i] + "_" + std::to_string(j) + ".csv";

        read_csv(tmp_file, arr);

        int n = arr.size();

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        heapSort(arr, n);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count() << std::endl; // Выводим время работы
        sum_time += duration.count();
    }
    corr_median_time.push_back(sum_time/10);
    }
    for (auto now : corr_median_time) {
        cout << now << " ";
    }
  return 0;
    }
    
