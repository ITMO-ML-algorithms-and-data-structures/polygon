#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 9, 8, 7, 5, 6, 4, 3, 2, 1, 0};
    int size = sizeof(a) / sizeof(a[0]) - 1;
    bool finish = false;
    while (!finish) {
        finish = true;
        for (int i = 0; i < size; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                finish = false;
            }
        }
        if (finish) {
            break;
        }
        finish = true;
        for (int i = size - 1; i >= 1; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                finish = false;
            }
        }
    }
    for (int i = 0; i <= size; i++) {
        cout << a[i] << " ";
    }
}