#include <iostream>
using namespace std;

int main()
{
    int array[] = {1,2,3,4,6,4,12,6234,12,4,6};
    int target = 124;
    int length = sizeof(array) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        
        if (array[i] != target and i == length-1)
        {
            cout << "-1";
        }
        
        if (array[i] == target)
        {
            cout << i;
            break;
        }
        
    }
    
    return 0;
}


