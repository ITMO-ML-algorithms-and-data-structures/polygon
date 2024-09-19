#include <iostream>
#include "middle+lab1.cpp"

int main() {
    int a[] = {1, 1, 1, -1};
    int len = 4;
    int res = Second_MAX(a, len);
    if (res == INT_MIN) {
        cout << "second max digit is not found";
    }
    else {
        cout << res;
    }
}


