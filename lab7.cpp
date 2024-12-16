#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
    int len_s = s.length();
    int len_p = p.length();
    
    int index_s = 0;
    int index_p = 0;
    int last_index_star = -1;
    int match_index = 0;

    while (index_s < len_s) {
        if (index_p < len_p && (s[index_s] == p[index_p] || p[index_p] == '?')) {
            index_s++;
            index_p++;
        }
        else if (index_p < len_p && p[index_p] == '*') {
            last_index_star = index_p;
            match_index = index_s;
            index_p++;
        }
        else if (last_index_star != -1) {
            index_p = last_index_star + 1;
            index_s = ++match_index;
        } 
        else {
            return false;
        }
    }
    while (index_p < len_p && p[index_p] == '*') {
        index_p++;
    }
    return index_p == len_p;
}

int main() {
    string s = "aa", p = "*";

    if (isMatch(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
