#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace chrono;


// Функция для обмена двух элементов
void swap(int &a, int &b) { // временная сложность - О(1), пространственная - О(1)
    int temp = a;
    a = b;
    b = temp;
}

// Функция для выполнения сортировки Comb Sort
void combSort(vector<int> &arr) { // временная сложность в среднем случае - О(nlogn), пространственная - О(1)
    int n = arr.size();
    int gap = n;
    bool swapped = true;

    // Пока шаг больше 1, продолжаем сортировать
    while (gap > 1 or swapped) { // временная сложность в среднем случае - О(nlogn), пространственная - О(1)
        gap = gap * 10 / 13;  // Уменьшаем шаг (обычно на 1.3)
        if (gap < 1) gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++) { // временная сложность - О(n), пространственная - О(1)
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}


// Функция для вывода массива
void printArray(vector<int> arr) { // временная сложность - О(n), пространственная - О(1)
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
    combSort(bestCase);
    auto end = high_resolution_clock::now();

    cout << "Sorted Best Case: ";
    printArray(bestCase);

    auto durationBest = duration_cast<microseconds>(end - start).count();

    // Тестирование на худшем случае
    cout << "Worst Case: ";
    printArray(worstCase);

    start = high_resolution_clock::now();
    combSort(worstCase);
    end = high_resolution_clock::now();

    cout << "Sorted Worst Case: ";
    printArray(worstCase);

    auto durationWorst = duration_cast<microseconds>(end - start).count();

    // Тестирование на среднем случае
    cout << "Average Case: ";
    printArray(averageCase);

    start = high_resolution_clock::now();
    combSort(averageCase);
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
 
