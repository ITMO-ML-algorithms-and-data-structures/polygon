// lab-5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

void oddevensort(vector<int>& arr) {
    int n = arr.size();
    bool sorted = false;

    while (!sorted) { // O(n)
        sorted = true;

        // Обмен элементов на нечетных позициях
        for (int i = 1; i < n - 1; i += 2) { // O(n)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        // Обмен элементов на четных позициях
        for (int i = 0; i < n - 1; i += 2) { // O(n)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}
// временная сложность в худшем и среднем случае - O(n^2), в лучшем случае (когда массив отсортирован) - O(n)
// пространтсвенная сложность - O(1)

// Функция вывода
void print_arr(const vector<int>& arr) {
    cout << "[";
    for (int j = 0; j < arr.size(); j++) {
        cout << arr[j];
        if (j < arr.size() - 1) {
            cout << " , ";
        }
    }
    cout << "] ";
}

// Функция тестирования алгоритма
void test_oddevensort1() {
    {
        vector<int> array1 = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
        cout << "Тест 1. Лучший случай";
        print_arr(array1);
        cout << "\n";
        auto start = chrono::high_resolution_clock::now();
        oddevensort(array1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        print_arr(array1);
        cout << "\n";
        cout << "Время: " << duration.count() << " секунд\n";
        cout << "\n";
    }

    {
        vector<int> array2 = { 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        cout << "Тест 2. Худший случай";
        print_arr(array2);
        cout << "\n";
        auto start = chrono::high_resolution_clock::now();
        oddevensort(array2);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        print_arr(array2);
        cout << "\n";
        cout << "Время: " << duration.count() << " секунд\n";
        cout << "\n";
    }
    {
        vector<int> array3 = { 38, 42, 27, 31, 20, 19, 23, 18, 10, 14, 9, 12, 8, 3, 13, 28, 1, 5, 50, 44, 37, 47, 34, 29, 26, 48, 24, 17, 7, 45, 11, 33, 6, 15, 36, 25, 41, 30, 4, 2, 35, 32, 21, 46, 49, 40, 39, 22, 43, 16 };
        cout << "Тест 3. Средний случай 1";
        print_arr(array3);
        cout << "\n";
        auto start = chrono::high_resolution_clock::now();
        oddevensort(array3);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        print_arr(array3);
        cout << "\n";
        cout << "Время: " << duration.count() << " секунд\n";
        cout << "\n";
    }
    {
        vector<int> array4 = { 18, 47, 32, 27, 19, 38, 5, 50, 45, 45, 3, 20, 35, 13, 2, 36, 7, 4, 6, 31, 29, 49, 46, 42, 30, 5, 45, 16, 25, 28, 12, 21, 11, 48, 45, 24, 44, 41, 40, 33, 5, 23, 26, 10, 37, 17, 8, 22, 15, 34 };
        cout << "Тест 4. Средний случай 2";
        print_arr(array4);
        cout << "\n";
        auto start = chrono::high_resolution_clock::now();
        oddevensort(array4);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        print_arr(array4);
        cout << "\n";
        cout << "Время: " << duration.count() << " секунд\n";
        cout << "\n";
    }

}
vector<int> read_file(const string& filename, int size) {
    ifstream file(filename);
    vector<int> data;
    int elem;
    while (size > 0 && file >> elem) {
        data.push_back(elem);
        size--;
    }
    return data;
}
void test_oddevensort2() {
    vector<int> arr;
    ofstream file("output11.txt");
        for (int i = 1000; i <= 10000; i = i + 1000) {
            arr = read_file("output1.txt", i);
            auto start = chrono::high_resolution_clock::now();
            oddevensort(arr);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            file << duration.count() << endl;
        }
        file.close();
        cout << "Тест1-1 завершен";
}
void test_oddevensort3() {
    vector<int> arr;
    ofstream file("output12.txt");
    for (int i = 0; i < 50; i = i++) {
        arr = read_file("output1.txt", 10000);
        auto start = chrono::high_resolution_clock::now();
        oddevensort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        file << duration.count() << endl;
    }
    file.close();
    cout << "Тест1-2 завершен";
}
void test_oddevensort4() {
    vector<int> arr;
    ofstream file("output13.txt");
    for (int i = 0; i < 50; i = i++) {
        arr = read_file("output1.txt", 100000);
        auto start = chrono::high_resolution_clock::now();
        oddevensort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        file << duration.count() << endl;
    }
    file.close();
    cout << "Тест1-3 завершен";
}
int main() {
    setlocale(LC_ALL, "Ru");
    //test_oddevensort1();
    test_oddevensort2();
    test_oddevensort3();
    test_oddevensort4();
    return 0;
}
