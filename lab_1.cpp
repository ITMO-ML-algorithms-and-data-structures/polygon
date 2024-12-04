#include <iostream> 

#define ll long long
using namespace std;
 
 int main() {

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
              

