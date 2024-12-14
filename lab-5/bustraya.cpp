#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Функция для разбиения массива
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для тестирования сортировки
void testQuickSort() {
    // Лучший случай: уже отсортированный массив
    std::vector<int> bestCase = {1, 2, 3, 4, 5};
    quickSort(bestCase, 0, bestCase.size() - 1);
    assert(bestCase == std::vector<int>({1, 2, 3, 4, 5}));

    // Средний случай: случайный массив
    std::vector<int> averageCase = {5, 3, 4, 1, 2};
    quickSort(averageCase, 0, averageCase.size() - 1);
    assert(averageCase == std::vector<int>({1, 2, 3, 4, 5}));

    // Худший случай: массив, отсортированный в обратном порядке
    std::vector<int> worstCase = {5, 4, 3, 2, 1};
    quickSort(worstCase, 0, worstCase.size() - 1);
    assert(worstCase == std::vector<int>({1, 2, 3, 4, 5}));

    std::cout << "Все тесты пройдены успешно!" << std::endl;
}

int main() {
    // Запуск тестов
    testQuickSort();

    int N;
    std::cout << "Введите количество элементов (до 1e6): "; 
    std::cin >> N; 

    if (N > 1e6) { 
        std::cout << "Количество элементов должно быть не больше 1e6." << std::endl; 
        return 1; 
    }

    std::vector<int> arr(N); 
    std::cout << "Введите элементы массива: "; 
    for (int i = 0; i < N; ++i) { 
        std::cin >> arr[i]; 
    }

    quickSort(arr, 0, N - 1); 

    std::cout << "Отсортированный массив: "; 
    for (int i = 0; i < N; ++i) { 
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl; 

    return 0; 
}