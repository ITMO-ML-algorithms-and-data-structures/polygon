#include <iostream>
#include <string>
using namespace std;

string compressString(const string& str) {
    if (str.empty()) return "";

    string result;
    int count = 1;

    for (size_t i = 1; i <= str.size(); ++i) {
        if (i == str.size() || str[i] != str[i - 1]) {
            result += str[i - 1];
            result += to_string(count);
            count = 1;
        } 
        else {
            ++count;
            }
    }
    return result;
}

int main() {
    string input = "aaabbzzzzzyyywwwwwhhhiiii";
    string compressed = compressString(input);
    cout << compressed << endl;
}

