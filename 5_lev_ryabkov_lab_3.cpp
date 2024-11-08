#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

vector<int> mixed_array(vector<int> arr)
    {
    int n = arr.size();
    random_device rd; // O(1) - создание генератора случайных чисел
    mt19937 gen(rd()); // O(1) - инициализация генератора случайных чисел

    // Перемешивание элементов массива
    for (int i = n - 1; i >= 0; --i)
    {
        uniform_int_distribution<int> dist(0, i); // O(1) - создание распределения
        int j = dist(gen); // O(1) - генерация случайного индекса
        swap(arr[i], arr[j]); // O(1) - перестановка двух элементов
    }
    // Сложность цикла: O(N) - в худшем случае, цикл выполняется N раз

    return arr;

    }


void test_mixed_array()
    {
    // Тест 1: Проверяем, что перемешивание не меняет размер массива
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> result1 = mixed_array(arr1);
    assert(result1.size() == arr1.size());


    // Тест 2: Проверяем, что все элементы присутствуют после перемешивания
    vector<int> sorted_arr1 = {1, 2, 3, 4, 5};
    sort(result1.begin(), result1.end());
    assert(result1 == sorted_arr1);

    // Тест 3: Проверка на массив с одним элементом
    vector<int> arr2 = {42};
    vector<int> result2 = mixed_array(arr2);
    assert(result2.size() == 1);
    assert(result2[0] == 42);

    //Тест 4: Проверяем, что все разные
    vector<int> arr4 = {1, 2, 3, 4, 5};
    vector<int> result4 = mixed_array(arr4);
    assert(arr4 != result4);

    //Тест 5: Проверяем, что случайные элементы не равны
    vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result5 = mixed_array(arr5);
    random_device rd;
    mt19937 gen(rd());


        uniform_int_distribution<int> dist(0, 9);
        int p = dist(gen);
        assert(arr5[p] != result5[p]);

}

int main() {


    int n = 100000000; // O(1) - выделение памяти и присваивание значения

    ifstream infile("/Users/levr/всякое/pythonProject/dataset_1.txt"); // O(1) - открытие файла
    vector<int> arr(n);             // O(N) - выделение памяти для вектора размером N
    int value;                      // O(1) - выделение памяти для переменной

    // Чтение данных из файла и запись в массив
    for (int u = 0; u < n; ++u) {
        infile >> arr[u]; // O(1) - чтение элемента и запись в массив

    }

    infile.close(); // O(1) - закрытие файла
    // Сложность цикла: O(N) - в худшем случае, цикл выполняется N раз

    test_mixed_array();

    vector<int> mixed_array(arr);

    // Вывод элементов массива на экран
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " "; // O(1) - вывод элемента массива
    }
    // Сложность цикла: O(N) - каждый элемент выводится один раз

    cout << '\n'; // O(1) - переход на новую строку
    return 0; // O(1) - завершение программы
}



// Сложность алгоритма составляет:
// O(N) - в худшем случае для каждого этапа:
//     - Чтение данных из файла: O(N)
//     - Перемешивание массива: O(N)
//     - Вывод массива: O(N)
// Общая сложность программы: O(N) + O(N) + O(N) = O(N).