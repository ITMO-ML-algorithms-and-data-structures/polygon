#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int GetIndex(set<string> repl, string str)
{
    // просто ищет индекс элемента в set (т.к. там всего 100 уникальных это тратит очень мало времени)
    int Index = 1;
    for (auto u : repl) {
        if (u == str)
            return Index;
        Index++;
    }
    return -1;
}
int main()
{
    // получаем значения из файла
    ifstream MyReadFile("vhod.txt");
    string str;
    vector <string> arr;
    while (getline(MyReadFile, str)) arr.push_back(str);
    // задаем переменные для замен
    vector <int> res;
    set<string> replacement;

    //производим замену
    replacement.insert(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) res.push_back(GetIndex(replacement, arr[i]));

    // записываем данные в файл
    ofstream MyFile("vihod.txt");
    for (int i = 0; i < res.size(); i++)MyFile << res[i] << '\n';
    MyFile.close();

    return 0;
}
