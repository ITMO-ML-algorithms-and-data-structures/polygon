#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    vector<int> b(0);
    for (int i = 0; i<n; i++) {
        if (a[i] % 2 == 0) b.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
    return 0;
}