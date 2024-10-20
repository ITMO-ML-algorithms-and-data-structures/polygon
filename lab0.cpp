#include <iostream>

int secondLargest(int arr[], int size) {
    int first = -1;
    int second = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second and arr[i] != first) {
            second = arr[i];
        }
    }

    return second;
}

int main() {
    int array[] = {1, 5, 2, 54, 23, 56, 7};
    int size = sizeof(array) / sizeof(array[0]);

    int answer = secondLargest(array, size);

    std::cout << answer;

    return 0;

}
