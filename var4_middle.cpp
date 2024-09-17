#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2};
    
    int target;
    cin >> target;
    
    int length;
    length = sizeof(arr)/sizeof(int);

    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == target)
        {
            count = count + 1;
        }        
    }
    cout << count;
    return 0;
}