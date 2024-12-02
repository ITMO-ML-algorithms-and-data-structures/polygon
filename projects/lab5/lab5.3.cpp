//BucketSort (Делит массив на несколько "карманов" (подмассивов) на основе диапазона значений. Каждый карман сортируется отдельным алгоритмом (например, сортировкой вставками))
#include <iostream>
#include <vector>
#include <algorithm> // Для sort
using namespace std;

void bucketSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Находим минимальный и максимальный элемент
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int bucketCount = arr.size(); // Количество "карманов"
    vector<vector<int > > buckets(bucketCount);

    // Распределяем элементы по "карманам"
    for (int num : arr) {
        int idx = (bucketCount * (num - minVal)) / (maxVal - minVal + 1);
        buckets[idx].push_back(num);
    }

    // Сортируем каждый "карман" и собираем результат
    arr.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end()); // Можно заменить сортировкой вставками
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}
