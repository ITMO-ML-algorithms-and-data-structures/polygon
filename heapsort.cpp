/*
Асимптотика пирамидальной сортировки

Временная сложность:
1. Построение кучи (функция heapify) выполняется за время O(n), так как каждый элемент в куче может быть обработан не более чем за O(log n) времени.
   Однако, для всего массива этот процесс оценивается как O(n), поскольку большая часть элементов будет обрабатываться за O(1) или O(log n) по мере продвижения снизу вверх.
2. Сортировка массива путём извлечения элементов из кучи (извлечение максимального элемента и восстановление кучи) требует O(log n) времени для каждого извлечения.
   Так как извлекается n элементов, суммарная сложность этого этапа — O(n log n).

Итого, общая временная сложность:
- Худшая временная сложность: O(n log n)
- Средняя временная сложность: O(n log n)
- Лучшая временная сложность: O(n log n)

Пространственная сложность:
- Не требует дополнительной памяти для хранения промежуточных данных, пространственная сложность алгоритма составляет O(1).

Итого:
- Временная сложность: O(n log n)
- Пространственная сложность: O(1)
*/

#include <iostream>
#include <vector>
#include <cassert>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для восстановления свойства кучи
void heapify(std::vector<int> &array, int n, int i) {
    int root = i; // корень
    int left_child = 2 * i + 1; // левый потомок
    int right_child = 2 * i + 2; // правый потомок

    // Проверка левого дочернего элемента
    if (left_child < n && array[left_child] > array[root]) {
        root = left_child;
    }

    // Проверка правого дочернего элемента
    if (right_child < n && array[right_child] > array[root]) {
        root = right_child;
    }

    // Если наибольший элемент не является корнем
    if (root != i) {
        swap(array[i], array[root]);
        heapify(array, n, root);
    }
}

// Функция для сортировки массива методом пирамидальной (кучей) сортировки
void heapSort(std::vector<int> &array) {
    int n = array.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]); // Перемещаем текущий корень в конец
        heapify(array, i, 0); // Вызываем heapify для уменьшенной кучи
    }
}

// Напишем вспомогательную функцию, которая проверяет отсортирован ли массив.
bool isSorted(const std::vector<int> &array) {
    for (size_t i = 1; i < array.size(); i++) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

void runTests() {
// Так как асимптотика во всех случаях одинакова, она не зависит от входных данных.
// то напишем просто несколько тестов с разными входными наборами

    std::vector<int> testarray1 = {15, -3, 22, 8, -10, 5, 12, -1, 4, 9};
    heapSort(testarray1);
    assert(isSorted(testarray1));

    std::vector<int> testarray2 = {42, 0, -15, 8, 16, 4, -6, 2, -3, 10};
    heapSort(testarray2);
    assert(isSorted(testarray2));

    std::vector<int> testarray3 = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
    heapSort(testarray3);
    assert(isSorted(testarray3));

    // Большие массивы
    std::vector<int> testaraay4(1000);
    for (int i = 0; i < 1000; ++i) {
        testaraay4[i] = 1000 - i;
    }
    heapSort(testaraay4);
    assert(isSorted(testaraay4));

    std::vector<int> testarray5(1000);
    for (int i = 0; i < 1000; ++i) {
        testarray5[i] = rand() % 10000;
    }
    heapSort(testarray5);
    assert(isSorted(testarray5));

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> array(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    heapSort(array);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
