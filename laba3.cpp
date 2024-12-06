#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> remove_duplicates(const vector<int>& arr) {
    //создание мн-ва - О(1)
    unordered_set<int> seen;  // Множество для отслеживания уже встреченных элементов
    //создание вектора - О(1)
    vector<int> result;       // Массив для хранения результата

    // Прохожу по каждому элементу массива
    //цикл, если длина массива N, то сложность - О(N)
    for (int num : arr) {
        //тоже O(N) за время выполнения всего цикла 
        //if (seen.find(num) == seen.end()) {  // Если элемент еще не встречался
            result.push_back(num);  // Добавляю его в результат О(1)
            seen.insert(num);       // Отмечаю элемент как встреченный О(1)
        //}
    }
    
    return result;
}

int main() {
    int size = 4;
    vector<int> arr = {1, 2, 3, 1};  // Исходный массив

    // Получаю массив без дубликатов
    vector<int> result = remove_duplicates(arr);

    // Вывожу результат
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// итог: О(N)

void test_remove_duplicates() {
    // Тест 1: Пустой массив
    vector<int> arr1 = {};
    vector<int> result1 = remove_duplicates(arr1);
    assert(result1.empty());

    // Тест 2: Массив с уникальными элементами
    vector<int> arr2 = {4, 5, 6, 7};
    vector<int> result2 = remove_duplicates(arr2);
    assert(result2 == arr2);  // Результат должен совпадать с исходным массивом

    // Тест 3: Массив с дубликатами
    vector<int> arr3 = {1, 2, 3, 1};
    vector<int> expected3 = {1, 2, 3};  // Ожидаемый результат
    vector<int> result3 = remove_duplicates(arr3);
    assert(result3 == expected3);

    // Тест 4: Массив с одинаковыми элементами
    vector<int> arr4 = {5, 5, 5, 5};
    vector<int> expected4 = {5};  // Ожидаемый результат
    vector<int> result4 = remove_duplicates(arr4);
    assert(result4 == expected4);

    // Тест 5: Большой массив с дубликатами
    vector<int> arr5 = {1, 2, 3, 1, 2, 3, 4, 5};
    vector<int> expected5 = {1, 2, 3, 4, 5};  // Ожидаемый результат
    vector<int> result5 = remove_duplicates(arr5);
    assert(result5 == expected5);
}

int tests() {
    test_remove_duplicates(); // Запуск тестов

    return 0;
}


