#include <iostream>
int main() {
    int n;
    std::cout << " n: "; 
    std::cin >> n;
    short int s[n];

    for (short int i = 0; i < n; i++) 
    {
        std::cin >> s[i];
    }
    short int counter = 0; 
    for (short int i = 0; i < n; i++){ 
        if (s[i] %3  == 0) 
        {
            counter = counter + 1;
        }
        }
        std::cout << "ответ "  << counter; 
        std::cout << std::endl;
