#include <iostream>
using namespace std;
//Hard -
//Найти сумму всех чисел массива, которые кратны 3
int main() 
{
    int n, val;
    long long sm = 0;
    cin >> n; // Ввод размера массива
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val % 3 == 0) // Проверка на делимость на 3
            sm += val;
    }
    cout << sm << endl; // Вывод суммы
}