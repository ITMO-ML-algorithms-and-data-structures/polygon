/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int findMinimum(const std::vector<int>& arr) {
    if (arr.empty()){ 
        return 0; //если массив пустой, то выводится 0
    }
    int minimum = arr[0];
    for (const int& num : arr) {
        if (num < minimum) {
            minimum = num;//находим минимум в массиве
        }
    }
    return minimum;
}

int main() {
    //std::vector<int> array = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    string input_line;
    getline(cin, input_line);
    stringstream ss(input_line);
    
    int num;
    vector<int> array;
    while (ss >> num){
        array.push_back(num);
    }
    {
        int minimum_value = findMinimum(array);//вызываем функцию (ищем минимум в заданном массиве)
        std::cout << "Минимальное значение в массиве: " << minimum_value;//выводим мин значение
    }
    return 0;
}