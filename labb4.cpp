#include <iostream>
#include <vector>

using namespace std; 

int n; 
vector<int> a, tek1, tek2, ans1, ans2;  
void f(int sm1, int sm2, int cnt) { 
    if (cnt == n) {  
        if (sm1 == sm2) { 
            ans1 = tek1; 
            ans2 = tek2; 
        }
    } else { 
        tek1.push_back(a[cnt]);  
        f(sm1 + a[cnt], sm2, cnt + 1); 
        tek1.pop_back(); 
        tek2.push_back(a[cnt]); 
        f(sm1, sm2 + a[cnt], cnt + 1); 
        tek2.pop_back(); 
    }
}

int main() {
    vector<int> arr; 
    arr.push_back(1); 
    arr.push_back(5); 
    arr.push_back(11); 
    arr.push_back(5);
    n = arr.size(); 
    a = arr;  

    f(0, 0, 0); 
    if (ans1.empty()) { 
        cout << "impossible"; 
        return 0; 
    } else {
        cout << "possible\n"; 
        for (int it : ans1) cout << it << ' ';
        cout << '\n'; 
        for (int it : ans2) cout << it << ' '; 
    }
}
