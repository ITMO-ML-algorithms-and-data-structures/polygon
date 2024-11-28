#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

//функция "спуска" в куче
void downheap(vector<int>& array, int start, int end) {
    int root = start; // устанавливаем корень в начало диапазона
    while (root * 2 + 1 <= end) {
        int child = root * 2 + 1; // вычисляем индекс левого потомка
        if ((child + 1 <= end) && (array[child] < array[child + 1])) { // проверка существования правого потомка и сравнение их значений
            child = child + 1;
        }
        if (array[root] < array[child]) {
            std::swap(array[root], array[child]);
            root = child;
        }
        else {
            return;
        }
    }
}
// сложность O(log(n)) (в худшем случае операции в цикле будут пройдены для каждого узла кучи)

//функция формирования пирамиды
void smoothsort(vector<int>& array, int size) {
    // Начальное формирование пирамиды, начиная с середины массива
    for (int start = (size - 2) / 2; start >= 0; --start) {
        downheap(array, start, size - 1); // корректируем кучу
    }

    // Сортировка
    for (int end = size - 1; end > 0; end--) { 
        std::swap(array[end], array[0]); 
        downheap(array, 0, end - 1); 
    }
}
// временная сложность O(nlog(n)) (за счет циклов for)
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

// Функции тестирования алгоритма
void test_smoothsort1() {
    {
        vector<int> array1 = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
        cout << "Тест 1. Лучший случай";
        print_arr(array1);
        cout << "\n";
        auto start = chrono::high_resolution_clock::now();
        smoothsort(array1, array1.size());
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
        smoothsort(array2, array2.size());
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
        smoothsort(array3, array3.size());
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
        smoothsort(array4, array4.size());
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
void test_smoothsort2() {
    vector<int> arr;
    ofstream file("output21.txt");
    for (int i = 1000; i <= 10000; i = i + 1000) {
        arr = read_file("output2.txt", i);
        auto start = chrono::high_resolution_clock::now();
        smoothsort(arr, arr.size());
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        file << duration.count() << endl;
    }
    file.close();
    cout << "Тест2-1 завершен";
}
void test_smoothsort3() {
    vector<int> arr;
    ofstream file("output22.txt");
    for (int i = 0; i < 50; i = i++) {
        arr = read_file("output2.txt", 10000);
        auto start = chrono::high_resolution_clock::now();
        smoothsort(arr, arr.size());
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        file << duration.count() << endl;
    }
    file.close();
    cout << "Тест2-2 завершен";
}
void test_smoothsort4() {
    vector<int> arr;
    ofstream file("output23.txt");
    for (int i = 0; i < 50; i = i++) {
        arr = read_file("output2.txt", 100000);
        auto start = chrono::high_resolution_clock::now();
        smoothsort(arr, arr.size());
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        file << duration.count() << endl;
    }
    file.close();
    cout << "Тест2-3 завершен";
}

int main() {
    setlocale(LC_ALL, "Ru");
    //test_smoothsort1();
    test_smoothsort2();
    test_smoothsort3();
    test_smoothsort4();

}
