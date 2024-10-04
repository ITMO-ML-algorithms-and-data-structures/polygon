#include <iostream> 
#include <fstream> 
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

bool areIsomorphic(const string &str1, const string &str2) { 
        if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, char> mapping1;
    unordered_map<char, char> mapping2;

    for (size_t i = 0; i < str1.length(); ++i) {
        char char1 = str1[i];
        char char2 = str2[i];

        if (mapping1.count(char1)) {
            if (mapping1[char1] != char2) {
                return false;
            }
        } else {
            mapping1[char1] = char2;
        }

        if (mapping2.count(char2)) {
            if (mapping2[char2] != char1) {
                return false;
            }
        } else {
            mapping2[char2] = char1;
        }
    }

    return true;
}

// не получается сгенерить файл с разделителем пробелом ААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААА

bool checkIsomorphismFromFile(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return false;
    }

    string line;
    if (getline(file, line)) {
        istringstream inputString(line);
        string str1, str2;
        if (inputString >> str1 >> str2) {
            return areIsomorphic(str1, str2);
        }
    }

    return false;
}

int main() {
    string filePath = "";
    bool result = checkIsomorphismFromFile(filePath);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
