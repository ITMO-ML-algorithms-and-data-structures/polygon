#include <iostream>

int main() {
    const size_t LENGTH = 10;
    int a[LENGTH]= { 1,5,56,-23,-7850,0,6896,46,-155,-1 };
    int min = (int)-INFINITY;

    for (int i = 0; i < LENGTH; i++) {
        //std::cin >> a[i];
        if (a[i] < min) {
            min = a[i];
        }
    }
    std::cout << min;
    return 0;
}
