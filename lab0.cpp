#include <iostream>
int main()
{
    int maximum, n = 5;
    int elements[5];
    for (int i = 0; i < n; i++)
    {
        std::cin >> elements[i];
    }
    maximum = elements[0];
    for (int i = 1; i < n; i++)
    {
        if (elements[i] > maximum)
        {
            maximum = elements[i];
        }
    }
    std::cout << maximum;
    return 0;
}