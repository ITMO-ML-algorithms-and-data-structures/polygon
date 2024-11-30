#include <iostream>  // для ввода-вывода
#include <algorithm> // для функции swap
#include <vector>    // для использования векторов
#include <chrono>    // для измерения времени
#include <cstdlib>   // для генерации случайных чисел
#include <ctime>     // для инициализации генератора случайных чисел

// Функция для переворота arr[0..i]
void flip(int arr[], int i)
{
    int temp;
    int start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

// Функция для нахождения индекса максимального элемента в arr[0..i-1]
int find_max_index(const int arr[], const int i)
{
    int max_i = 0;
    for (int index = 0; index < i; index++)
    {
        if (arr[index] > arr[max_i])
        {
            max_i = index;
        }
    }
    return max_i;
}

// Основная функция, которая сортирует данный массив с помощью операций переворота
void pancake_sort(int *arr, const int n)
{
    // Начинаем с полного массива и по одному уменьшаем текущий размер на единицу
    for (int curr_size = n; curr_size > 1; curr_size--)
    {
        // Находим индекс максимального элемента в arr[0..curr_size-1]
        int max_index = find_max_index(arr, curr_size);
        // Перемещаем максимальный элемент в конец текущего массива, если он ещё не там
        if (max_index != curr_size - 1)
        {
            // Чтобы переместить в конец, сначала перемещаем максимальное число в начало
            flip(arr, max_index);
            // Теперь перемещаем максимальное число в конец текущего подмассива, переворачивая текущий массив
            flip(arr, curr_size - 1);
        }
    }
}

// Функция для генерации массива случайных чисел
void generate_random_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 10000; // Генерация случайного числа от 0 до 9999
    }
}

int main()
{
    const int array_size = 100000;  // Размер массива
    const int num_iterations = 50; // Количество итераций

    std::srand(static_cast<unsigned int>(std::time(0))); // Инициализация генератора случайных чисел

    for (int i = 0; i < num_iterations; ++i)
    {
        int arr[array_size];
        generate_random_array(arr, array_size); // Генерация массива случайных чисел

        auto start_time = std::chrono::high_resolution_clock::now(); // Начало измерения времени
        pancake_sort(arr, array_size);                               // Сортировка массива
        auto end_time = std::chrono::high_resolution_clock::now();   // Конец измерения времени

        std::chrono::duration<double> duration = end_time - start_time;                              // Вычисление времени выполнения
        std::cout << duration.count() << std::endl; // Вывод времени выполнения
    }

    return 0;
}
