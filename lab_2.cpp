#include <functional>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


#define uint8 short int


vector<short int> LabelEncoder(string dataset_path) {
    string line;
    ifstream in(dataset_path);
    vector<short int> answer(0);
    unordered_map<string, short int> map;

    if (in.is_open()) {
        while (getline(in, line)) {
            if (map[line] == 0) map[line] = (short int)map.size();
            answer.push_back(map[line]);
        }
    }
    in.close();
    return answer;
}


int main() {
    auto answer = LabelEncoder("/Users/danil/PLUSPLUS/polygon/test.txt");
    for (auto i : answer) cout << i << '\n';
}