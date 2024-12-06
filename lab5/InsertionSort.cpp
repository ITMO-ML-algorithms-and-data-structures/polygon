#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>


// Сортировка вставками
// Использование памяти: O(1) для переменных
// Сложность алгоритма: O(n^2) (т. к два вложеных массива длины n)
std::vector<int> insertionSort(std::vector<int> arr) {
    int n = arr.size();
    for (int i=1; i<n; i++) // Проходим все эл-ты
        // Если пред эл больше текцщего, то меняем местами и сдвигает вправо
        for (int j=i; j>0 && arr[j-1]>arr[j]; j--)
            std::swap(arr[j-1], arr[j]);

    return arr;
}


// Функция для создания случайного массива
std::vector<int> arrRand(const int& n, const int& arrMin, const int& arrMax) {
    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 seed(rd());
    arr[0] = arrMax;
    arr[n - 1] = arrMin;

    for (int i=1; i<n-1; ++i) arr[i] = arrMin + seed() % (arrMax - arrMin);

    return arr;
}


std::vector<int> arrWorse(const int& n) {
    std::vector<int> arr(n);

    for (int i=0; i<n; ++i) arr[i] = n - i;

    return arr;
}


std::vector<int> arrBett(const int& n) {
    std::vector<int> arr(n);

    for (int i=0; i<n; ++i) arr[i] = i;

    return arr;
}


// Вывод
void display(const std::vector<int>& arr, const std::vector<int>& arrSort, std::chrono::duration<double> duration) {
    /*
    int n = arr.size();
    std::cout << "\nРазмер массива:" << n;
    */

    std::cout << duration.count() << ", ";
    /*
    std::cout << "\nИсходный массив:\n";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";

    std::cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < n; i++) std::cout << arrSort[i] << " ";
    */
}


// Проверка на корректность сортировки
bool check(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i=1; i<n; ++i) {
        if (arr[i - 1]>arr[i]) return false;
    }

    return true;
}


// Тест для алгоритма сортировки
void test(const int& n = 10, const int& arrMax = 100, const int& arrMin = 0) {
    std::vector<int> arr = arrRand(n, arrMin, arrMax);

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> arrSort = insertionSort(arr);
    assert(check(arrSort));
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    display(arr, arrSort, duration);
}


int main() {
    for (int i=1000; i <= 50000; i+=1000)
        test(i, 999999, 0);
    return 0;
}