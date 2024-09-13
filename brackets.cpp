#include <iostream>
#include <vector>
#include<string>

using namespace std;


int counter(const vector<string> &brackets) {
    int total, l_b;
    l_b = 0;
    total = 0;
    for (const auto & bracket : brackets) {
        if (bracket == "(")
            l_b++;
        else if (bracket == ")" && l_b > 0) {
            total++;
            l_b -= 1;
        }
    }
    return total;
}


int main() {
//    int n = 5;
//  cout << "введите длинну строки";
//  cin >> n;

    string a = "()((())))))(";
    int n = a.size();

    vector<string> brackets(n);
    for (int i = 0; i < n; i++) {
//    cin >> brackets[i];
        brackets[i] = a[i];
    }

//  cout << brackets[4];
    cout << counter(brackets);
    return 0;

}

