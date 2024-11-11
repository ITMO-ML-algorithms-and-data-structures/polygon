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

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int start2 = mid + 1;

    // Если первый элемент меньше или равен последнему элементу второго подмассива, ничего не делаем
    if (arr[mid] <= arr[start2]) {
        return;
    }

    // Слияние двух подмассивов
    while (left <= mid && start2 <= right) {
        if (arr[left] <= arr[start2]) {
            left ++;
        } else {
            int value = arr[start2];
            int index = start2;

            // Сдвигаем все элементы на одно место вправо
            while (index != left) {
                arr[index] = arr[index - 1];
                index --;
            }
            arr[left] = value;

            // Обновляем индексы
            left ++;
            mid ++;
            start2 ++;
        }
    }
}

void inPlaceMergeSort(std::vector<int>& arr, int left, int right) {
    // Рекурсивное деление массива на подмассивы
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивная сортировка левой и правой половин
        inPlaceMergeSort(arr, left, mid);
        inPlaceMergeSort(arr, mid + 1, right);

        // Слияние отсортированных подмассивов
        merge(arr, left, mid, right);
    }
}

int main() {
    for (int i = 1000; i <= 1000000; i *= 10) {
        std::vector<int> arr;        
        std::string tmp_file = std::to_string(i) + ".csv";

        read_csv(tmp_file, arr);
        int n = arr.size();

        auto start = std::chrono::high_resolution_clock::now(); // Фиксируем время старта    

        inPlaceMergeSort(arr, 0, n - 1);

        auto end = std::chrono::high_resolution_clock::now(); // Фиксируем время окончания
        std::chrono::duration<double> duration = end - start;
        std::cout << "Execution time for " << i << " : " << duration.count() << " seconds" << std::endl; // Выводим время работы
    }

    

    return 0;
}
