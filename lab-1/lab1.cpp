#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a;
    int buffer = 0;
    int i, j;
    //ввод массива
    for (int x = 0; x < n; x++ ){
        int temp;
        cin >> temp;
        if (temp > 0) {
            a.push_back(temp);
        } 
    }
    //обработка данных методом сортировки вставкой

    for (i = 1; i < a.size(); i++){
        buffer = a[i];
        for (j = i - 1; j >= 0 && a[j] > buffer; j--)
        a[j + 1] = a[j];
        a[j + 1] = buffer;

    }

    //вывод массива
    for (auto now : a) {
        cout << now << " ";
    }

}