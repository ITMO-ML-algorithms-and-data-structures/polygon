#include <iostream>
#include <vector>
#include <cassert>
#include <chrono> // Для измерения времени
using namespace std;
using namespace chrono;

// Функция для поиска подмассивов с суммой 0
vector<vector<int>> findZeroSumSubarrays(const vector<int>& arr, int K) {
    int N = arr.size();
    vector<vector<int>> results;

    // Перебираю все возможные подмассивы длины K
    for (int i = 0; i <= N - K; ++i) {
        int sum = 0;

        // Для текущего подмассива длины K вычисляю сумму
        for (int j = i; j < i + K; ++j) {
            sum += arr[j];
        }

        // Если сумма равна нулю, сохраняю индексы
        if (sum == 0) {
            vector<int> indices;
            for (int j = i; j < i + K; ++j) {
                indices.push_back(j);
            }
            results.push_back(indices);
        }
    }

    return results;
}

void runTest(const vector<int>& arr, int K, int expectedResult) {
    auto start = high_resolution_clock::now();
    vector<vector<int>> result = findZeroSumSubarrays(arr, K);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);  // Измеряю в микросекундах

    cout << "Found " << result.size() << " subarrays with sum 0." << endl;

    // Проверяю количество подмассивов
    assert(result.size() == expectedResult); 
    cout << "Test passed in " << duration.count() / 1000000.0 << " seconds." << endl;
}

void runTests() {
    // Тест 1: Нет подмассивов с суммой 0
    vector<int> arr1 = {1, 2, 3, 4, 5};
    runTest(arr1, 2, 0); // Ожидается 0 подмассивов с суммой 0

    // Тест 2: Подмассив с суммой 0 существует
    vector<int> arr2 = {1, -1, 2, -2, 0};
    runTest(arr2, 2, 2); // Ожидается 2 подмассива с суммой 0

    // Тест 3: Один элемент с суммой 0
    vector<int> arr3 = {0};
    runTest(arr3, 1, 1); // Ожидается 1 подмассив с суммой 0

    // Тест 4: Массив из всех нулей
    vector<int> arr4 = {0, 0, 0, 0};
    runTest(arr4, 4, 1); // Ожидается 1 подмассив с суммой 0

    // Тест 5: Массив длиной меньше K
    vector<int> arr5 = {1, 2, 3};
    runTest(arr5, 4, 0); // Не может быть подмассива длиной 4 в массиве длиной 3

    // Дополнительные тесты для различных длин массивов

    // Тест 6: Массив с 1 элементом
    vector<int> arr6 = {0};
    runTest(arr6, 1, 1); // Ожидается 1 подмассив с суммой 0

    // Тест 7: Массив из 5 элементов
    vector<int> arr7 = {1, -1, 0, 0, 0};
    runTest(arr7, 2, 3); // Ожидается 3 подмассива с суммой 0

    // Тест 8: Массив из 10 элементов
    vector<int> arr8 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    runTest(arr8, 5, 6); // Ожидается 6 подмассивов с суммой 0

    // Тест 9: Массив из 15 элементов
    vector<int> arr9 = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1};
    runTest(arr9, 4, 12); // Ожидается 12 подмассивов с суммой 0

    // Тест 10: Массив из 20 элементов
    vector<int> arr10 = {0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 0};
    runTest(arr10, 6, 5); // Ожидается 5 подмассивов с суммой 0

    // Тест 11: Массив из 25 элементов
    vector<int> arr11 = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10, 11, -11, 12, -12, 13};
    runTest(arr11, 3, 12); // Ожидается 12 подмассивов с суммой 0

    cout << "All tests passed!" << endl;
}

// Функция для измерения времени выполнения
void measureExecutionTime() {
    auto start = high_resolution_clock::now();
    runTests(); // Запуск тестов
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Total execution time: " << duration.count() / 1000000.0 << " seconds" << endl;
}

int main() {
    measureExecutionTime();
    return 0;
}

