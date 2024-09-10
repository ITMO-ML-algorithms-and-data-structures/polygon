#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
    string input_line;
    cout << "Enter your line: ";
    getline (cin, input_line);
    stack<char> line;

    int result = 0;

    for (int i = 0; i < input_line.length(); i++) {
        char letter = input_line[i];

        if (letter == '(') {
            line.push(letter);
        } else if (letter == ')') {
            if (!line.empty()) {
                char prev_letter = line.top();
                if (prev_letter == '(') {
                    line.pop();
                    result++;
                    continue;
                } else {
                    line.push(letter);
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}

