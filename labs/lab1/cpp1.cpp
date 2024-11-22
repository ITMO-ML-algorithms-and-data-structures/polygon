#include <iostream>
using namespace std;

int main() {
    int array[10] = {1, 13, -14, 89, 45, -9, -65, 56, 1023, -2323};
    int maximum1 = -1000000000000, maximum2 = -10000000000;

    for (int elem : array) {
        if (elem > maximum1) {
            maximum2 = maximum1;
            maximum1 = elem;
        } else if (elem < maximum1 && elem > maximum2) {
            maximum2 = elem;
        }
    }
    
    cout << maximum2 << endl;
}