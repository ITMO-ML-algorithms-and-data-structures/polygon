#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res; // 24 байта + size * 4 байта


    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start); // 24 байта
        pos_start = pos_end + delim_len; // 24 байта
        res.push_back(token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

//функция проверки вхождения ключа в map
bool containsKey(const map<char, char>& myMap, char key) {
    return myMap.find(key) != myMap.end();
}


string isostrings(const string& filename) {
    string line; // 24 байта
    string result; // 24 байта

    ifstream file(filename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            bool flag = true; // 1 байт
            vector<string> data = split(line, " "); // 24 байта
            map<char, char> words; // 24 байта
            for (int i = 0; i < data[0].size(); i++) {
                if (containsKey(words, data[0][i]) ) {
                    if (words[data[0][i]] != data[1][i]) {
                        flag = false;
                        break;
                    }
                }
                else {
                    words[data[0][i]] = data[1][i];
                }
            }
            if (flag) {
                for (int i = 0; i < data.size(); i++) {
                    result += data[i] + " ";
                }
                result += "-> изоморфная строка \n";
            }else {
                for (int i = 0; i < data.size(); i++) {
                    result += data[i] + " ";
                }
                result += "-> не изоморфная строка \n";
            }
        }
    }
    file.close();
    return result; // 24 байта
}