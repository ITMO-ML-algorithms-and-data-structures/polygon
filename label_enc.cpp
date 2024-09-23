#include "label_enc.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;
vector<int> label_encoder (string path) {
    ifstream file(path);

    string line;
    int u_element_number = 0;
    unordered_map<string, int> label_enc;
    vector<string> mas_word;

    if (getline(file, line)) {
        istringstream stream(line);
        string word;
        while (stream >> word) {
            mas_word.push_back(word);
        }
    }
    vector<int> label(mas_word.size());
    for (int i = 0; i < mas_word.size(); i++) {
        if (not label_enc.contains(mas_word[i])) {
            label_enc[mas_word[i]] = u_element_number + 1;
            u_element_number++;
        }
        label[i] = label_enc[mas_word[i]];
    }

    file.close();
    return label;
}

int main() {
    vector<int> label = label_encoder("test_dir/test_3.txt");
    for (int i = 0; i < label.size(); i++) {
        cout <<label[i] << ", ";
    }

    return 0;
}