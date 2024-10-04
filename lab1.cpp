#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<vector<int>> countVectorizer(const vector<string>& arr) {
    // Словарь: уникальное слово - его индекс
    unordered_map<string, int> wordIndex; // + (100+4)*100=10400 байта
    int index = 0; // + 4 байта
    string line; // + 100 байт
    char ch; // + 1 байт
    // Заполнение словаря
    for (int i = 0; i < arr.size(); i++) {
        // + 4 байта
        line = arr[i];
        string word; // + 100 байт
        for (int j = 0; j < line.size(); j++) {
            // + 4 байта
            ch = line[j];
            if (ch == ' ') {
                if (!word.empty()) {
                    // если слова еще нет в словаре
                    if (wordIndex.find(word) == wordIndex.end()) {
                        wordIndex[word] = index;
                        index++;
                    }
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        // Добавляем последнее слово
        if (!word.empty()) {
            if (wordIndex.find(word) == wordIndex.end()) {
                wordIndex[word] = index++;
            }
        }
    }

    // Создаем двумерный массив для хранения количества вхождений каждого уникального слова - результат
    // Количество строк в массива совпадает с размерностью количества входных строк
    // Количество столбцов с размерностью количества уникальных слов
    // По дефолту заполняем нулями
    vector<vector<int>> countMatrix(arr.size(), vector<int>(wordIndex.size(), 0));
    // Максимум 1e4 строк (всего входных строк) * 1e2 столбцов (уникальных слов) * 4 байта (каждый элемент это int)
    // + 4000000 байта

    // Заполняем массив количеством вхождений
    for (int i = 0; i < arr.size(); i++) {
        // + 4 байта
        string word; // + 100 байт
        for (int j = 0; j < arr[i].size(); j++) {
            // + 4 байта
            ch = arr[i][j];
            if (ch == ' ') {
                if (!word.empty()) {
                    countMatrix[i][wordIndex[word]]++;
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        // Обрабатываем последнее слово
        if (!word.empty()) {
            countMatrix[i][wordIndex[word]]++;
        }
    }

    return countMatrix;
    // Алгоритмическая сложность по времени: O(n*k), n - кол-во строк, k - кол-во символов в строке
    // Затраты по памяти: 4010721 байт
}


void testCountVectorizer() {
    // Тест 1: тест из примера
    vector<string> input1 = {"Hello world !", "Hello", "world", "!"};
    vector<vector<int>> expected1 = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> result1 = countVectorizer(input1);
    assert(result1 == expected1);

    // Тест 2: пустая строка
    vector<string> input2 = {""};
    vector<vector<int>> expected2 = {{}};
    vector<vector<int>> result2 = countVectorizer(input2);
    assert(result2 == expected2);

    // Тест 3: строка с одинаковыми словами
    vector<string> input3 = {"Hello Hello Hello"};
    vector<vector<int>> expected3 = {{3}};
    vector<vector<int>> result3 = countVectorizer(input3);
    assert(result3 == expected3);

    // Тест 4: несколько уникальных слов
    vector<string> input4 = {"apple banana", "banana apple apple", "apple"};
    vector<vector<int>> expected4 = {{1, 1}, {2, 1}, {1, 0}};
    vector<vector<int>> result4 = countVectorizer(input4);
    assert(result4 == expected4);

    // Тест 5: слова с разными пробелами
    vector<string> input5 = {"   Hello   world   !   ", "Hello"};
    vector<vector<int>> expected5 = {{1, 1, 1}, {1, 0, 0}};
    vector<vector<int>> result5 = countVectorizer(input5);
    assert(result5 == expected5);

    cout << "Tests passed" << endl;
}


int main() {
    // Прогон тестов
    testCountVectorizer();

    // Пример использования функции
    // Вход
    int size = 4;
    vector<string> arr = {"Hello world !", "Hello", "world", "!"};

    // Выход
    vector<vector<int>> result = countVectorizer(arr);
    vector<int> row;
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        row = result[i];
        for (size_t j = 0; j < row.size(); j++) {
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
