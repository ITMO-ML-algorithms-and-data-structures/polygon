#include <iostream> 
#include <string> 

using namespace std;

int main() {
    string row = "a(b)(((a)b))";

    int count_open = 0;
    int count_close = 0;

    for (int i = 0; i < row.size(); i++) {
        if (row[i] == '(')
            count_open += 1;
        if (row[i] == ')') {
            count_close += 1;
            if (count_close > count_open)
                break;
        }
    }
    if (count_open == count_close)
        cout << "False";
    else if (count_open > count_close)
        cout << "True";
    else
        cout << "Error";
}
//Сложность - O(N**2)