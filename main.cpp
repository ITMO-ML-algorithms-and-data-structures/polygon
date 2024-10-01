#include <iostream>
using namespace std;
int main(){
    int n, ans,ans1, i, t;
    cin>>n;
    ans1 = -1;
    ans = -1000;
    for (i = 0; i < n; i++){
        cin>>t;
        if (t > ans){
            ans = t;
            ans1 = i;
        }
    }
    cout<<ans1;

    return 0;
}