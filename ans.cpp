#include <cassert>
#include "lab1.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    assert(areIsomorphic("foo", "bar") == false);
    assert(areIsomorphic("egg", "adD") == false);
    assert(areIsomorphic("doo", "goo") == true);

    ifstream inputfail("input.txt"); // 32 байта
    string test;
    while(getline(inputfail, test)) { // всего символов в файле * 1 байт
        bool f = true;// 1 байт
        string a = "",b = "";
        if (test.size() % 2 == 0){
            test.pop_back();
        }
        for(int i = 0;i < test.size(); i++){// i = 4 байта
            if (test[i] == ' '){
                f = false;
                i++;
            }
            if (f){
                a += test[i]; //len(a) * 1 байт
            }else{
                b += test[i]; //len(b) * 1 байт
            }
        }
        if (areIsomorphic(a, b)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
