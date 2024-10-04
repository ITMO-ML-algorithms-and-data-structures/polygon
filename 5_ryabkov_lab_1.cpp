#include <iostream>

int main(){

    int n;
    std::cout << " n: ";
    std::cin >> n;
    int s[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
    }
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (s[i] %3  == 0)
        {
            counter = counter + 1;
        }
    }
    std::cout << "ответ "  << counter;

}
