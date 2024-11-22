#include <iostream>
#include <string>
#include "lab-3.cpp"

using namespace std;

// int a[] = aaaaaa, ожидаемый вывод → a6 / вывод программы → a6
// int a[] = aababaa, int len = 7: ожидаемый вывод → a2baba2 / вывод программы → a2baba2
// int a[] = aaabbbbcccccd, int len = 6: ожидаемый вывод → a3b4c5d / вывод программы → a3b4c5d
// int a[] = abcdeedcba, len = 4: ожидаемый исход → abcde2dcba / вывод программы → abcde2dcba

int main() 
{
    string uncounted_str = "abcdeedcba";
    string result = compress(uncounted_str);
    cout << result;
}