#include <iostream> //тут все понятно
using namespace std;
int main() {
    int massiv,min;
    min = INT_MAX; //Вводим переменную, где будет минимальное значение
    cout << "Please enter length array ";
    cin >> massiv;
    int* arr = new int[massiv]; //Создаем динамический массив

    for(int i = 0; i < massiv; i++) {    //задаем значение переменной массива
        cout << " Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    for(int i = 0; i < massiv; i++) { //Находим методом перебора минимальное значение в массиве
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Min element is " << " " << min << endl; //выводим
}
//вот и вся петрушка