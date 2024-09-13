#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Hard +
int main()
{
    int n;
    long long c = 0, s;
    cin >> n >> s;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (abs(a[i] + a[j]) == s)
          c++;
    cout << c << endl;
    return 0;
}