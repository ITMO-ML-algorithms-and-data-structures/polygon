#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void bucketSort(vector<int>& arr) {

    int maxElement = *max_element(arr.begin(), arr.end());
    // maxElement: 4 байта // O(n) для поиска максимального элемента

    int bucketCount = arr.size();
    // bucketCount: 4 байта // O(1)

    vector<vector<int> > buckets(bucketCount);
    // buckets: 
    // 24 байта (на объект вектора) + bucketCount * 24 байта (пустые внутренние векторы)
    // Если каждый внутренний вектор в среднем заполняется n / bucketCount элементами:
    // Общее: ~ bucketCount * 24 байта + n * 4 байта // O(n)

    for (int i = 0; i < arr.size(); i++) // Переменная i: 4 байта // O(n)
    {
        int index = (arr[i] * bucketCount) / (maxElement + 1);
        // index: 4 байта // O(1)
        buckets[index].push_back(arr[i]);
        // Добавление в вектор: O(1) амортизированное
    }

    for (int i = 0; i < bucketCount; i++) // Переменная i: 4 байта // O(bucketCount)
    {
        sort(buckets[i].begin(), buckets[i].end());
        // Сортировка каждого внутреннего вектора:
        // Если в каждом векторе в среднем n / bucketCount элементов:
        // O((n / bucketCount) * log(n / bucketCount)) для одного вектора
        // Итог: O(n * log(n / bucketCount))
    }

    int index = 0;
    // index: 4 байта // O(1)
    for (int i = 0; i < bucketCount; i++) // Переменная i: 4 байта // O(bucketCount)
    {
        for (int j = 0; j < buckets[i].size(); j++) // Переменная j: 4 байта // O(n)
        {
            arr[index++] = buckets[i][j];
            // Присвоение: O(1)
        }
    }
    // Итог по памяти: 4 байта (maxElement) + 4 байта (bucketCount) + память под buckets 
    // Общая сложность: O(n + n * log(n / bucketCount))
}

int main()
{
    int n = 1000;
    // n: 4 байта // O(1)

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt");
    // infile: 152 байта // O(1)

    vector<int> arr(n);
    // arr: 24 байта (объект вектора) + 4 * n байт = 4024 байта // O(n)

    for (int u = 0; u < n; ++u) // Переменная u: 4 байта // O(n)
    {
        infile >> arr[u]; // Чтение: O(1)
        arr[u] = (arr[u] % 1000); // Остаток от деления: O(1)
    }

    infile.close(); // Закрытие файла // O(1)
    bucketSort(arr); // Сортировка // O(n + n * log(n / bucketCount))

    for (int i = 0; i < n; i++) // Переменная i: 4 байта // O(n)
    {
        cout << arr[i] << " "; // Вывод элемента // O(1)
    }
    cout << '\n';

    return 0;
    // Итог по памяти: 4 байта (n) + 152 байта (infile) + 4024 байта (arr)
    // + память под buckets
    // Итоговая сложность: O(n + n * log(n / bucketCount))
}

// Подсчет памяти:
// 1. n: 4 байта
// 2. ifstream infile: 152 байт
// 3. vector arr: 24 байта (объект вектора) + 4 * n байт (1000 элементов) = 4024 байта
// 4. buckets: ~ bucketCount * 24 байта + n * 4 байта
// 5. Внутренние переменные:
//    - maxElement: 4 байта
//    - bucketCount: 4 байта
//    - index: 4 байта
//    - i, j: 4 + 4 = 8 байт
// Общая память: ~ 4200 байт + память для buckets

// Подсчет сложности:
// 1. В main:
//    - Чтение файла: O(n)
//    - Присвоение остатка: O(n)
//    - Вызов bucketSort: O(n + n * log(n / bucketCount))
//    - Вывод массива: O(n)
// 2. В bucketSort:
//    - Создание buckets: O(n)
//    - Заполнение buckets: O(n)
//    - Сортировка buckets: O(n * log(n / bucketCount))
//    - Сборка из buckets: O(n)
// Итоговая сложность: O(n + n * log(n / bucketCount))