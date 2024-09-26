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
    int unique_index = 0;
    unordered_map<string, int> label_map;
    vector<int> label;
    if (getline(file, line)) {
        istringstream stream(line);
        string word;
        while (stream >> word) {
            if (not label_map.contains(word)) {
                label_map[word] = unique_index + 1;
                unique_index++;
            }
            label.push_back(label_map[word]);
        }
    }

    file.close();
    return label;
}

int main() {
    vector<int> label = label_encoder("test_dir/test_4.txt");
    for (int i = 0; i < label.size(); i++) {
        cout <<label[i] << ", ";
    }

    return 0;
}