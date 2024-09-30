#include <iostream>

using namespace std;

int main() 
{   
    int size;
    cin >> size; //вводится кол-во элементов в массиве
    int maximum[2] = { 0, 0 }; //максимальные положительные элементы
    int minimum[2] = { 0, 0 }; //минимальные отрицательные элементы
    for (int i = 0; i < size; i++) { //считывание элементов
        int digit;
        cin >> digit;
        if (digit > 0) { //положительное или отрицательное
            if (digit > maximum[1]) {
                maximum[0] = maximum[1];
                maximum[1] = digit;
            }
            else if (digit > maximum[0]) {
                maximum[0] = digit;
            }
        }
        else {
            if (digit < minimum[1]) {
                minimum[0] = minimum[1];
                minimum[1] = digit;
            }
            else if (digit < minimum[0]) {
                minimum[0] = digit;
            }
        }
    }
    if (minimum[0] == maximum[0] and maximum[0] == 0) { //если массив из двух элементов, выводим их
        cout << minimum[1] << " " << maximum[1];
    }
    else {
        if (minimum[0] * minimum[1] > maximum[0] * maximum[1]) {   //поиск макс произведения
            cout << minimum[0] << " " << minimum[1];
        }
        else {
            cout << maximum[0] << " " << maximum[1];
        }
    }
    return 0;
}
