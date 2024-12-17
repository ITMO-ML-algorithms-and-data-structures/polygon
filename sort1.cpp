#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

vector<int> read_file(const string filename) {
    vector<int> mas;
    ifstream in(filename);
    int number;

    while (in >> number) {
        mas.push_back(number);
    }
    return mas;
}

void shakerSort(vector<int>& arr) {
    int left = 0;                // Индекс начала неотсортированного участка
    int right = arr.size() - 1;  // Индекс конца неотсортированного участка
    bool swapped = true;         // Флаг, указывающий на наличие обменов

    while (left < right && swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);  // Обмен элементов, если текущий больше следующего
                swapped = true;           // Устанавливаем флаг: был обмен
            }
        }
        --right;  // Уменьшаем правую границу, т.к. последний элемент теперь на своём месте

        // Проход справа налево
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);  // Обмен элементов, если текущий меньше предыдущего
                swapped = true;           // Устанавливаем флаг: был обмен
            }
        }
        ++left;  // Увеличиваем левую границу, т.к. первый элемент теперь на своём месте
    }
}

int main() {
    clock_t start = clock();
    vector<int> arr = read_file("/Users/mir/CLionProjects/lab-5/arr_1_mln.txt");

    shakerSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}