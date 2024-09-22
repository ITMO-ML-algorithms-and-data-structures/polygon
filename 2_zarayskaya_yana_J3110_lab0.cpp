//найти длину самой длиной последовательности одинаковых элементов

#include <iostream>
int main()
{
    int massif[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> massif[i];
    }
    int maxlenght = 1;
    int lenght = 1;
    for (int i = 0; i < 9; i++) {
        if (massif[i] == massif[i + 1]) {
            lenght++;
        }
        else {
            if (lenght > maxlenght) {
                maxlenght = lenght;
            }
            lenght = 1;
        }
    }
    if (lenght > maxlenght) {
        maxlenght = lenght;
    }
    std::cout << maxlenght;
    return 0;
}
