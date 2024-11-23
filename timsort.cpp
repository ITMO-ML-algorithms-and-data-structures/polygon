#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
 
using namespace std;
 
const int RUN = 32;
 
// Функция для сортировки вставками
// Временная сложность: O(n^2) в худшем случае, O(n) в лучшем случае
// Пространственная сложность: O(1)
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
 
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
 
// Функция для слияния двух подмассивов
// Временная сложность: O(n), где n - размер объединяемых подмассивов
// Пространственная сложность: O(n)
void merge(vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
 
    vector<int> leftArr(len1);
    vector<int> rightArr(len2);
 
    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = left;
 
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
 
    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
 
    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
 
// Функция Timsort
// Временная сложность: O(n log n) в среднем и худшем случаях, O(n) в лучшем случае
// Пространственная сложность: O(n)
void timSort(vector<int>& arr) {
    int n = arr.size();
 
    // Сортировка вставками для маленьких подмассивов
    for (int start = 0; start < n; start += RUN) {
        insertionSort(arr, start, min(start + RUN - 1, n - 1));
    }
 
    // Слияние отсортированных подмассивов
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
 
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}
 
// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
 
int main() {
 
    // Лучший случай: отсортированный массив
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    // Худший случай: отсортированный в обратном порядке
    vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
 
    // Средний случай: случайный массив
    vector<int> averageCase = {5, 3, 8, 6, 2, 7, 4, 10, 1, 9};
 
    // Тестирование на лучшем случае
    cout << "Best Case: ";
    printArray(bestCase);
 
    auto start = chrono::high_resolution_clock::now();
    timSort(bestCase);
    auto end = chrono::high_resolution_clock::now();
 
    cout << "Sorted Best Case: ";
    printArray(bestCase);
 
    auto durationBest = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);
 
    start = chrono::high_resolution_clock::now();
    timSort(worstCase);
    end = chrono::high_resolution_clock::now();
 
    cout << "Sorted Worst Case: ";
    printArray(worstCase);
 
    auto durationWorst = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
   // Тестирование на среднем случае
   cout << "Average Case: ";
   printArray(averageCase);
 
   start = chrono::high_resolution_clock::now();
   timSort(averageCase);
   end = chrono::high_resolution_clock::now();
 
   cout << "Sorted Average Case: ";
   printArray(averageCase);
 
   auto durationAverage = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
   // Вывод результатов времени выполнения
   cout << fixed << setprecision(6); // Устанавливаем точность вывода до шести знаков после запятой
   cout << "Time taken for Best Case: " << durationBest / 1000.0 << " ms" << endl;
   cout << "Time taken for Worst Case: " << durationWorst / 1000.0 << " ms" << endl;
   cout << "Time taken for Average Case: " << durationAverage / 1000.0 << " ms" << endl;
 
   return 0;
}
