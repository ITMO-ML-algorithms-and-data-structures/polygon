#include <iostream>

int main() {
    int positiveCount = 0;

    int arr[] = {2, -7, 5, 9, -3, -9, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        }
    }
    std::cout << positiveCount << std::endl;

    return 0;
}
