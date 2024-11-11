
#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Начинаем с большого интервала и уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Основной цикл для сортировки подмассива
        for (int i = gap; i < n; i++) {
            // Сохраняем текущее значение
            int temp = arr[i];
            int j;

            // Сдвигаем элементы arr[0..i-gap], которые превышают temp, на один
            // место вперед, чтобы сделать место для temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
    std::vector<int> arr = {12, 34, 54, 2, 3};

    std::cout << "Input array: ";
    printArray(arr);

    shellSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}