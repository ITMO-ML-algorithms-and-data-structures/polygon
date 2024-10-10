#include <vector>
#include <iostream>
#include "lab.cpp"

typedef long long ll;

using namespace std;

int main() {
    vector<ll> digits = {0, -45, 72, 13, 65, 23, -99, 0, 0, 1, 2, 5};

    pair<ll, ll> result = getMaxComposition(digits);

    cout << result.first << " " << result.second << endl;

    return 0;
}