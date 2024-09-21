#include <iostream>

using namespace std;

int main() {
    int array[10]{1, 4, 9, 15, 3, 7, 8, 33, 12, 10};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i]%3==0) {
            sum += array[i];
       }
    }
    cout << sum;
}
