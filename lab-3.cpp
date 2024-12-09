#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string compress(string str) { //Объявляется функция compress,чтобы избежать копирования строки
    if (str.empty()) return ""; // O(1) Проверяется, пуста ли строка. Если строка пуста, функция сразу возвращает пустую строку 

    string result; //  O(1)  Объявляется строка result, которая будет хранить результат сжатой строки
    int count = 1;//  O(1)  Переменная для подсчета количества повторений каждого символа подряд

    for (size_t i = 1; i <= str.size(); ++i) { // O(n)  цикл по символам строки
        if (i == str.size() || str[i] != str[i - 1]) { // O(1)
            result += str[i - 1]; //   O(1)  добавляется последний символ из последовательности повторяющихся символов
            result += to_string(count); // O(1) Добавляется количество повторений данного символа в виде строки 
            count = 1; // O(1)
        } 
        else {
            ++count; // O(1)
            }
    }
    return result;
}

void Test(){
    string test_1 = "a3b2z5y3w5h3i4";
    assert(compress("aaabbzzzzzyyywwwwwhhhiiii") == test_1);
    std::cout<<"OK";

    string test_2 = "a2b2c2";
    assert(compress("aabbcc") == test_2);
    std::cout<<"OK";
}


int main() {
    string input = "aaabbzzzzzyyywwwwwhhhiiii";
    string compressed = compress(input); //Вызывается функция compress, которая сжимает строку input, и результат сохраняется в переменную compressed
    cout << compressed << endl; //Вывод результата
    Test();
}

