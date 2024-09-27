#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Hard -
//Найти сумму всех чисел массива, которые кратны 3
int main() 
{
    int n;
    long long sm = 0;
    cin >> n; // Ввод размера массива
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; //Ввод элементов массива
    for (int i = 0; i < n; i++)
        if (a[i] % 3 == 0)
            sm += a[i];
    cout << sm << endl; //Вывод суммы
}