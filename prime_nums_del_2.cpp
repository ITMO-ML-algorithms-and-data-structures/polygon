#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>

using namespace std;

bool isPrime(int num) {
    if (num < 3) return false;
    int limit = static_cast<int>(sqrt(num));
    for (int i = 2; i <= limit; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    vector<int> testVec = {1, 2, 3, 4, 5, 6, 7, 8, 5, 5, 8 ,9, 7, 101, 103, 103};
    unordered_map<int, int> countHash;
    for (int el: testVec) {
        if (isPrime(el)) {
            if (countHash.count(el)) {
                countHash[el]++;
            } else {
                countHash[el] = 1;
            }
        }
    }

    for (auto pair: countHash) {
        if (pair.second % 2 == 0) {
            cout << pair.first << endl;
        }
    }
    return 0;
}
