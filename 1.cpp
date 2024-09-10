#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
    string S = "((())())()";
    int L = 0;
    int R = 0;

    for (char element : S) {
        if (element == '(') {
            L = L + 1;
        } else if (element == ')') {
            R = R + 1;
        }
    }
    
    if (L > R){
        cout << R;
    } else if (R > L){
        cout << L;
    }else{
        cout << R;
    }

    return 0;
}
