#include <iostream>
#include <vector>
using namespace std;

void brickSort(vector<int>& arr) {
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;
        for (size_t i = 1; i <= arr.size() - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        for (size_t i = 0; i <= arr.size() - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

void shellSort(vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int minElem = arr[0];
    int maxElem = arr[0];
    for (int num : arr) {
        if (num < minElem) minElem = num;
        if (num > maxElem) maxElem = num;
    }
    int range = maxElem - minElem + 1;

    // Массив подсчёта
    vector<int> count(range, 0);
    for (int num : arr) {
        count[num - minElem]++;
    }

    size_t index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minElem;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {34, 2, 78, 1, 56, 99, 23, 12};

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // brickSort(arr); 
    //shellSort(arr); 
    countingSort(arr); 

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
