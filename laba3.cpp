#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <string>

using namespace std;

void EditVec(vector<string>& vec) {
    unordered_map<string, int> countMap; // 40 байт + количество ключей * 24 байта + количество значений * 4 байта

    for (int i = 0; i < vec.size(); ++i) {
        countMap[vec[i]]++; //заполняем ключами и значениями
    }

    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = to_string(countMap[vec[i]]); //превращаем значения в строку и заменяем слова на количество
    }
}


int main() {
    vector<string> test1 = {};
    vector<string> res1 = {};

    vector<string> test2 = { "apple", "banana", "apple", "orange", "banana", "apple" }; // 24 байта + количество значений * 24 байта
    vector<string> res2 = { "3", "2", "3", "1", "2", "3" }; // 24 байта + количество значений * 24 байта

    vector<string> test3 = { "orange", "orange", "orange", "orange" }; // 24 байта + количество значений * 24 байта
    vector<string> res3 = { "4", "4", "4", "4" }; // 24 байта + количество значений * 24 байта


    vector<string> test4 = { "pink", "red", "black", "pink", "green", "green", "green", "blue" }; // 24 байта + количество значений * 24 байта
    vector<string> res4 = { "2", "1", "1", "2", "3", "3", "3", "1" }; // 24 байта + количество значений * 24 байта

    vector<string> test5 = { "white", "yellow", "yellow", "white", "yellow", "white", "yellow", "yellow", "white", "yellow" }; // 24 байта + количество значений * 24 байта
    vector<string> res5 = { "4", "6", "6", "4", "6", "4", "6", "6", "4", "6" }; // 24 байта + количество значений * 24 байта

    EditVec(test1);
    assert(test1 == res1);

    EditVec(test2);
    assert(test2 == res2);

    EditVec(test3);
    assert(test3 == res3);

    EditVec(test4);
    assert(test4 == res4);

    EditVec(test5);
    assert(test5 == res5);

    cout << "Done!" << endl;

    return 0;
}
