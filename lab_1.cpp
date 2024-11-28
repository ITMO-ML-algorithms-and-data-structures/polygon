#include <iostream>

bool isPrime(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i * i <= num; ++i) { 
        if (num % i == 0) return false; 
    }
    return true; 
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n]; 
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            std::cout << a[i] << " "; 
        }
    }
    std::cout << std::endl;
    delete[] a;

    return 0;
}