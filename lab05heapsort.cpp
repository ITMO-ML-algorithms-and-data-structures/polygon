//пирамидальная сортировка 
#include <iostream>
#include <vector>


// Функция для выполнения операции heapify
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем максимальный элемент как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше текущего максимума
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если максимальный элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Рекурсивно heapify затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Главная функция для сортировки массива с использованием пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}


int main() {
    // Тестовые случаи
    // Измерение времени выполнения
    std::vector<int> test1 = {12, 11, 13, 5, 6, 7};
    clock_t start = clock();
    std::cout << "test 1:\n";
    heapSort(test1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test2 = {4, 10, 3, 5, 1, 7};
    start = clock();
    std::cout << "test 2:\n";
    heapSort(test2);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";
    
    std::vector<int> test3 = {1, 2, 3, 4, 5};
    start = clock();
    std::cout << "test 3:\n";
    heapSort(test3);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test4 = {};
    start = clock();
    std::cout << "test 4:\n";
    heapSort(test4);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    std::vector<int> test5 = {5, 4, 3, 2, 1};
    start = clock();
    std::cout << "test 5:\n";
    heapSort(test5);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time taken: " << timeTaken << " seconds.\n";

    return 0;
}
