#include <bits/stdc++.h>
#include <cassert>
using namespace std;

// Функция для поиска всех подмассивов размера K с суммой элементов равной 0
vector<vector<int>> findZeroSumSubarrays(const vector<int>& arr, int K) { // O(N^K) временная сложность
    int N = arr.size();
    vector<vector<int>> result; // Хранение найденных комбинаций индексов

    // Рекурсивная функция для генерации комбинаций
    function<void(int, int, vector<int>, int)> backtrack = [&](int start, int depth, vector<int> current, int currentSum) {
        if (depth == K) { // Базовый случай: комбинация размера K
            if (currentSum == 0) { // Проверка, равна ли сумма нулю
                result.push_back(current); // Добавление комбинации в результат, если сумма равна нулю
            }
            return;
        }
        for (int i = start; i < N; ++i) { // Итерация по элементам массива
            current.push_back(i); // Выбор текущего индекса
            backtrack(i + 1, depth + 1, current, currentSum + arr[i]); // Рекурсия с следующим индексом
            current.pop_back(); // Откат (backtrack)
        }
    };

    backtrack(0, 0, {}, 0); // Инициализация рекурсии
    return result;
}

int main() { // Главная функция
    // Тест 1: Маленький массив
    vector<int> arr1 = {1, -1, 2, -2, 3};
    int K1 = 2;
    vector<vector<int>> result1 = findZeroSumSubarrays(arr1, K1);
    assert(result1.size() == 2); // Существует два подмассива размера 2 с суммой 0: {0, 1}, {2, 3}
    
    // Проверка
    vector<vector<int>> expected1 = {{0, 1}, {2, 3}};
    assert(result1 == expected1);

    // Тест 2: Большой K, чтобы увидеть разницу во времени работы
    vector<int> arr2 = {1, -1, 2, -2, 3, -3};
    int K2 = 4;
    vector<vector<int>> result2 = findZeroSumSubarrays(arr2, K2);
    assert(result2.size() == 3); // Существует три подмассива размера 4 с суммой 0

    // Проверка
    vector<vector<int>> expected2 = {{0, 1, 2, 3}, {0, 1, 4, 5}, {2, 3, 4, 5}};
    assert(result2 == expected2);

    cout << "Все тесты пройдены успешно!" << endl;

    return 0;
}