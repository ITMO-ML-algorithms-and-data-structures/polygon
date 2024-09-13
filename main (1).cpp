#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main() {
    // Найти все числа, которые встречаются чётное количество раз
    
    vector<int> vec({1, 2, 3, 4, 4, 5, 7, 1, 7, 2, 2});
    set<int> my_set;
    for (int x : vec) {
        my_set.insert(x);
    }
    
    int length = size(vec);
    
    for (int item : my_set) {
        int k = 0;
        
        for (int j=0; j < length; j++) {
            if (item == vec[j]) {
                k++;
            }
        }
        
        if (k % 2 == 0) {
            cout << item << endl;
        }
    }
}