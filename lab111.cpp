//Вариант 1
#include <iostream>
using namespace std;
int main()
{
    int sum = 0; //переменная для счёта суммы элементов
    int arr[10]; //в массиве 10 элементов
    cout << "Введите десять чисел:" << endl;
    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];//ввод массива с клавиатуры
    }
        
    for(int j = 0; j < 10; j++)
    {
        if(arr[j] % 3 == 0)//проверка на кратность
        {
            sum = sum + arr[j];
        }
    }
    cout << "Сумма элементов, кратных трём:"<< sum << endl;
    return 0;
}