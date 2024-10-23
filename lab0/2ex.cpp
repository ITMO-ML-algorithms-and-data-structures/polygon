#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Hard +
// Найти все пары чисел в массиве, разность которых равна заданному числу
int main()
{
    int n;
    long long c = 0, s;
    cin >> n >> s; //Ввод размера массива и заданное число
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i]; //Ввод элементов массива
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (abs(a[i] + a[j]) == s)
          c++;
    cout << c << endl; //Вывод суммы
    return 0;
}