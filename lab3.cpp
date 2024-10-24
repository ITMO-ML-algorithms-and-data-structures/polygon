#include <iostream>

using namespace std;

int skob(string st) {
    int len_str = st.size();
    int cou = 0;
    for (int i = 0; i <= len_str; i++) {
        if (st[i] == '(') {cou += 1;}
        else if (st[i] == ')') {cou -= 1;}
        if (cou < 0) {return 2;}
    }
    if (cou == 0) {return 0;}
    else {return 1;}
}

int main() {
    string a = "67g((566)))";
    if (skob(a) == 2) {cout << "Error";}
    if (skob(a) == 0) {cout << "False";}
    if (skob(a) == 1) {cout << "True";}
    return 0;
}
//ассимптотика O(n), тк мы один раз проходимся по элементам строки