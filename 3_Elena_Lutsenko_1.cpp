#include <iostream>

using namespace std;

int main() {
    int a[4] = { 1, 3, 5, 6 };
    int s = 0;
    for (int i = 0; i < (end(a) - begin(a)); i++) {
        if (a[i] % 3 == 0) {
            s += a[i];
        }
    }
    cout << s;
    return 0;
}
