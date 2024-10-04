#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

int GetIndex(set<string> repl, string str)
{
    // просто ищет индекс элемента в set (т.к. там всего 100 уникальных это тратит очень мало времени)
    int Index = 1;
    for (auto u : repl) { // 4 байта на каждый элемент
        if (u == str)
            return Index;
        Index++;
    }
    return -1;
}
vector<int> labelencoder(vector<string> arr)
{
    // задаем переменные для замен
    // вектора хватит по ОЗУ даже если 1е9
    vector <int> res; // 16 байт + элементы
    set<string> replacement; // 16 байт + элементы

    //производим замену
    replacement.insert(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) res.push_back(GetIndex(replacement, arr[i])); //4 байта на каждый элемент

    return res;
}
void testProcessLine() {
    // почему-то не давало проверить массив, поэтому пришлось закостылить
    // байты не считаем, т.к. не учитывается
    vector<string> test1({ "Orange", "Yellow", "Orange" });
    vector<int> result = labelencoder(test1);
    string res1;
    for (int i = 0; i < result.size(); i++) res1 += to_string(result[i]);
    assert(res1 == "121");
    vector<string> test2({ "Orange","Blue","Grey","Orange","Yellow","Blue" });
    result = labelencoder(test2);
    string res2;
    for (int i = 0; i < result.size(); i++) res2 += to_string(result[i]);
    assert(res2 == "312341");
    vector<string> test3({ "Blue" });
    result = labelencoder(test3);
    string res3;
    for (int i = 0; i < result.size(); i++) res3 += to_string(result[i]);
    assert(res3 == "1");

    cout << "All tests passed!" << endl;
}
int main() {
    testProcessLine();
}