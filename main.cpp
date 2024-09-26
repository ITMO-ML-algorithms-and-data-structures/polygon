//Ксения Автономова 26.09.2024
//Поток: 4
//Задача: Найти количество пар чисел в массиве, где первое больше второго.
//Основная программа
#include <iostream>
#include <sstream>
#include <vector>
#include "lab1_lib.h"

using namespace std;

//Функция преобразования строки, содержащей числа, в массив чисел
vector<int> ExtractNumbers(string inputString)
{
    vector<int> numbers;
    stringstream stream;
    stream << inputString;

    int number;

    while (!stream.eof()) {
        stream >> number;
        numbers.push_back(number);
    }

    return numbers;
}


int main()
{
    cout << "Enter numbers separated by space (like '10 20 30'):\n";
    
    string inputString = "";
    getline(cin, inputString);
    vector<int> inputNumbers = ExtractNumbers(inputString);

    int result = CalcLab1Result(inputNumbers);
    std::cout << "Result: " << result << "\n";
}