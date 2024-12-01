#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace chrono;

// Функция для переворота подмассива от 0 до i
void flip(vector<int> &arr, int i) { // временная - O(n), пространственная - O(1)
    reverse(arr.begin(), arr.begin() + i + 1);
}

// Функция для нахождения индекса максимального элемента в подмассиве arr[0..n-1]
int findMax(vector<int> arr, int n) { // временная - O(n), пространственная - O(1)
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Основная функция Pancake Sort
void pancakeSort(vector<int> &arr) {
    int n = arr.size();
    for (int curr_size = n; curr_size > 1; curr_size--) { // временная - O(n^2), пространственная - O(1)
        int maxIndex = findMax(arr, curr_size);
        if (maxIndex != curr_size - 1) {
            flip(arr, maxIndex); // временная - O(n), пространственная - O(1)
            flip(arr, curr_size - 1); // временная - O(n), пространственная - O(1)
        }
    }
}


// Функция для вывода массива
void printArray(vector<int> arr) { // временная - O(n), пространственная - O(1)
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    // Лучший случай
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Худший случай
    vector<int> worstCase = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Средний случай
    vector<int> averageCase = {5, 3, 8, 6, 2, 7, 4, 10, 1, 9};

    // Тестирование на лучшем случае
    cout << "Best Case: ";
    printArray(bestCase);

    auto start = high_resolution_clock::now();
    pancakeSort(bestCase);
    auto end = high_resolution_clock::now();

    cout << "Sorted Best Case: ";
    printArray(bestCase);

    auto durationBest = duration_cast<microseconds>(end - start).count();

    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);

    start = high_resolution_clock::now();
    pancakeSort(worstCase);
    end = high_resolution_clock::now();

    cout << "Sorted Worst Case: ";
    printArray(worstCase);

    auto durationWorst = duration_cast<microseconds>(end - start).count();

    // Тестирование на среднем случае
    cout << "Average Case: ";
    printArray(averageCase);

    start = high_resolution_clock::now();
    pancakeSort(averageCase);
    end = high_resolution_clock::now();

    cout << "Sorted Average Case: ";
    printArray(averageCase);

    auto durationAverage = duration_cast<microseconds>(end - start).count();

    // Вывод результатов времени выполнения
    cout << fixed << setprecision(3); // Устанавливаем точность вывода до трех знаков после запятой
    cout << "Time taken for Best Case: " << durationBest / 1000.0 << " ms" << endl;
    cout << "Time taken for Worst Case: " << durationWorst / 1000.0 << " ms" << endl;
    cout << "Time taken for Average Case: " << durationAverage / 1000.0 << " ms" << endl;


    return 0;
}
