//количество положительных чисел в массиве
#include <iostream>

int main() {
    int positiveCount = 0;


    int arr[] = {2, -7, 5, 9, -3, -9, 8, 6, 72, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        }
    }
    std::cout << positiveCount << "\n";

    return 0;
}