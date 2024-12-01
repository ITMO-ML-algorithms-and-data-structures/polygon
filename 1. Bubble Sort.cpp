#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Функция для печати массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для проверки корректности сортировки с выводом результатов
void testBubbleSort() {
    setlocale(LC_ALL, "RU");
    // Тестовые случаи
    vector<pair<string, vector<int>>> testCases = {
        {"Пустой массив", {}},
        {"Отсортированный массив", {1, 2, 3, 4, 5}},
        {"Неотсортированный массив", {5, 1, 4, 2, 8}},
        {"Массив с повторяющимися элементами", {3, 1, 4, 1, 5, 9, 2, 6, 5}}
    };

    // Ожидаемые результаты
    vector<vector<int>> expectedResults = {
        {},
        {1, 2, 3, 4, 5},
        {1, 2, 4, 5, 8},
        {1, 1, 2, 3, 4, 5, 5, 6, 9}
    };

    // Проход по каждому тестовому случаю
    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Тест " << i + 1 << ": " << testCases[i].first << endl;
        vector<int> arr = testCases[i].second;

        // Замер времени
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        // Проверка корректности
        assert(arr == expectedResults[i]);
        cout << "Исходный массив: ";
        printArray(testCases[i].second);
        cout << "Отсортированный массив: ";
        printArray(arr);
        cout << "Время выполнения: " << duration.count() << " микросекунд" << endl;
        cout << "Тест успешно пройден!\n" << endl;
    }
}

int main() {
    // Вызов функции для тестирования
    testBubbleSort();
    return 0;
}


//итоговый подсчёт по памяти: 4 * n + C, где n - кол-во элементов в массиве, С - константа, отражающая потребление памяти переменными
// Асимптотическая сложность в худшем и среднем случаях составляет O(n^2).
// Асимптотическая сложность в лучшем случае(массив уже отсортирован) составляет O(n).

