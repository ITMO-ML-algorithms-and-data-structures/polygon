#include <iostream>

using namespace std;

int partition(int digits[], int low, int high) {

    int pivot = digits[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (digits[j] <= pivot) {
            i++;
            swap(digits[i], digits[j]);
        }
    }

    swap(digits[i + 1], digits[high]);
    return i + 1;
}

/*
!!! MANUAL TEST
!!! DO NOT READ
i = -1 j = 0     104, 231, 235, 678, 124, 129, 238
i =  0 j = 0
i =  1 j = 1
i =  2 j = 2
i =  2 j = 3
i =  3 j = 4     104, 231, 235, 124, 678, 129, 238
i =  4 j = 5     104, 231, 235, 124, 129, 678, 238
*/

void quickSort(int digits[], int low, int high) {
    if (low < high) {
        int pindex = partition(digits, low, high);

        quickSort(digits, low, pindex - 1);
        quickSort(digits, pindex + 1, high);
    }
}

void printArray(int digits[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << digits[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int digits[] = { 104, 231, 235, 678, 124, 129, 238 };
    int size = sizeof(digits) / sizeof(digits[0]);

    cout << "Original array: ";
    printArray(digits, size);

    quickSort(digits, 0, size - 1);

    cout << "Sorted array: ";
    printArray(digits, size);

    return 0;
}
