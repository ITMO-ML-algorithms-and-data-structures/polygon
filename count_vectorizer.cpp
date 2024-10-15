#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// cout << sizeof(_) << endl;

int main() {
    ifstream infile("dataset2.txt");  // 520

    vector<string> array;  // 24 (3 указателя)
    string line;  // 32

    // После заполнения array, память будет 24 + 32*колвострок байт + длинавсехстрок
    while (getline(infile, line)) {
        if (!line.empty()) {
            array.push_back(line);
        }
    }
    infile.close();

    int arr_size = array.size();  // 4, должно хватать
    unordered_map<string, int> word_to_index;  // 48
    int current_word_index;  // 4

    // После цикла word_to_index будет 48 + 58*колвослов + длинауникалслов
    for (const auto& line : array) {
        istringstream iss(line);  // 32
        string word;  // 32

        while (iss >> word) {
            if (word_to_index.find(word) == word_to_index.end()) {
                word_to_index[word] = current_word_index++;
            }
        }
    }

    // 24 + 24*arr_size + arr_size*current_word_index*4
    vector<vector<int>> counts(arr_size, vector<int>(current_word_index, 0));

    for (int i = 0; i < arr_size; ++i) {
        istringstream iss(array[i]);  // 32

        string word;  // 32

        while (iss >> word) {
            int idx = word_to_index[word];  // 4
            counts[i][idx]++;
        }
    }

    for (int i = 0; i < arr_size; ++i) {
        cout << "[";
        for (int j = 0; j < current_word_index; ++j) {
            cout << counts[i][j];
            if (j < current_word_index - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
