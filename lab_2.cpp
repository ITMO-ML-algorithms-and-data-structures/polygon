#include <iostream>
#include <vector>
#include <algorithm> //для функции sort

using namespace std;

vector<int> getUniqueValues(const vector<int>& arr) { //функция для извлечения уникальных значений из массива
    vector<int> unique_values; //вектор для хранения уникальных значений
    vector<int> sorted_arr = arr; //копия, чтобы не изменять оригинальный вектор

    //сортируем копию
    sort (sorted_arr.begin(), sorted_arr.end());

    //проходим по отсортированному массиву
    for (size_t i = 0; i < sorted_arr.size(); i++) {
        //i - 4 байта
        if (i == 0 || sorted_arr[i] != sorted_arr[i - 1]) {
            unique_values.push_back(sorted_arr[i]);
            //добавляем только если это первый элемент или элемент не равен предыдущему
        }
    }

    return unique_values;
}

int main() {
    const int size = 4; //размер массива
    //4 байта
    vector<int> arr = {1, 2, 3, 1}; //входной массив
    //4*4 = 16 байт

    vector<int> unique_values = getUniqueValues(arr); //вектор без дубликатов (результат выполнения функции) присваивается переменной unique_values 

    cout << "Уникальные значения: ";
    for (int value : unique_values) {
    //4 байта
    //каждый элемент из контейнера unique_values, сохраняется в переменной value
        cout << value << " ";
    }
    cout << '\n';

    printf ("vector size: %ld bytes\n", sizeof (unique_values));
    //консоль выводит результат 24 байта

    return 0;
}

//общее количество используемой памяти: 4 (size) + 16 (arr) + 24 (unique_values) + 4 (i) + 4 (value) = 52 байта