#include <cassert>
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


using namespace std;
void TestLabelEnc() {
    vector<int> test_1 {1, 2, 3, 2, 4, 2, 1};
    vector<int> test_2 {1, 2, 3, 1, 4, 5, 6, 7, 8, 9, 10, 7, 11, 12, 13, 14, 15, 14, 4, 16, 17, 7, 18, 15, 16, 16, 9, 19, 20, 21, 22, 23, 24, 12, 9, 25, 1, 26, 9, 16, 1, 27, 22, 28, 29, 30, 7, 2, 26, 31, 26, 20, 32, 2, 7, 33, 34, 17, 35, 15, 36, 6, 21, 35, 21, 14, 20, 37, 7, 22, 2, 19, 11, 18, 32, 20, 33, 10, 20, 1, 1, 4, 19, 38, 29, 12, 20, 30, 18, 4, 11, 37, 17, 35, 19, 4, 18, 6, 30, 34, 35, 38, 34, 32, 28, 32, 20, 32, 26, 33, 19, 12, 11, 27, 7, 9, 27, 37, 38, 8, 4, 32, 7, 11, 22, 25, 13, 16, 32, 4, 31, 11, 28, 30, 5, 18, 25, 11, 3, 11, 23, 21, 23, 16, 5, 5, 9, 28, 20, 1};
    vector<int> test_3 {1, 2, 3, 4, 5, 1, 5, 6, 2, 7, 7, 1, 2, 7, 6, 8, 5, 3, 7, 1, 3, 9, 6, 7, 7, 4, 4, 6, 1, 10, 6, 6, 4, 3, 8, 10, 8, 5, 8, 3, 4, 9, 6, 10, 5, 8, 5, 2, 4, 5};
    vector<int> test_4 {1, 1, 1, 1, 1, 2, 1, 2, 3, 3, 3, 3, 3, 1, 2, 1, 2, 2, 2, 2, 2};
    vector<int> test_empty {};
    vector<int> test_same {1, 1, 1, 1, 1, 1, 1};
    assert(label_encoder("test_dir/test.txt") == test_1);
    assert(label_encoder("test_dir/test_2.txt") == test_2);
    assert(label_encoder("test_dir/test_3.txt") == test_3);
    assert(label_encoder("test_dir/test_4.txt") == test_4);
    assert(label_encoder("test_dir/test_empty.txt") == test_empty);
    assert(label_encoder("test_dir/test_same.txt") == test_same);
    cout << "Ok" << endl;
}

int main() {
    TestLabelEnc();
    return 0;
}