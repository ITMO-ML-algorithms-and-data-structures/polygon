#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;
using namespace std::chrono; 


void bucketSort(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    // Создаем k ведер
    vector<vector<int>> buckets(k);

    // Находим минимальный и максимальный элемент
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    // Если все элементы массива одинаковы, массив уже отсортирован
    if (minValue == maxValue) {
        return;
    }

    // Распределяем элементы в ведра
    for (int i = 0; i < n; i++) {
        int bucketIndex = ((arr[i] - minValue) * (k - 1)) / (maxValue - minValue); // Индекс ведра
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Сортируем элементы в каждом ведре
    for (int i = 0; i < k; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Объединяем отсортированные элементы из ведер
    int index = 0;
    for (int i = 0; i < k; i++) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }
}


// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Юнит-тесты
void testBucketSort() {
    const int defaultK = 5; // Значение по умолчанию для количества ведер

    setlocale(LC_ALL, "RU");
    // Тестовые данные
    vector<pair<string, vector<int>>> testCases = {
        {"Пустой массив", {}},
        {"Один элемент", {42}},
        {"Уже отсортированный массив", {1, 2, 3, 4, 5}},
        {"Обратно отсортированный массив", {5, 4, 3, 2, 1}},
        {"Случайный массив", {3, 1, 4, 1, 5, 9, 2, 6, 5}},
        {"Массив с повторяющимися элементами", {10, 7, 7, 3, 2, 2, 5, 7}}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Тест " << i + 1 << ": " << testCases[i].first << endl;

        vector<int> arr = testCases[i].second;
        cout << "Исходный массив: ";
        printArray(arr);

        // Определяем количество ведер
        int k = defaultK;
        if (!arr.empty()) {
            k = max(1, min((int)sqrt(arr.size()), (int)arr.size()));
        }

        // Замер времени выполнения
        auto start = high_resolution_clock::now();
        bucketSort(arr, k);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        // Вывод результата
        cout << "Отсортированный массив: ";
        printArray(arr);
        cout << "Количество ведер: " << k << endl;
        cout << "Время выполнения: " << duration.count() << " микросекунд" << endl;

        // Проверка корректности сортировки
        assert(is_sorted(arr.begin(), arr.end()));
        cout << "Тест успешно пройден!" << endl << endl;
    }
}

int main() {
    // Запуск юнит-тестов
    testBucketSort();
    return 0;
}

//асимптотическая сложность по памяти: О(n). Потребление памяти линейно зависит от количества элементов во входном массиве.
//по времни: в худшем случае: O(n log n) (например, если все элементы попадают в одно ведро), в среднем случае: O(n) (если элементы распределены равномерно по ведрам).