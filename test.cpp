#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,1,2,44,23,765,45,44};
    int l=arr.size();
    set<int> s;
    for (int i = 0; i < l; i++) {
        int r = arr[i];
        s.insert(r);
    }
    cout << "Массив: " << endl;
    for (const int& elem : s) {
        cout << elem << ' ';
    }
    return 0;
}