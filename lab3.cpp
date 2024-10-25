#include <iostream>

using namespace std;

int skob(string st) {
    int len_str = st.size();  // O(1)
    int cou = 0; // O(1)
    for (int i = 0; i <= len_str; i++) { // O(1) на каждой итерации
        if (st[i] == '(') {cou += 1;} // O(1)
        else if (st[i] == ')') {cou -= 1;} // O(1)
        if (cou < 0) {return 2;} // O(1)
    }
    if (cou == 0) {return 0;} // O(1)
    else {return 1;} // O(1)
}

int main() {
    string a = "67g((566)))"; // O(1)
    if (skob(a) == 2) {cout << "Error";} // O(1)
    if (skob(a) == 0) {cout << "False";} // O(1)
    if (skob(a) == 1) {cout << "True";} // O(1)
    return 0;
}
//ассимптотика O(n), тк мы один раз проходимся по элементам строки