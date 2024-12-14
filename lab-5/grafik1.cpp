#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>

// Функция пузырьковой сортировки
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Функция для тестирования сортировки
void testBubbleSort() {
    std::vector<int> bestCase = {1, 2, 3, 4, 5};
    bubbleSort(bestCase);
    assert(bestCase == std::vector<int>({1, 2, 3, 4, 5}));

    std::vector<int> averageCase = {5, 3, 4, 1, 2};
    bubbleSort(averageCase);
    assert(averageCase == std::vector<int>({1, 2, 3, 4, 5}));

    std::vector<int> worstCase = {5, 4, 3, 2, 1};
    bubbleSort(worstCase);
    assert(worstCase == std::vector<int>({1, 2, 3, 4, 5}));

    std::cout << "Все тесты пройдены успешно!" << std::endl;
}

int main() {
    // Запуск тестов
    testBubbleSort();

    // Измерение времени сортировки для различных размеров массивов
    for (int N = 1000; N <= 1e6; N += 1000) {
        std::vector<int> arr(N);
        
        // Заполнение массива случайными числами
        for (int i = 0; i < N; ++i) {
            arr[i] = rand() % 10000; // случайные числа от 0 до 9999
        }

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        std::cout << "Размер массива: " << N << ", Время сортировки: " << duration.count() << " секунд" << std::endl;
    }

    return 0;
}