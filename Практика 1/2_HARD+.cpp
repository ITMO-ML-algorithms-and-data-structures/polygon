#include <iostream>
using namespace std;



/*
    test                            answer
    "()(()(()))))(((()))"           8
    ")()()((()))))))("              5
    ")("                            0
    "])({()(()"                     2

*/
int main()
{
    string tests[] = {"()(()(()))))(((()))", ")()()((()))))))(", ")(", "])({()(()"};
    int len_tests = sizeof(tests) / sizeof(tests[0]);
    // string s = "])({()(()";
    int close = 0;
    int cnt = 0;
    
    cout << "test" << "\t" << "answer" << "\n";
    for (int i = 0; i < len_tests; i++) {
        cnt = 0;
        close = 0;

        for (char c : tests[i]) {
            if (c == '(') {
                close++;
            }

            if ((c == ')') and (close != 0)) {
                close--;
                cnt++;
            }
        }

        cout << tests[i] << "\t" << cnt << "\n";
    }
    
    // cout << cnt;
    return 0;
}