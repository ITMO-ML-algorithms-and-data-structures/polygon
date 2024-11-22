#include <iostream> 
#include <string> 
#include <fstream>

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
    return balance == 0;
}

int main() {
    ifstream input_file("test.txt");

    string row;
    int value;
    while (input_file >> value) {
        arr.push_back(value);
    }
    input_file.close();

    if (isBalanced(row))
        cout << "True";
    else
        cout << "False";

    return 0;
}
//O(n), т.к. мы выполняем единственный линейный проход по строке, и все операции внутри цикла выполняются за O(1)
//O(1), т.к. так как используется лишь одна переменная balance для хранения состояния скобочного баланса.