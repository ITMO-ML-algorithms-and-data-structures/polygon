#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



double findMedian(vector <int> arr, int n)
{
    sort(begin(arr), end(arr));

    if (n % 2 != 0) {
        return arr[n / 2];
    }
    else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }

}

int main()
{
    vector <int> arr = { 5, 2, 7, 3, 1, 6, 4 };

    int n = sizeof(arr) / sizeof(arr[0]);

    double median = findMedian(arr, n); 
    cout  << median << endl;
    return 0;

}