#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

bool is_it_value(unordered_map<char, char> biection, char curr_value) {

    for (const auto& [key, value] : biection) {
        if (value == curr_value) {
            return true;
        }
    }
    return false;
}

bool isIsomorphic(string str1, string str2) {

    unordered_map<char, char> biection;

    //1 (char по 1 байту) * n + 1 * n + хранение цепочек 
    //+ незначительные затраты на хэш-функцию + 8 байт на указатель (64-битная)

    int size1 = str1.size();

    if (size1 != str2.size()) {
        return false;
    }

    //проходим по элементам строки и проверяем,
    //можно ли построить биекцию между элементами двух строк

    for (size_t i = 0; i != size1; ++i) {
        char curr_el1 = str1[i];
        char curr_el2 = str2[i];


        //если элемента из строки 1 нет в ключах,
        //то проверяем есть ли элемент из строки 2 в значениях или нет
        //по сути проверка на инъективность нашего отображения

        if (biection.find(curr_el1) == biection.end()) {
            if (!is_it_value(biection, curr_el2)) {
                biection[curr_el1] = curr_el2;
            }
            else {
                return false;
            }

        //если такой ключ уже есть,
        //то проверяем не сопоставлено ли ему какое-то другое значение

        }
        else {
            if (biection[curr_el1] != curr_el2) {
                return false;
            }
        }
    }

    return true;
}

void Test_isIsomorphic() {

    assert(isIsomorphic("egg", "add"));
    assert(!isIsomorphic("e", "bb"));
    assert(isIsomorphic("paper", "title"));
    assert(isIsomorphic("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba"));
    assert(!isIsomorphic("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcbz"));
}

int main() {

    string path;
    cin >> path;

    //считываем файл и разбиваем на 2 подстроки

    ifstream inputFile(path);
    string line;
    while (getline(inputFile, line)) {
        string s1, s2;
        cout << isIsomorphic(s1, s2); //каждая по n + 1 байт + указатель на строку 8 байт (64-битная система)
    }

    inputFile.close();

    return 0;
}

//time O(n)
