#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>
using namespace std;

// Метод для изменения смены двух элементов
void swap(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

// Алгоритм сэмплирования массива
vector<int> sample_array(vector<int> arr) {
    srand(time(nullptr)); // инициализация генератора случайных чисел, O(1) - инициализация генератора случайных чисел
    int n = arr.size(); // O(1) - получение размера массива
    for (int i = n - 1; i > 0; i--) {
        // Цикл выполняется (n-1) раз - O(n)
        int j = rand() % (i + 1); // O(1) - генерация случайного числа

        swap(&arr[i], &arr[j]); // O(1) - обмен двух элементов массива
    }

    return arr; // O(1) - возврат результата
    // Общая сложность: O(n) - один проход по массиву
}

// Функция для чтения файла
void readFileAndProcess(const string &filename, vector<int> &arr) {
    fstream file(filename, fstream::in); // O(1) - открытие файла

    if (file.is_open()) {
        string line;
        while (getline(file, line)) { // O(m) - где m - количество строк в файле
            istringstream iss(line); // O(1) - создание потока для строки
            string number;
            while (getline(iss, number, ',')) { // O(L) - где L - количество символов в строке
                if (!number.empty()) {
                    arr.push_back(stol(number)); // преобразуем строку в число и добавляем в вектор O(1) - добавление числа в вектор (амортизированно)
                }
            }
        }
        arr = sample_array(arr); // O(n) - перемешивание массива

        file.close(); // O(1) - закрытие файла
    }
    // Общая сложность чтения файла: O(m * L + n) - m строк и L символов на строку + перемешивание
}

// Тесты
void test_sample_array() {
    // Тест 1: Проверяем, что перемешивание не меняет размер массива
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> result1 = sample_array(arr1);
    assert(result1.size() == arr1.size());

    // Тест 2: Проверяем, что все элементы присутствуют после перемешивания
    vector<int> sorted_arr1 = {1, 2, 3, 4, 5};
    sort(result1.begin(), result1.end());
    assert(result1 == sorted_arr1);

    // Тест 3: Проверка на массив с одним элементом
    vector<int> arr2 = {42};
    vector<int> result2 = sample_array(arr2);
    assert(result2.size() == 1);
    assert(result2[0] == 42);

    // Тест 4: Проверка на пустой массив
    vector<int> arr3 = {};
    vector<int> result3 = sample_array(arr3);
    assert(result3.size() == 0);
}

int main() {
    test_sample_array();
    int k;
    cin >> k; // O(1)
    vector<int> sampled_arr;

    readFileAndProcess("../dataset.txt", sampled_arr); // O(m * L + n) - обработка файла и перемешивание

    for (int i = 0; i < k; i++) {
        cout << sampled_arr[i] << endl; // O(k) - вывод элементов
    }

    return 0;
}
