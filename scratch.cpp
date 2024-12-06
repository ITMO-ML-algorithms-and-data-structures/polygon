#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    cout << "Size: ";
    int len; cin >> len;

    vector <double> ass(len);

    cout << "Numbers: ";
    for (int i = 0; i < len; i++) cin >> ass[i];

    sort(ass.begin(), ass.end());

    if (len % 2 == 0) cout << (ass[len / 2] + ass[len / 2 - 1]) / 2;
    else cout << ass[len / 2];
}
