#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,temp,k; // n - Кол-во элементов в массиве / temp -
    vector <int> a;
    cin >> n;
    k = 0;

    for (int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp); // Заполняем массив элементами
    }

    for (int i = 0;i < a.size(); i++){
        if (a[i] % 2 != 0){
            k++; // Считаем кол-во нечетных элементов
        }
    }
    cout << k;
    return 0;

}