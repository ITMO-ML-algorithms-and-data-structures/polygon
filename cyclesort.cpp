/*
   Асимптотика Cycle Sort:

   Временная сложность:
   1. В худшем случае (если массив отсортирован в обратном порядке) Cycle Sort требует выполнения нескольких циклов по массиву,
      что приводит к временной сложности O(n^2), где n — количество элементов в массиве.
   2. В среднем случае алгоритм также выполняет O(n^2) операций, поскольку на каждом цикле поиска позиции элемента мы проходим по оставшейся части массива.
   3. В лучшем случае, если элементы массива уже отсортированы, каждый элемент будет на своей позиции, и цикл завершится после первой перестановки, что даст временную сложность O(n^2).

   Пространственная сложность:
   Cycle Sort не использует дополнительных массивов для хранения данных, все операции происходят в самом массиве. Это приводит к пространственной сложности O(1), то есть алгоритм работает с постоянным количеством дополнительной памяти.

   Итого:
   - Худшая временная сложность: O(n^2)
   - Лучшая временная сложность: O(n^2)
   - Средняя временная сложность: O(n^2)
   - Пространственная сложность: O(1)
   */

#include <iostream>
#include <vector>
#include <cassert>

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void cycleSort(std::vector<int> &array) {
    int n = array.size(); // Получаем размер вектора
    int writes = 0;

    // Проходим по всем элементам и ставим их на правильное место
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        // Инициализируем элемент как начальную точку
        int item = array[cycle_start];

        // Находим позицию, на которую нужно поставить элемент.
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (array[i] < item)
                pos++;

        // Если элемент уже на правильной позиции
        if (pos == cycle_start)
            continue;

        // Игнорируем все одинаковые элементы
        while (item == array[pos])
            pos++;

        // Ставим элемент на его правильную позицию
        if (pos != cycle_start) {
            Swap(item, array[pos]);
            writes++;
        }

        // Поворачиваем остаток цикла
        while (pos != cycle_start) {
            pos = cycle_start;

            // Находим позицию, на которую нужно поставить элемент
            for (int i = cycle_start + 1; i < n; i++)
                if (array[i] < item)
                    pos++;

            // Игнорируем все одинаковые элементы
            while (item == array[pos])
                pos++;

            // Ставим элемент на его правильную позицию
            if (item != array[pos]) {
                Swap(item, array[pos]);
                writes++;
            }
        }
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
    // 1) Худший случай: массив отсортирован в обратном порядке
    std::vector<int> worstCaseArray = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cycleSort(worstCaseArray);
    assert(isSorted(worstCaseArray));

    // 2) Средний случай: случайный массив
    std::vector<int> averageCaseArray = {3, 8, 2, 5, 1, 4, 7, 0, 9, 6};
    cycleSort(averageCaseArray);
    assert(isSorted(averageCaseArray));

    // 3) Лучший случай: массив уже отсортирован
    std::vector<int> bestCaseArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cycleSort(bestCaseArray);
    assert(isSorted(bestCaseArray));

    std::cout << "All tests passed !" << std::endl;
}

int main() {
    runTests();

    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> array(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    cycleSort(array);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}
