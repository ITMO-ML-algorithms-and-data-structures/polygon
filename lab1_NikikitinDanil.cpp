#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector <int> v = { 1,2,3,4,56,78,12,14,2,4,5,7,8,9,70,12,22,42,41 };
    int k, max_k;
    k = 0;

    max_k = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            k = k + 1;
            max_k = max(max_k, k);
        }
        else {
            k = 0;
        }
    }
    cout << max_k;

}