#include <iostream> 
#include <string> 

using namespace std;

bool isBalanced(const string& row) {
    int balance = 0;

    for (char ch : row) {
        if (ch == '(') {
            balance++;
        }
        else if (ch == ')') {
            balance--;
            if (balance < 0) {
                return false;
            }
        }
    }
    return balance != 0;
}

int main() {
    string row = "a(b)(((a)b))";

    if (isBalanced(row))
        cout << "True";
    else
        cout << "False";

    return 0;
}
//O(n), т.к. мы выполняем единственный линейный проход по строке, и все операции внутри цикла выполняются за O(1)
//O(1), т.к. так как используется лишь одна переменная balance для хранения состояния скобочного баланса.