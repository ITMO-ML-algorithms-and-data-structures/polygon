#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // Найти все пары чисел в массиве, разность которых равна заданному числу
    int k = 3;
    vector<int> vec({1, 4, 6, 1, 3, 3, 3, 6, 2, 10, 12, 15});
    int length = size(vec);
    for (int i; i<length; i++) {
        for (int j=i; j<length; j++) {
            if ((j-i==k) || (i-j==k)) {
                cout << j << " " << i << endl;
            }
        }
    }
    return 0;
}