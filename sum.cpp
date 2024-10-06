//Найти все уникальные пары чисел в массиве, сумма которых равна заданному числу S
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int s;
    cout << "Enter a number: ";
    cin >> s;
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 3};
    unordered_map<int, int> count;
    
    for (int i = 0; i < s; i++)
    {
        ++count[arr[i]];
    }
    for (int num: arr)
    {
        if (count[s - num] != 0)
        {
            cout << num << " " << s - num << "\n";
            count[num] = 0;
            count[s - num] = 0;
        }
    }

    return 0;
}