#include <iostream>
#include <vector>
#include <cassert>

// сортирует массив с использованием алгоритма сортировки голубиных отверстий
void pigeonhole_sort(int arr[], int n)
{
    // нахождение минимального и максимального значений в массиве
    int min_value = arr[0], max_value = arr[0]; // O(1): инициализация переменных
    for (int i = 1; i < n; i++)                 // O(N): поиск минимума и максимума
    {
        if (arr[i] < min_value) // O(1): сравнение
            min_value = arr[i]; // O(1): обновление минимума
        if (arr[i] > max_value) // O(1): сравнение
            max_value = arr[i]; // O(1): обновление максимума
    }
    int range = max_value - min_value + 1; // O(1): вычисление диапазона

    // создание массива векторов. размер массива равен диапазону. каждый вектор представляет собой отверстие, содержащее соответствующие элементы.
    std::vector<int> holes[range]; // O(range): выделение памяти для векторов

    // проход по входному массиву и размещение каждого элемента в соответствующее ему отверстие
    for (int i = 0; i < n; i++)                      // O(N): заполнение векторов
        holes[arr[i] - min_value].push_back(arr[i]); // O(1): вставка элемента в вектор

    // проход по всем отверстиям одно за другим. для каждого отверстия взять его элементы и поместить в массив.
    int index = 0;                  // O(1)
    for (int i = 0; i < range; i++) // O(range): проход по каждому вектору
    {
        for (int value : holes[i]) // O(m): m - количество элементов в текущем векторе
            arr[index++] = value;  // O(1): копирование значения из вектора обратно в исходный массив
    }
}

void test_best_case()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_average_case()
{
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_worst_case()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_2worst_case()
{
    int arr[] = {5, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

// тесты для крайних случаев
void test_empty_array()
{
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    assert(n == 0);
}

void test_single_element()
{
    int arr[] = {42};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    assert(arr[0] == 42);
}

void test_two_elements_sorted()
{
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    assert(arr[0] == 1 && arr[1] == 2);
}

void test_two_elements_unsorted()
{
    int arr[] = {2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    assert(arr[0] == 1 && arr[1] == 2);
}

void test_negative_numbers()
{
    int arr[] = {-3, -1, -4, -2, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}
void test_large_range()
{
    int arr[] = {1000, -1000, 500, -500, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonhole_sort(arr, n);
    assert(arr[0] == -1000 && arr[1] == -500 && arr[2] == 0 && arr[3] == 500 && arr[4] == 1000);
}

int main()
{
    test_best_case();
    std::cout << "Тест для лучшего случая пройден" << std::endl;

    test_average_case();
    std::cout << "Тест для среднего случая пройден" << std::endl;

    test_worst_case();
    std::cout << "Тест для худшего случая пройден" << std::endl;

    test_2worst_case();
    std::cout << "Тест для второго худшего случая пройден" << std::endl;

    // тесты для крайних случаев
    test_empty_array();
    std::cout << "Тест для пустого массива пройден" << std::endl;

    test_single_element();
    std::cout << "Тест для массива с одним элементом пройден" << std::endl;

    test_two_elements_sorted();
    std::cout << "Тест для отсортированного массива из двух элементов пройден" << std::endl;

    test_two_elements_unsorted();
    std::cout << "Тест для неотсортированного массива из двух элементов пройден" << std::endl;

    test_negative_numbers();
    std::cout << "Тест для массива с отрицательными числами пройден" << std::endl;

    test_large_range();
    std::cout << "Тест для массива с большим диапазоном значений пройден" << std::endl;

    return 0;
}
