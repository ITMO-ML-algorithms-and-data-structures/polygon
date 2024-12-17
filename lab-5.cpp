#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>
//#include "functions.h"

using namespace std;

// Функция для чтения вещественных чисел из файла
vector<double> readDoublesFromFile(const string& filePath) {
    vector<double> numbers; // Вектор для хранения вещественных чисел
    ifstream inputFile(filePath); // Открываем файл

    // Проверяем, удалось ли открыть файл
    if (!inputFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filePath << endl;
        return numbers; // Возвращаем пустой вектор в случае ошибки
    }

    string line;
    // Читаем файл построчно
    while (getline(inputFile, line)) {
        istringstream iss(line); // Создаем поток для разбора строки
        double number;

        // Считываем числа из строки
        while (iss >> number) {
            numbers.push_back(number); // Добавляем число в вектор
        }
    }

    inputFile.close(); // Закрываем файл
    return numbers; // Возвращаем вектор с числами
}

// Функция для сортировки массива с использованием Cycle Sort
void cycleSort(vector<double>& arr) {
    int n = arr.size();
    int writes = 0; // Счетчик записей в память

    for (int cycle_start = 0; cycle_start < n - 1; cycle_start++) {
        double item = arr[cycle_start];

        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        if (pos == cycle_start) {
            continue;
        }

        while (item == arr[pos]) {
            pos++;
        }

        if (pos != cycle_start) {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cycle_start) {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            while (item == arr[pos]) {
                pos++;
            }

            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}

void insertionSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        double key = arr[i]; // Текущий элемент для вставки
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Вставляем ключ на его правильное место
    }
}

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int getNextGap(int gap) {
    gap = (gap * 10) / 13; // Делим на фактор уменьшения
    return (gap < 1) ? 1 : gap; // Убедимся, что шаг не меньше 1
}

void combSort(vector<double>& arr) {
    int n = arr.size();
    int gap = n; // Начальный шаг

    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// Главная функция для тестирования алгоритма
int main() {
    setlocale(LC_ALL, "RUS");
    /* 
    string path;
    string algtype;

    cin >> path >> algtype;

    vector<double> data = readDoublesFromFile(path);

    if (algtype == "1") {
        cycleSort(data);

    }
    else if (algtype == "2") {
        insertionSort(data);
    }
    else if (algtype == "3") {
        combSort(data);
    }
    else {
        cout << "Ошибка: неверный тип алгоритма." << endl;
        return 1;
    }
    */
    return 0;
}
