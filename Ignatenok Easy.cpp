#include<iostream>
#include <vector>

using namespace std;
int main()
{
    int n; //кол-во элементов списка
    cin >> n;
    int m[n]; //списков из n-элементов
    int s = 0; //сумма элементов списка
    int c = 0;
    //счетчик чисел больших среднего

    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        s += m[i];
    }
    for(int i = 0; i < n; i++)
    {
        if (m[i] > (s/n))
        {
            c += 1;
        }
    }
    cout << "Кол-во эл. больших среднего арифметического:" << c;
    return 0;
}
