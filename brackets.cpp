#include <iostream>
#include <vector>
#include<string>

using namespace std;
// задача - посчитать колличество правильных пар скобочек

// считает пары скобочек
int counter(const vector<string> &brackets) {
    int total, l_b; // Переменные счетчики, l_b - Считает левые скобочки
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

    string a = "()((())))))("; // Тестовая строчка

    vector<string> brackets(n);
    for (int i = 0; i < a.size(); i++) {
        brackets[i] = a[i];
    }

//  cout << brackets[4];
    cout << counter(brackets);
    return 0;

}

