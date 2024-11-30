#include <iostream>
#include <vector>
#include <cassert>

// сортирует массив с использованием алгоритма сортировки голубиных отверстий
void pigeonhole_sort(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }
    int n = arr.size(); // О(1): определение размера вектора
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
    // создание вектора векторов. размер массива равен диапазону. каждый вектор представляет собой отверстие, содержащее соответствующие элементы.
    std::vector<std::vector<int>> holes(range); // O(range): выделение памяти для векторов

    // проход по входному массиву и размещение каждого элемента в соответствующее ему отверстие
    for (int i = 0; i < n; i++)                      // O(N): заполнение векторов
        holes[arr[i] - min_value].push_back(arr[i]); // O(1): вставка элемента в вектор

    // проход по всем отверстиям одно за другим. для каждого отверстия надо взять его элементы и поместить в массив.
    int index = 0;                  // O(1)
    for (int i = 0; i < range; i++) // O(range): проход по каждому вектору
    {
        for (int value : holes[i]) // O(m): m - количество элементов в текущем векторе
            arr[index++] = value;  // O(1): копирование значения из вектора обратно в исходный массив
    }
}

void test_best_case()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    pigeonhole_sort(arr);
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_average_case()
{
    std::vector<int> arr = {3, 1, 4, 2, 5};
    pigeonhole_sort(arr);
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_worst_case()
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    pigeonhole_sort(arr);
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_large_range()
{
    std::vector<int> arr = {1000, -1000, 500, -500, 0};
    pigeonhole_sort(arr);
    assert(arr[0] == -1000 && arr[1] == -500 && arr[2] == 0 && arr[3] == 500 && arr[4] == 1000);
}

// тесты для крайних случаев
void test_empty_array()
{
    std::vector<int> arr; // Пустой вектор
    pigeonhole_sort(arr);
    assert(arr.empty()); // Проверка, что вектор пустой
}

void test_single_element()
{
    std::vector<int> arr = {42};
    pigeonhole_sort(arr);
    assert(arr[0] == 42);
}

void test_two_elements_sorted()
{
    std::vector<int> arr = {1, 2};
    pigeonhole_sort(arr);
    assert(arr[0] == 1 && arr[1] == 2);
}

void test_two_elements_unsorted()
{
    std::vector<int> arr = {2, 1};
    pigeonhole_sort(arr);
    assert(arr[0] == 1 && arr[1] == 2);
}

void test_negative_numbers()
{
    std::vector<int> arr = {-3, -1, -4, -2, -5};
    pigeonhole_sort(arr);
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

int main()
{
    test_best_case();
    std::cout << "Тест для лучшего случая пройден" << std::endl;

    test_average_case();
    std::cout << "Тест для среднего случая пройден" << std::endl;

    test_worst_case();
    std::cout << "Тест для худшего случая пройден" << std::endl;

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