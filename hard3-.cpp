#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    unordered_map<int, int> quant;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        quant[a[i]]++;
    }
    for (auto i = quant.begin(); i != quant.end(); ++i) {
        if (i->second % 2  == 0) {
            cout << i->first << " ";
        }
    }
    return 0;
}