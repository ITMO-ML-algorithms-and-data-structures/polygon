#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    int len_str1;
    cin >> str1 >> str2;
    map<char, char> alpha;
    vector<char> alredy_in_map;
    len_str1 = str1.size();


    if (str1.size() != str2.size()) { //проверка на равномощность 
        cout << "False";
        return 0;
    }


    for (int i = 0; i <= len_str1; i++) { 
        if (alpha.count(str1[i])) { //есть ли в словаре
            if (alpha[str1[i]] != str2[i]) { //если уже есть и не совпадает, то -
                cout << "False";
                return 0;
            }
        }
        else {
            if (std::count(alredy_in_map.begin(), alredy_in_map.end(), str2[i])) { //проверка был ли элемент 
                cout << "False";
                return 0;
            }

            alpha[str1[i]] = str2[i]; //добавление в словарь
            alredy_in_map.push_back(str2[i]); //добавление значения в словарь 
        }
    }
    cout << "True";




    return 0;
}
