#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class CountVectorizer {
public:

    CountVectorizer(const vector<string>& arr) {
        breakAndAddUnique(arr);
        matrix = createMatrix(arr);
    }

    void printMatrix() const {
        for (const auto& row : matrix) {
            cout << "[";
            for (int number_of_appearings : row) {
                cout << number_of_appearings << " ";
            }
            cout << '\b';
            cout << "]" << endl;
        }
    }
    // Функция для теста: Получает количество уникальных слов
    int GetUniqueWordCount() const {
        return word_index_map.size();
    }

    // Функция для теста: Проверяет, существует ли слово
    bool WordExists(const string& word) const {
        return word_index_map.find(word) != word_index_map.end();
    }

private:
    // Создаем поля (хэш-таблицы) с парами ключ-значение: а) слово-индекс б) индекс-слово
    // Также создаем матрицу N x M

    unordered_map<string, int> word_index_map; // U уникальных слов, L средняя длина слова
    unordered_map<int, string> index_word_map; // U уникальных слов, L средняя длина слова
    vector<vector<int>> matrix; // O(N * M * sizeof(int)), где N - количество строк, M - количество уникальных слов

    /*
    Пишем функцию, берущую на вход вектор из строк, разбивающую каждую по пробелам
    и добавляющую в хэш-таблицу уникальные значения
    */

    void breakAndAddUnique(const vector<string>& arr) {
        int index = 0;

        for (const auto& str : arr) {
            istringstream stream(str);
            string word;

            while (stream >> word) {
                if (word_index_map.find(word) == word_index_map.end()) {
                    word_index_map[word] = index; // O(U * (sizeof(int) + L))
                    index_word_map[index] = word; // O(U * (sizeof(int) + L))
                    index++;
                }
            }
        }
    }

    /*
    Пишем функцию, берущую на вход вектор из строк и преобразующую его в матрицу нулей n X m,
    где n -- кол-во строк в массиве, а m -- кол-во уникальных слов
    */
    vector<vector<int>> createMatrix(const vector<string>& arr) {
        vector<vector<int>> matrix(arr.size(), vector<int>(word_index_map.size(), 0));

        for (int row_index = 0; row_index < arr.size(); ++row_index) {
            istringstream stream(arr[row_index]);
            string word;

            while (stream >> word) {
                if (word_index_map.find(word) != word_index_map.end()) {
                    int word_column_index = word_index_map[word];
                    matrix[row_index][word_column_index]++;
                }
            }
        }

        return matrix;
    }

};

int main() {
    vector<string> arr = {
        "Hello world apple banana !",
        "Hello apple hi",
        "world world Timur",
        "! hi"
    };

    vector<string> arr2 = {
        "What do I do",
        "I do not know",
        "Do not read this",
        "I"
    };

    CountVectorizer cv(arr);
    cv.printMatrix();

    cout << "\n";

    CountVectorizer cv2(arr2);
    cv2.printMatrix();

    /* Память всего:

    O(U * L + N * M * sizeof(int)), где:

    U - количество уникальных слов
    L - средняя длина слова
    N - количество строк (в данном примере 4)
    M - количество уникальных слов (также зависит от U)

    O(6 * 5 + 4 * 6 * sizeof(int)) == O(30 + 96) = O(126)

    */

    return 0;
}
