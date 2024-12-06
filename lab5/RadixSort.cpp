#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <cassert>


// Функция для сортировки подсчётом на основе текущего разряда
void countingSort(std::vector<int>& arr, const int& exp) {
    int n = arr.size();
    std::vector<int> res(n);
    int count[10] = {0}; // Массив для подсчёта кол-во цифр 0-9 

    // Подсчёт появленме разряда
    for (int i=0; i<n; i++) count[(arr[i] / exp) % 10]++;
    
    // Чтобы count[i] содержал индекс разряда в итоговом массиве
    for (int i=1; i<10; i++) count[i] += count[i - 1];
    
    // Итоговый массив
    for (int i=n-1; i>=0; i--) {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = res;
}


// Подразрядная сортировка
// Использование памяти: O(n * r) r - разряд числа
// Сложность алгоритма: O(n * r) r - разряд числа
std::vector<int> radixSort(std::vector<int> arr) {
    // Максимальный эл в массиве
    int arrMax = *max_element(arr.begin(), arr.end());

    // Сортировка для каждого разряда
    for (int exp=1; arrMax/exp>0; exp*=10) countingSort(arr, exp);

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

    for (int i=0; i<n; ++i) arr[i] = std::pow(10, i);

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
    std::vector<int> arr = arrRand(n, arrMax, arrMin);

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> arrSort = radixSort(arr);
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