#include <iostream>
#include <cassert>
#include <vector>

// переворачивает arr[0..i]
void flip(std::vector<int> &arr, int i)
{
    int temp;    // O(1): создание временной переменной
    int start = 0; // O(1): создание счетчика
    while (start < i) // O(i): цикл выполняется i/2 раз
    {
        temp = arr[start];             // O(1): присваивание значения
        arr[start] = arr[i];           // O(1): присваивание значения
        arr[i] = temp;                 // O(1): присваивание значения
        start++;                       // O(1): увеличиваем счетчик
        i--;                           // O(1): уменьшаем индекс
    }
}

// находит индекс максимального элемента в arr[0..i-1]
int find_max_index(const std::vector <int> &arr, int i)
{
    int max_i = 0; // O(1): инициализация переменной для хранения индекса максимального элемента

    for (int index = 0; index < i; index++) // O(i): цикл выполняется i раз
    {
        if (arr[index] > arr[max_i]) // O(1): сравнение двух значений
        {
            max_i = index; // O(1): обновление индекса максимального элемента
        }
    }

    return max_i; // O(1)
}

// основная функция, которая сортирует данный массив с помощью операций переворота
void pancake_sort(std::vector<int> &arr)
{
    for (int curr_size = arr.size(); curr_size > 1; curr_size--) // O(n^2): внешний цикл выполняется n раз
    {
        int max_index = find_max_index(arr, curr_size); // O(curr_size): вызов функции поиска максимального элемента
        if (max_index != curr_size - 1) // O(1): проверка необходимости переворота
        {
            flip(arr, max_index);     // O(max_index): первый переворот
            flip(arr, curr_size - 1); // O(curr_size): второй переворот
        }
    }
}

// тесты
void test_best_case()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    pancake_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_average_case()
{
    std::vector<int> arr = {3, 1, 4, 2, 5};
    pancake_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_worst_case()
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    pancake_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

// крайние случаи
void test_empty_array()
{
    std::vector <int> arr;
    pancake_sort(arr);
    // пустой массив остается пустым, программа работает без ошибок
}

void test_single_element()
{
    std::vector<int> arr = {1};
    pancake_sort(arr);
    assert(arr[0] == 1);
}

void test_all_elements_same()
{
    std::vector<int> arr = {7, 7, 7, 7, 7};
    pancake_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] == arr[i + 1]);
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

    test_empty_array();
    std::cout << "Тест для пустого массива пройден" << std::endl;

    test_single_element();
    std::cout << "Тест для массива с одним элементом пройден" << std::endl;

    test_all_elements_same();
    std::cout << "Тест для массива с одинаковыми элементами пройден" << std::endl;

    return 0;
}