#include <iostream>
#include <vector>
using namespace std;
/*
    test                                        answer
    {1, 2, 2, 5, 7, 5, 8, 5}                    19
    {1, 5, 3, 4, 2}                             0
    {}                                          0
    {2, 2, 2, 111, 1, 1, -10, 7, -10, 111}      210

*/

bool flag(vector<int> arr, int elem) {
    int cnt = 0;
    for (int c : arr) {
        if (elem == c) {
            cnt++;
        }
        
        if (cnt >= 2) {
            return true;
        }
    }
    
    return false;
}


int main() {
    vector<vector<int>> tests= {{1, 2, 2, 5, 7, 5, 8, 5}, {1, 5, 3, 4, 2}, {}, {2, 2, 2, 111, 1, 1, -10, 7, -10, 111}};
    int sum;

    for (vector<int> test : tests) {
        sum = 0;
        for (int el : test) {
            if (flag(test, el)) {
                sum += el;
            }
        }
    
        cout << sum << "\n";
    }

    return 0;
}