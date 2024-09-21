#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<int>> countVectorizer(const vector<string>& arr) {
    // Словарь: уникальное слово - его индекс
    unordered_map<string, int> wordIndex;
    int index = 0;
    string line;
    char ch;
    // Заполнение словаря
    for (int i = 0; i < arr.size(); i++) {
        line = arr[i];
        string word;
        for (int j = 0; j < line.size(); j++) {
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

    // Заполняем массив количеством вхождений
    for (int i = 0; i < arr.size(); i++) {
        string word;
        for (int j = 0; j < arr[i].size(); j++) {
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
}

int main() {
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
    // Алгоритмическая сложность по времени: O(n*k), n - кол-во строк, k - кол-во символов в строке
    // по памяти: словарь O(m), m - кол-во уникальных слов + двумерный массив O(n * m)
}
