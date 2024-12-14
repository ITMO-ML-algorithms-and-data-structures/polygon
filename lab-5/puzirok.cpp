#include <iostream>
#include <vector>

// Функция для выполнения пузырьковой сортировки
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Последние i элементов уже отсортированы
        for (int j = 0; j < n - i - 1; j++) {
            // Сравниваем соседние элементы
            if (arr[j] > arr[j + 1]) {
                // Если они в неправильном порядке, меняем их местами
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Если не было обменов, массив уже отсортирован
        if (!swapped) {
            break;
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
    // Инициализация вектора с помощью списка инициализации
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Исходный массив: ";
    printArray(arr);

    bubbleSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}