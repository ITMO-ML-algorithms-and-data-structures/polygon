//Задача: реализовать функцию, которая ищет изоморфные строки
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;
//Функция отвечает за сбор даннх из файла.
string Inoutputer(string FILE_INPUT_FOLDER)
{
    ifstream in(FILE_INPUT_FOLDER);
    if (in.is_open())
    {
        string line;
        getline(in, line);
        in.close();
        return(line);
    }
    else
    {
        cout << "Error" << endl;
        in.close();
        return ("not detected file");
    }
}
//проверка на изоморфность
bool areIsomorphic(const string str1, const string str2) { //1 * 2 * количество символов в строке
    if (str1.length() != str2.length()) {
        return false;
    }
    // Память для словарей  2 * n * 10 байт
    map<char, char> map1;
    map<char, char> map2;
    //проверяем с двух сторон, для этого 2 мапа
    for (size_t i = 0; i < str1.length(); ++i) {
        char char1 = str1[i];//1 байт
        char char2 = str2[i];//1 байт

        if (map1.find(char1) == map1.end()) {
            map1[char1] = char2;//1 ключ+1значение+8 указатель
        }
        else if (map1[char1] != char2) {
            return false;
        }

        if (map2.find(char2) == map2.end()) {
            map2[char2] = char1;//1 ключ+1значение+8 указатель
        }
        else if (map2[char2] != char1) {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string s_main1;
    string FILE_INPUT_FOLDER;
    cout << "ENTER THE FILE PATH" << endl;
    cin>>FILE_INPUT_FOLDER;
    s_main1 = Inoutputer(FILE_INPUT_FOLDER);
    vector<string> words;
    vector<string> results; 
    string word = "";
    for (int i=0; i < s_main1.size()+1; i++)
    {

        if (s_main1[i] != ' ')
        {
            word += s_main1[i];
        }
        else
        {
            words.push_back(word);
            word = "";
            continue;
        }
    }
    for (int j = 0; j < words.size()-1; j++)
    {
        if  (areIsomorphic(words[j], words[j + 1]))
        {
            results.push_back(words[j]+words[j + 1]);
        }
    }
    cout << results.size() << endl;

}
