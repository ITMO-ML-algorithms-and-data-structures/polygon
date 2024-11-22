#include <iostream> 
#include <iomanip> 
#include <algorithm> 
#include <vector> 
#include <cmath> 
#include <string> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <deque>

#define ll long long
 using namespace std;
 
 int main() {
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    cout << "size: ";

    int dlin; cin >> dlin;
    vector <int> ass(dlin);
    int koll = 0;

    cout << "write numbers: ";

    for (int i = 1; i < dlin; i++) cin >> ass[i];
        
    for (int i = 1; i < dlin; i++){
        if (ass[i-1] > ass[i]) koll++;
    }
    cout << koll;

    return 0;
}
              

