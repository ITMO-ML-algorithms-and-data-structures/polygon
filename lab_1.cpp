#include <iostream>
using namespace std;

bool isSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSort(arr, n)) {
        cout << "Массив отсортирован по возрастанию." << endl;
    } else {
        cout << "Массив не отсортирован по возрастанию." << endl;
    }
    return 0;
}
