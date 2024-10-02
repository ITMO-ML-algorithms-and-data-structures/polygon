#include <iostream>
int multiply(int arr[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= arr[i];
    }
    return res;
}

int main() {
    int array[] = {9, 2, 5, 7, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int ans = multiply(array, size);
    std::cout << ans;
    return 0;
}
