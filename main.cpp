#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<vector<int>> CountVectorizer(const vector<string>& arr) {
    unordered_map<string, vector<int>> words_slov;
    int index = 0; //4 байта
    for (int i = 0; i < arr.size(); i++) {
        //4 байта
        string word; // 100 байт
        for (auto& letter : arr[i]) {
            if (letter == ' ') {
                if (!word.empty()) {
                    words_slov[word].push_back(index);
                    word.clear();
                }
            } else{
                word += letter;
            }
        }
        if (!word.empty()) {
            words_slov[word].push_back(index);
        }
        index++;
    }


    // for (auto& [word, index] : words_slov) {
    //     cout << word << " ";
    //     for (auto& id : index) {
    //         cout << id << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> matrix(arr.size(), vector<int>(words_slov.size(), 0));
    int row = words_slov.size()-1; //4 байта
    for (auto& [word, index] : words_slov) {
        for (auto& id: index) {
            matrix[id][row] += 1;
        }
        row--;
    }
    return matrix;
}

void tests() {
    vector<string> arr1 = {"Hello world !", "Hello", "world", "!"};
    vector<vector<int>> ans1 = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> res1 = CountVectorizer(arr1);
    assert(res1 == ans1);

    vector<string> arr2 = {"Hello world, Hello Nina, Hello Lensoveta"};
    vector<vector<int>> ans2 = {{3, 1, 1, 1}};
    vector<vector<int>> res2 = CountVectorizer(arr2);
    assert(res2 == ans2);

    vector<string> arr3 = {"  "};
    vector<vector<int>> ans3 = {{}};
    vector<vector<int>> res3 = CountVectorizer(arr3);
    assert(res3 == ans3);

    vector<string> arr4 = {"I don't like    a cat", "I   love dog", "I love mum"};
    vector<vector<int>> ans4 = {{1, 1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}};
    vector<vector<int>> res4 = CountVectorizer(arr4);
    assert(res4 == ans4);

    vector<string> arr5 = {"Star      Ship", "Ship", "  Ship", "Ship     " };
    vector<vector<int>> ans5 = {{1, 1}, {0, 1}, {0, 1}, {0, 1}};
    vector<vector<int>> res5 = CountVectorizer(arr5);
    assert(res5 == ans5);

    vector<string> arr6 = {"       ", "  ", "     ", "      " };
    vector<vector<int>> ans6 = {{}, {}, {}, {}};
    vector<vector<int>> res6 = CountVectorizer(arr6);
    assert(res6 == ans6);

    cout << "Yappie, all tests passed!" << endl;
}

int main() {
    //Потоковый ввод
    vector<string> arr;
    string line;
    while(getline(cin,line))
    {
        if (line.empty())
            break;
        arr.push_back(line);
    }

    for (auto& x : arr) {
        cout << x << endl;
    }

    //vector<string> arr = {"Hello world, Hello Nina, Hello Lensoveta", "Lensoveta - the best dormitory"};;
    vector<vector<int>> result = CountVectorizer(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            if (j != result[i].size()-1) {
                cout << result[i][j] << ", ";
            } else {
                cout << result[i][j];
            }
        }
        cout << "]";
        cout << endl;
    }
    tests();
}

//Сложность можно оценить как O(n * m + n + k * p + n * k).
//Если считать, что количество уникальных слов k - до 1е2
//среднее количество вхождений p - до 100
//количество строк n - до 1e4, а длина строки l - до 1е2
//сложность разбивания строк на слова и добавление в контейнер = O(n * m)
//cложность формирования матрицы будет O(k * p)
//Вывод матрицы: Проход по элементам матрицы занимает O(n * k)
//итого: O(n * m + k * p + n * k)

//Хранение строк: Для хранения строк используется O(n * m) памяти
//Хранение unordered_map: для хранения слов в unordered_map потребуется O(k * p)
//Матрица: Матрица имеет размер n x k, что требует O(n * k) памяти
//Итого: O(n*m + k*p, n*k + 4*3 байт + 100)
