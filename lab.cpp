#include <iostream>

using namespace std;

int findMin(int arr[], int length) {
    int min = arr[0];

    for (int i = 1; i < length; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {20, 3, 5, 17, 10};
    int length = sizeof(arr) / sizeof(arr[0]);

    int min = findMin(arr, length);
    cout << "Минимальное значение в массиве: " << min;

    return 0;
}