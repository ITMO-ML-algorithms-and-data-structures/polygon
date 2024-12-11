#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>


// Слияние двух массивов
void merge(std::vector<int>& arr, const int& left, const int& mid, const int& right) {
    // Длина левого и правого массивов
    int nLeft = mid - left + 1;
    int nRight = right - mid; 

    std::vector<int> arrLeft(nLeft);
    std::vector<int> arrRight(nRight);
    
    // Создаём массивы левой и правой частей массива
    for (int i=0; i<nLeft; i++) arrLeft[i] = arr[left + i];
    for (int i=0; i<nRight; i++) arrRight[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    // Слияние двух отсортированных массива в один
    while (i<nLeft && j<nRight) {
        if (arrLeft[i]<=arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    // Добавояем отсавшиеся эл-ты в итоговый массив
    while (i<nLeft) {
        arr[k] = arrLeft[i];
        i++;
        k++;
    }

    while (j<nRight) {
        arr[k] = arrRight[j];
        j++;
        k++;
    }
}


// Сортировка слиянием
// Использование памяти: O(n) (т. к создаём 2 массива в общей длины n)
// Сложность алгоритма: O(n log n) (рекурсивно разбиваем log n и выполняем слияние O(n))
std::vector<int> mergeSort(std::vector<int> arr, int left, int right) {
    if (left<right) {
        int mid = left + (right - left) / 2;

        arr = mergeSort(arr, left, mid);
        arr = mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
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

    std::cout << duration.count() << "\n";
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
    std::vector<int> arrSort = mergeSort(arr, 0, n - 1);
    assert(check(arrSort));
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    display(arr, arrSort, duration);
}


int main() {
    test(100, 999999, 0);
    return 0;
}