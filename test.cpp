#include <iostream>
#include <vector>
#include "script.cpp"

using namespace std;


int main() {
    vector<int> arr = {1,100,10,2,5,6,7,8};
    int K = 5;

    vector<int> result = sampleArray(arr, K);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
