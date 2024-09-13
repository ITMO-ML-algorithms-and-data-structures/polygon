#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Hard -
int main() 
{
    int n;
    long long sm = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i] % 3 == 0)
            sm += a[i];
    cout << sm << endl;
}