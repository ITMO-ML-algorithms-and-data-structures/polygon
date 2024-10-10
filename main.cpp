//Ксения Автономова 10.10.2024
//Поток: 4
//Задача: Реализовать функцию, которая определяет, являются ли две строки изоморфными.
//Основная программа
#include <iostream>
#include "lab2_lib.h"

using namespace std;

int main()
{
    string inputString1 = "";
    cout << "Enter first string:\n";    
    getline(cin, inputString1);

    string inputString2 = "";
    cout << "Enter second string:\n";
    getline(cin, inputString2);

    auto result = IsIsomorphic(inputString1, inputString2);

    if (result) {
        cout << "String are isomorphic";
    }
    else {
        cout << "String are not isomorphic";
    }
}
