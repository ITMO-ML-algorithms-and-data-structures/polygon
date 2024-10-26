#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
string compress(const string input)
{
    string compressed;
    int count = 1;
    char currentChar = input[0];

    for (int i = 1; i < input.length(); i++)
    {
        if (input[i] == currentChar)
        {
            count++;
        }
        else
        {
            compressed += currentChar + to_string(count);
            currentChar = input[i];
            count = 1;
        }
    }
    compressed += currentChar + to_string(count) ;

    return compressed;
}

int main()
{
    string input;
    ifstream File;
    File.open("C:\\Users\\oleg-\\projects\\algos\\dataset.txt");
    if (!File) {
        cout << "Не удалось открыть файл." << endl;
        return 1; 
    }
    string line;
    string result;
    while (getline(File, line)) 
    {
        line.erase(remove(line.begin(), line.end(), ';'), line.end());
        result += line; 
    }
    input = result;

    string compressed = compress(input);
    cout << compressed << endl;

}
   //Временная сложность:O(n) (основной цикл выполняется О(n) раз, если символы уникальны, каждый символ будет добавлен к строке compressed, что делает временные также O(n))
   //Пространственная сложность:O(n) (строка compressed может занимать в худшем случае O(n), переменные count, currentChar, i занимают O(1) памяти)
