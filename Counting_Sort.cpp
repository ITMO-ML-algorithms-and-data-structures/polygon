#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Для max_element

using namespace std;

vector<int> read_file(const string& filename) {
    vector<int> arr; // Вектор для хранения элементов массива
    ifstream inputFile(filename); // Открываем файл для чтения

    int number;
    while (inputFile >> number) { // Читаем числа из файла
        arr.push_back(number); // Добавляем каждое число в вектор
    }

    return arr; // Возвращаем заполненный массив
}

void countingSort(vector<int>& arr) {
    // Находим максимальное значение в массиве
    int max = *max_element(arr.begin(), arr.end());

    // Создаем массив для подсчета частоты значений
    vector<int> count(max + 1, 0);

    // Подсчитываем частоту каждого элемента
    for (int num : arr) {
        count[num]++;
    }

    // Заполняем исходный массив отсортированными элементами
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i; // Записываем значение в отсортированный массив
            count[i]--; // Уменьшаем счетчик
        }
    }
}

int main() {
    vector<int> arr = read_file("datasets/dataset_1000.txt");

    countingSort(arr); // Сортируем массив

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}