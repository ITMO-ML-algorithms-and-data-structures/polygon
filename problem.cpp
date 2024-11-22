#include <iostream>
using namespace std;

int primeNum(int c) {
    if (c < 2) return 0;
    for (int j = 2; j < c; j++) {
        if (c % j == 0) {
            return 0;
            break;
        }
    }
    return 1;
}

int main() {
    int n = 8;
    int a[]= {2, 3, 5, 6, 7, 2, 0, 1};
    for (int i = 0; i < n; i++) {
        if (primeNum(a[i])) {
            cout << a[i] << " ";
        }
    }
    return 0;
}

