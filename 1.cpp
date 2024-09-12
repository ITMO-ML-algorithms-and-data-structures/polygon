#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
    string S = "))))((((";
    int L = 0;
    int itog = 0;

    for (char element : S) {
        if (element == '(') {
            L++;
        } else if (element == ')' & L > 0) {
            L--;
            itog++;
        }
    }
    cout << itog;
    

    return 0;
}

