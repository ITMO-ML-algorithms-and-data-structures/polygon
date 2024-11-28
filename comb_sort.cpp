#include <iostream>
#include <cassert>
#include <vector>

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

// функция для сортировки вектора методом comb sort
void comb_sort(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }
    int gap = arr.size(); // O(1)
    bool swapped = true;  // O(1): устанавливаем флаг swapped как true, чтобы цикл гарантированно запустился хотя бы один раз

    // продолжаем выполнение цикла до тех пор, пока шаг не станет равным 1 или не произойдёт ни одной перестановки
    while (gap != 1 || swapped == true) // O(N^2)
    {
        gap = get_next_gap(gap); // O(1): вычисляем следующий шаг
        swapped = false;         // O(1): сбрасываем флаг swapped, чтобы проверить, произошли ли перестановки в этом проходе

        for (int i = 0; i < arr.size() - gap; i++) // O(N): сравниваем все элементы с текущим шагом
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
    std::vector<int> arr = {1, 2, 3, 4, 5};
    comb_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_average_case()
{
    std::vector<int> arr = {3, 1, 4, 2, 5};
    comb_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_worst_case()
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    comb_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_empty_vector()
{
    std::vector<int> arr;
    comb_sort(arr);
    assert(arr.empty());
}

void test_single_element()
{
    std::vector<int> arr = {97};
    comb_sort(arr);
    assert(arr[0] == 97);
}

void test_with_duplicates()
{
    std::vector<int> arr = {4, 5, 4, 3, 2, 2};
    comb_sort(arr);
    for (int i = 0; i < arr.size() - 1; i++)
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

    test_empty_vector();
    std::cout << "Тест для пустого вектора пройден" << std::endl;

    test_single_element();
    std::cout << "Тест для вектора с одним элементом пройден" << std::endl;

    test_with_duplicates();
    std::cout << "Тест для вектора с дубликатами пройден" << std::endl;

    return 0;
}