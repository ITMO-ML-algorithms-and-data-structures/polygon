#include <iostream>
#include <array>
#include <string>
#include <unordered_set>
#include <vector>
#include <list>
#include <unordered_map>

#include <fstream>
#include <sstream>

#include <cassert>

using namespace std;

vector<string> readCSV(const string& filename) {
    // Прочитать строки из таблицы .csv
    // На вход 24 + 12 (примерно) байт
    ifstream file(filename);
    string line; // + 24 байта
    vector<string> data;

    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return {};
    }

    while (getline(file, line)) {
        stringstream sstream(line); // + 50 байт * N
        string value; // + 24 байта * N

        while (getline(sstream, value, ',')) {
            data.push_back(value); // + 24 байта * M * N
        }
    }

    file.close();

    // 24 + 12 + 24 + 50 * N + 24 * N + 24 * N * M = 24 * N * M + 74 * N + 60 байт,
    // где N - количество строк в таблице, M - количество символов в строке

    return data;
}

vector<string> define_unique(vector<string>& arr) {
    // Определить уникальные строки (которые не содержатся в других более длинных)
    // На вход (24 + M) * N байт
    unordered_set<string> unique;

    int size = arr.size(); // + 4 байта

    for (int i = 0; i < size; i ++) {
        bool flag = true; // + 1 байт * N

        for (int j = 0; j < size; j ++) {
            if ((arr[i].find(arr[j]) != string::npos) && (i != j) && (arr[i] != arr[j])) {
                flag = false;
                break;
            }
        }
        
        if (flag && (unique.find(arr[i]) == unique.end()))
            unique.insert(arr[i]); // + M * K байт
    }

    vector<string> out(unique.begin(), unique.end()); // + (24 + M) * K байт

    // (24 + M) * N + 4 + 1 * N + M * K + (24 + M) * K = (24 + M) * (N + K) + M * K + N + 4 байт,
    //  где N - количество строк в массиве, M - условно среднее количество букв в строке, K - количество уникальных слов

    return out;
}

int countSubstring(const std::string& text, const std::string& substring) {
    // Подсчёт количества вхождений подстроки в строку
    // На вход 24 + N + 24 + M байт
    int count = 0; // + 4 байта
    size_t pos = text.find(substring); // + 8 байт

    while (pos != std::string::npos) {
        count ++;
        pos = text.find(substring, pos + substring.length());
    }

    // 24 + N + 24 + M + 4 + 8 = N + M + 60 байт,
    // где N - длина строки, M - длина подстроки

    return count;
}

unordered_map<string, list<int>> vectorize(string filename) {
    // Непосредственно векторизация
    // На вход 24 + 12 байт
    vector<string> arr = readCSV(filename); // (24 + M) * N байт
    vector<string> unique_words = define_unique(arr); // (24 + M) * K байт

    const int unique_words_num = unique_words.size(); // + 4 байт

    unordered_map<string, list<int>> vec_table;

    for (auto& word : arr) {
        list<int> tmp_arr;

        for (int i = 0; i < unique_words_num; i ++) {
            tmp_arr.push_back(countSubstring(word, unique_words[i])); // + 4 * K байт
        }

        vec_table[word] = tmp_arr; // + 4 * K * N байт
    }

    // 24 + 12 + (24 + M) * N + (24 + M) * K + 4 + 4 * K + 4 * K * N = 4 * K * N + (24 + M) * (N + K) + 4 * K + 40 байт,
    // где N - количество строк в массиве, M - условно среднее количество букв в строке, K - количество уникальных слов

    return vec_table;
}

void test() {
    unordered_map<string, list<int>> vec_table1;

    vec_table1["1      e"] = {1, 0, 0, 0, 0};
    vec_table1["1      e"] = {1, 0, 0, 0, 0};
    vec_table1["1      e"] = {1, 0, 0, 0, 0};
    vec_table1["xA 8  0k"] = {0, 1, 0, 0, 0};
    vec_table1["fd        KPO"] = {0, 0, 0, 0, 1};
    vec_table1["y"] = {0, 0, 1, 0, 0};
    vec_table1["fd        KPO"] = {0, 0, 0, 0, 1};
    vec_table1["y"] = {0, 0, 1, 0, 0};
    vec_table1["N"] = {0, 0, 0, 1, 0};
    vec_table1["xA 8  0k"] = {0, 1, 0, 0, 0};

    unordered_map<string, list<int>> vec_table1_processed = vectorize("dataset1.csv");

    assert(vec_table1 == vec_table1_processed);

    unordered_map<string, list<int>> vec_table2_processed = vectorize("dataset2.csv");

    // for (auto& pair : vec_table2_processed) {
    //     for (auto& value : pair.second)
    //         cout << value << " ";
    //     cout << endl;
    // }

    //unordered_map<string, list<int>> vec_table3 = {"a", "b", "c", "ab", "bc", "aabbcc"};
    unordered_map<string, list<int>> vec_table3_processed = vectorize("dataset3.csv");

    for (auto& pair : vec_table3_processed) {
        cout << pair.first << "     ";
        for (auto& value : pair.second)
            cout << value << " ";
        cout << endl;
    }

    cout << "test completed!" << endl;
}

int main() {
    test();

    return 0;
}

