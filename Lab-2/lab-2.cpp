#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string test, str_first, str_second; // n + n + n

bool isomorphism(string str_first, string str_second){ //n + n 
    if(str_first.size() != str_second.size()) //1
        return false;
    std::map<char, char> isomorf; // 48
    for(int i = 0; i < str_first.size(); i++)
    {
        if(isomorf.find(str_first[i]) == isomorf.end()) // 1
        {
            isomorf[str_first[i]] = str_second[i];
        }
        else if(isomorf[str_first[i]] != str_second[i]) // 1
        {
            return false;
        }
    }
    return true;
}


int main()
{
    ifstream in("test.txt");
    while(getline(in, test)){ // k
        str_second = str_first;
        str_first = test;
        if(str_first != "" and str_second != ""){
            cout << ((isomorphism(str_first, str_second) and isomorphism(str_second, str_first)) ? "true" : "false") << endl; // 1
            str_first = str_second = "";
        }
    }
}
// n + n + n + n + n + 1 + 48 + 1 + 1 + 1 + k = 52 + 5 * n + k байт