#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Найти количество нечётных чисел в массиве

int main() {
    int n;
    int i;

    cout << "Размер массива: ";
    cin >> n;

    // vector arr[n]; // Массив заданного размера
    vector<int> arr(n, 0);
    // arr = { 10, 20, 30 };

    cout << "Элементы массива: "; // Вводим элементы массива
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int odd_count = 0; // Счётчик нечётных чисел

    // Проходим по массиву и считаем нечётные числа
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) { // Проверяем, является ли число нечётным
            odd_count++; // Увеличиваем счётчик
        }
    }

    // Выводим результат
    cout << "Количество нечётных чисел в массиве: " << odd_count << endl;

    return 0;
}
