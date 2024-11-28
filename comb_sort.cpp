#include <iostream>
#include <cassert>

// функция для вычисления следующего шага
int get_next_gap(int gap)
{
    // уменьшаем шаг на коэффициент сжатия
    gap = (gap * 10) / 13; // O(1)
    if (gap < 1)           // O(1)
    {
        return 1; // O(1)
    }
    return gap; // O(1)
}

// функция для сортировки массива методом comb sort
void comb_sort(int arr[], const int n)
{
    int gap = n;         // O(1)
    bool swapped = true; // O(1): устанавливаем флаг swapped как true, чтобы цикл гарантированно запустился хотя бы один раз

    // продолжаем выполнение цикла до тех пор, пока шаг не станет равным 1 или произошла хотя бы одна перестановка
    while (gap != 1 || swapped == true) // O(N^2)
    {
        gap = get_next_gap(gap); // O(1): вычисляем следующий шаг
        swapped = false;         // O(1): сбрасываем флаг swapped, чтобы проверить, произошли ли перестановки в этом проходе

        for (int i = 0; i < n - gap; i++) // O(N): сравниваем все элементы с текущим шагом
        {
            if (arr[i] > arr[i + gap]) // O(1)
            {
                int temp = arr[i];     // O(1)
                arr[i] = arr[i + gap]; // O(1)
                arr[i + gap] = temp;   // O(1)
                swapped = true;        // O(1): установка флага, если была выполнена перестановка
            }
        }
    }
}

void test_best_case()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_average_case()
{
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_worst_case()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_empty_array()
{
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    assert(n == 0);
}

void test_single_element()
{
    int arr[] = {97};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    assert(arr[0] == 97);
}

void test_with_duplicates()
{
    int arr[] = {4, 5, 4, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    comb_sort(arr, n);
    for (int i = 0; i < n - 1; i++)
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

    test_empty_array();
    std::cout << "Тест для пустого массива пройден" << std::endl;

    test_single_element();
    std::cout << "Тест для массива с одним элементом пройден" << std::endl;

    test_with_duplicates();
    std::cout << "Тест для массива с дубликатами пройден" << std::endl;

    return 0;
}