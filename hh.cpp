#include <iostream>

int main() {
    int arr[] = {5, 3, 9, 1, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minVal = arr[0]; 
    int maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int difference = maxVal - minVal;

    std::cout << "Разница между максимальным и минимальным: " << difference << std::endl;

    return 0;
}