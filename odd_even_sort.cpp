#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
 
using namespace std;
 
// Функция Odd-Even Sort
// Временная сложность: O(n^2), где n - размер массива
// Пространственная сложность: O(1), так как сортировка выполняется на месте
void oddEvenSort(vector<int>& arr) {
    int n = arr.size();
    bool isSorted = false;
 
    while (!isSorted) {
        isSorted = true;
 
        // Четные индексы
        for (int i = 1; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
 
        // Нечетные индексы
        for (int i = 0; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
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
    oddEvenSort(bestCase);
    auto end = chrono::high_resolution_clock::now();
 
    cout << "Sorted Best Case: ";
    printArray(bestCase);
 
    auto durationBest = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);
 
    start = chrono::high_resolution_clock::now();
    oddEvenSort(worstCase);
    end = chrono::high_resolution_clock::now();
 
    cout << "Sorted Worst Case: ";
    printArray(worstCase);
 
    auto durationWorst = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
   // Тестирование на среднем случае
   cout << "Average Case: ";
   printArray(averageCase);
 
   start = chrono::high_resolution_clock::now();
   oddEvenSort(averageCase);
   end = chrono::high_resolution_clock::now();
 
   cout << "Sorted Average Case: ";
   printArray(averageCase);
 
   auto durationAverage = chrono::duration_cast<chrono::microseconds>(end - start).count();
 
   // Вывод результатов времени выполнения
   cout << fixed << setprecision(6); 
   cout << "Time taken for Best Case: " << durationBest / 1000.0 << " ms" << endl;
   cout << "Time taken for Worst Case: " << durationWorst / 1000.0 << " ms" << endl;
   cout << "Time taken for Average Case: " << durationAverage / 1000.0 << " ms" << endl;
 
   return 0;
}
