#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

string runner(string str) {
    string result;
    int len = str.size();
    if (len == 0) {
        return result;
    }
    char Char = str[0];
    int kol = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == Char) {
            kol++;
        } else {
            result += Char;
            result += to_string(kol);
            Char = str[i];
            kol = 1;
        }
    }
    result += Char;
    result += to_string(kol);
    return result;
}

int main() {
    ifstream F("aba.txt");
    vector<string> A;
    string line;
    while (getline(F, line)) {
        A.push_back(line);
    }
    F.close();
    string B;
    B = runner(A[0]);
    cout << B;
    return 0; 
}
