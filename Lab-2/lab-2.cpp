#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <locale>
using namespace std;

string str_first, str_second; // n + n 

bool isomorphism(string str_first, string str_second){ //n + n 
    if(str_first.size() != str_second.size())
        return false; // 1
    map<char, char> isomorf; // 48
    for(int i = 0; i < str_first.size(); i++)
    {
        if(isomorf.find(str_first[i]) == isomorf.end())
            isomorf[str_first[i]] = str_second[i]; // 1
        else if(isomorf[str_first[i]] != str_second[i])
        {
            return false; // 1
        }
    }
    return true; // 1
}


int main()
{
    cin >> str_first >> str_second;
    if(isomorphism(str_first, str_second))
        cout << "true";
    else
        cout << "false";
}
// n + n + n + n + 1 + 48 + 1 + 1 + 1 = 52 + 4 * n байт