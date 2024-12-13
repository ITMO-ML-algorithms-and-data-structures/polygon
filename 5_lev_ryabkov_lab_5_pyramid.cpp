#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Функция для просеивания элемента вниз по куче
void pyramid(vector<int>& arr, int n, int i)
{
    int largest = i;  // 4 байта // O(1)
    int left = 2 * i + 1;  // 4 байта // O(1)
    int right = 2 * i + 2;  // 4 байта // O(1)

    if (left < n && arr[left] > arr[largest])  // Проверка: O(1), доступ по индексу: O(1)
    {
        largest = left;  // Присвоение: O(1)
    }

    if (right < n && arr[right] > arr[largest])  // Проверка: O(1), доступ по индексу: O(1)
    {
        largest = right;  // Присвоение: O(1)
    }

    if (largest != i)  // Проверка: O(1)
    {
        swap(arr[i], arr[largest]);  // O(1)
        pyramid(arr, n, largest);  // Рекурсивный вызов: O(log n) в худшем случае
    }
    // Итог по памяти: 12 байт (largest, left, right)
    // Итоговая сложность: O(log n) в худшем случае
}

void pyrsort(vector<int>& arr)
{
    int n = arr.size();  // 4 байта // O(1)

    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--)  // Переменная i: 4 байта // O(n)
    {
        pyramid(arr, n, i);  // Вызов pyramid: O(log n)
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i >= 1; i--)  // Переменная i: 4 байта // O(n)
    {
        swap(arr[0], arr[i]);  // O(1)
        pyramid(arr, i, 0);  // Вызов pyramid: O(log n)
    }
    // Итог по памяти: 4 байта (n) + 4 байта (i)
    // Итоговая сложность: O(n log n)
}

int main() {
    int n = 1000;  // 4 байта // O(1)

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt");
    // infile: 152 байта // O(1)

    vector<int> arr(n);
    // arr: 24 байта (объект вектора) + 4 * n байт = 4024 байта // O(n)

    for (int u = 0; u < n; ++u)  // Переменная u: 4 байта // O(n)
    {
        infile >> arr[u];  // Чтение: O(1)
        arr[u] = arr[u] % n;  // Остаток от деления: O(1)
    }

    infile.close();  // Закрытие файла // O(1)
    pyrsort(arr);  // Сортировка // O(n log n)

    for (int i = 0; i < n; ++i)  // Переменная i: 4 байта // O(n)
    {
        cout << arr[i] << " ";  // Вывод элемента // O(1)
    }
    cout << '\n';

    return 0;
    // Итог по памяти: 4 байта (n) + 152 байта (infile) + 4024 байта (arr)
    // Итоговая сложность: O(n log n)
}

// Подсчет памяти:
// 1. n: 4 байта
// 2. ifstream infile: 152 байт
// 3. vector arr: 24 байта (объект вектора) + 4 * n байт (1000 элементов) = 4024 байта
// 4. Внутренние переменные в pyramid: largest (4 байта), left (4 байта), right (4 байта)
// 5. Внутренние переменные в pyrsort: n (4 байта), i (4 байта)
// Общая память: ~ 4200 байт

// Подсчет сложности:
// 1. В main:
//    - Чтение файла: O(n)
//    - Присвоение остатка: O(n)
//    - Вызов pyrsort: O(n log n)
//    - Вывод массива: O(n)
// 2. В pyrsort:
//    - Построение кучи: O(n)
//    - Извлечение из кучи: O(n log n)
// 3. В pyramid:
//    - Вызов рекурсии: O(log n) в худшем случае
// Итоговая сложность: O(n log n)