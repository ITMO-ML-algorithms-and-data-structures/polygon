#include <iostream>
#include <vector>

// Функция для построения кучи
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;  // Инициализируем largest как корень //4 байта
    int left = 2 * i + 1;  // Левый дочерний элемент //4 байта
    int right = 2 * i + 2; // Правый дочерний элемент //4 байта
    //Сложность: O(1); 12 байт

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    //Сложность: O(1)

    // Если правый дочерний элемент больше текущего largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    //Сложность:O(1)

    // Если largest не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Сложность: O(1)

        // Рекурсивно приводим поддерево в порядок
        heapify(arr, n, largest); //Сложность:O(logN); 12*logN
    }
}

// Основная функция сортировки Heap Sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();//4 байта
    //Сложность: O(1); 4 байта

    // Строим кучу (переводим массив в форму кучи)
    for (int i = n / 2 - 1; i >= 0; i--) { //4 байта
        heapify(arr, n, i);
    }
    //Сложность: O(N); 4 байта

    // Извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) { //4 байта
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
    //Сложность: O(N*logN); 4 байта
}

int main() {
    // Пример: Массив для сортировки
    std::vector<int> arr = {5, 1, 4, 2, 8, 7, 6, 3};//Сложность: O(N); 4*N байт

    heapSort(arr); //Сложность: O(N*logN)

    // Вывод отсортированного массива
    for (int i = 0; i < arr.size(); i++) { //4 байта
        std::cout << arr[i] << " "; //Сложность:O(N)
    }

    return 0;
    //Сложность: O(N*logN); 4*N + 4 байт
}

