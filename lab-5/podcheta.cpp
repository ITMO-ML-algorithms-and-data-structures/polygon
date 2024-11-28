 #include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Функция сортировки подсчетом
void countingSort(std::vector<int>& arr, int k) {
    int n = arr.size();

    // Создаем массив для подсчета частоты
    std::vector<int> count(k + 1, 0);

    // Подсчитываем частоту каждого элемента
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Перезаписываем исходный массив, используя подсчет
    int index = 0;
    for (int i = 0; i <= k; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Функция для тестирования сортировки
void testCountingSort() {
    // Лучший случай: уже отсортированный массив
    std::vector<int> bestCase = {0, 1, 2, 2, 3, 4, 5};
    countingSort(bestCase, 5);
    assert(bestCase == std::vector<int>({0, 1, 2, 2, 3, 4, 5}));

    // Средний случай: случайный массив
    std::vector<int> averageCase = {3, 1, 4, 2, 0, 5, 2};
    countingSort(averageCase, 5);
    assert(averageCase == std::vector<int>({0, 1, 2, 2, 3, 4, 5}));

    // Худший случай: массив, состоящий только из одного значения
    std::vector<int> worstCase = {3, 3, 3, 3, 3};
    countingSort(worstCase, 3);
    assert(worstCase == std::vector<int>({3, 3, 3, 3, 3}));

    std::cout << "Все тесты пройдены успешно!" << std::endl;
}

int main() {
    // Запуск тестов
    testCountingSort();

    int N, k;
    std::cout << "Введите количество элементов (до 1e6): "; 
    std::cin >> N; 

    if (N > 1e6) { 
        std::cout << "Количество элементов должно быть не больше 1e6." << std::endl; 
        return 1; 
    }

    std::cout << "Введите максимальное значение (k): "; 
    std::cin >> k; 

    std::vector<int> arr(N); 
    std::cout << "Введите элементы массива (в пределах 0 до " << k << "): "; 
    for (int i = 0; i < N; ++i) { 
        std::cin >> arr[i]; 
    }

    countingSort(arr, k); 

    std::cout << "Отсортированный массив: "; 
    for (int i = 0; i < N; ++i) { 
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl; 

    return 0; 
}   