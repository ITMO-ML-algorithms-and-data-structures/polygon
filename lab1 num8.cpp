#include <iostream>

using namespace std;

int findDifferenceMinMax(int arr[], int n) {
    if (n == 0) { // возвращает 0 если список пустой
        return 0;
    }

    int mn = arr[0], mx = arr[0]; // максимум и минимум списка

    for (int i = 1; i < n; i++) { //в цикле на каждом шаге обновляем максимальное и минимальное значение списка
        mx = max(mx, arr[i]); // ищет максимум списка
        mn = min(mn, arr[i]); // ищет минимум списка
    }

    return mx - mn; // функция возвращает разность максимального и минимального элем-та списка
}

int main()  {
    int n;
    cin >> n;
    int arr[n]; // ввод длины списка
    for (int i = 0; i< n; i++) {
        cin >> arr[i]; // заполнение списка элементами
    }
    int res = findDifferenceMinMax(arr, n); // присваивает переменной res разность максимального и минимального элем-та списка
    cout << res;

    return 0;
}