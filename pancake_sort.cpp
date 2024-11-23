#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip> // Для std::fixed и std::setprecision

using namespace std;

// Функция для переворота подмассива
// Сложность: O(k), где k - размер подмассива
void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
}

// Функция для нахождения индекса максимального элемента в массиве
// Сложность: O(n), где n - размер массива
int findMax(const vector<int>& arr, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функция Pancake Sort
// Сложность: O(n^2), где n - размер массива
// Память: O(1), так как сортировка выполняется на месте и не требует дополнительной памяти
void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = n; curr_size > 1; curr_size--) {
        // Находим индекс максимального элемента в текущем массиве
        int maxIndex = findMax(arr, curr_size);

        // Переворачиваем массив до максимального элемента, если он не на первом месте
        if (maxIndex != 0) {
            flip(arr, maxIndex + 1); // Переворот до максимального элемента
        }

        // Переворачиваем оставшуюся часть массива, чтобы переместить максимальный элемент в конец
        flip(arr, curr_size);
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
    // Предопределенные тестовые случаи

    // Лучший случай: отсортированный массив
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Худший случай: отсортированный в обратном порядке
    vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Средний случай: случайный массив
    vector<int> averageCase = {5, 3, 8, 6, -2, 7, 4, 10, 1, 9};

    // Тестирование на лучшем случае
    cout << "Best Case: ";
    printArray(bestCase);

    auto start = chrono::high_resolution_clock::now();
    pancakeSort(bestCase);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted Best Case: ";
    printArray(bestCase);

    auto durationBest = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);

    start = chrono::high_resolution_clock::now();
    pancakeSort(worstCase);
    end = chrono::high_resolution_clock::now();

    cout << "Sorted Worst Case: ";
    printArray(worstCase);

    auto durationWorst = chrono::duration_cast<chrono::microseconds>(end - start).count();

   // Тестирование на среднем случае
   cout << "Average Case: ";
   printArray(averageCase);

   start = chrono::high_resolution_clock::now();
   pancakeSort(averageCase);
   end = chrono::high_resolution_clock::now();

   cout << "Sorted Average Case: ";
   printArray(averageCase);

   auto durationAverage = chrono::duration_cast<chrono::microseconds>(end - start).count();

   // Вывод результатов времени выполнения
   cout << fixed << setprecision(3); // Устанавливаем точность вывода до трех знаков после запятой
   cout << "Time taken for Best Case: " << durationBest / 1000.0 << " ms" << endl;
   cout << "Time taken for Worst Case: " << durationWorst / 1000.0 << " ms" << endl;
   cout << "Time taken for Average Case: " << durationAverage / 1000.0 << " ms" << endl;

   return 0;
}
