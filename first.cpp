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
 
typedef long long ll;
using namespace std;
 
 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    cout << "size: ";

    int dlin; cin >> dlin;
    vector <int> ass(dlin);
    int koll = 0;

    cout << "write numbers: ";

    for (int i = 1; i < dlin; i++){
        cin >> ass[i];

    }
    for (int i = 1; i < dlin; i++){
        if (ass[i-1] > ass[i]) koll++;
    }
    cout << koll;
}
