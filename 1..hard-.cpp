//1 hard -
#include <iostream>
int main()
{
    const int n = 13;
    int num[n]{ 1,4,6,3,2,5,67,2,1,12,4,5,34 };
    int i;
    i = 0;
    int sum;
    sum = 0;
    while (i < n) {
        if ((num[i]) % 3 == 0) {
            sum = sum + num[i];
        }
        i++;
    }
    std::cout << sum;

    return 0;
}
