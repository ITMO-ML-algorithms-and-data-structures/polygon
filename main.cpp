#include  <iostream>
#include <random>
#include <chrono>
#include <string>
#include <cmath>
using namespace std;

int count_n = 0;

int abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}


// Функция для выполнения Comb Sort
void combSort(int arr[], int n) {
    int gap = n; // Начальное расстояние
    bool swapped = true;

    // Постепенное уменьшение gap до 1
    while (gap != 1 || swapped) {
        // Уменьшаем расстояние согласно фактору уменьшения 1.3
        gap = max(1, static_cast<int>(gap / 1.3));
        swapped = false;

        // Сравниваем и переставляем элементы на расстоянии gap
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}



void countSort(int array[], int size) {

    int max = array[0];
    int min = array[0];
    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    int count_len = abs(max - min) + 1;
    int count[count_len];

    for (int i = 0; i < count_len; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i] - min]++;
    }
    int ind = 0;
    for (int i = 0; i < count_len; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                array[ind++] = i + min;
            }
        }
    }

}

void cocktailSort(int a[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            // count_n += 1;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped) {
            break;
        }

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            // count_n += 1;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

int number_of_errors = 0;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
        cout << endl;
    }
}

bool check(int array[], int size) {
    bool f = true;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            f = false;
            break;
        }
    }
    return f;
}

random_device rd;
mt19937 gen(rd());
uniform_int_distribution distrib(0, 10000);

void time(int n, string func) {
    int array[n];


    for (int i = 0; i < n; ++i) {
        array[i] = distrib(gen);
    }
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = array[i];
    }
    auto start = chrono::high_resolution_clock::now();
    if (func == "countSort") {
        countSort(array, n);
    } else if (func == "combSort") {
        combSort(array, n);
    } else if (func == "cocktailSort"){
        cocktailSort(array, n);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << elapsed.count() << endl;
    if (!check(array, n)) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        number_of_errors++;
        }

}

void times_for_different_arrays (int min, int max, int step, string func) {
    cout << func << endl;
    for (min; min <= max; min += step) {
        time(min, func);
    }
}

void times_for_array_n (int n, int number, string func) {
    cout << func << endl;
    for (int i; i < number; i++) {
        time(n, func);
    }
}


void tests_cocktailSort() {
    int best[] = {1, 2, 3, 4 , 5};
    int worst[] = {5, 4, 3, 2, 1};
    int rand[] = {3, 2, 5, 4, 1};
    cocktailSort(best, 5);
    cout << count_n << endl;
    count_n = 0;
    cocktailSort(worst, 5);
    cout << count_n << endl;
    count_n = 0;
    cocktailSort(rand, 5);
    cout << count_n << endl;
    count_n = 0;
}

void tests_combSort() {
    int best[] = {1, 2, 3, 4 , 5};
    int worst[] = {5, 4, 3, 2, 1};
    int rand[] = {3, 2, 5, 4, 1};
    combSort(best, 5);
    cout << count_n << endl;
    count_n = 0;
    combSort(worst, 5);
    cout << count_n << endl;
    count_n = 0;
    combSort(rand, 5);
    cout << count_n << endl;
    count_n = 0;
}

int main() {
    // //Для ввода массива вручную
    // int arr[100000];
    // for (int i = 0; i < 100000; i++) {
    //     arr[i] = i;
    // }
    // auto start = chrono::high_resolution_clock::now();
    // combSort(arr, 100000);
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double, milli> elapsed = end - start;
    // cout << elapsed.count() << endl;



    // times_for_different_arrays(1000,100000,1000,"countSort");
    // times_for_different_arrays(10000, 100000, 1000, "combSort");
    // times_for_array_n(10000, 100, "cocktailSort");
    cout << number_of_errors << endl;
}