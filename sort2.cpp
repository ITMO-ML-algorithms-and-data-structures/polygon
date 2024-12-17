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

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Текущий элемент
        int j = i - 1;

        // Перемещаем элементы, которые больше key, вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Вставляем текущий элемент в правильное место
        arr[j + 1] = key;
    }
}

int main() {
    clock_t start = clock();
    vector<int> arr = read_file("/Users/mir/CLionProjects/lab-5/arr_1_mln.txt");

    insertionSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}