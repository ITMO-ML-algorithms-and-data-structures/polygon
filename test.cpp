#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>

#include <stdio.h>

#include <typeinfo>

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define ASSERT_MSG(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << "." << std::endl; \
            std::cerr << "Error in test: " << message << std::endl; \
            std::abort(); \
        } \
    } while (false)

void solve(std::istream & in = std::cin, std::ostream & out = std::cout) {
    string t;
    in >> t;
    out << t;
}

string run(const std::string & input) {

    stringstream in(input);
    stringstream out;

    solve(in, out);

    return out.str();
}


void test() {
    struct {
        string input;
        string expected_return;
    } tests[] = {
        {"01", "01"},
        {"1", "1"},
        {"-1", "-1"},
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        auto t = tests[i];

        string result = run(t.input);

        //cout << result << endl;
        //cout << t.expected_return << endl;

        ASSERT_MSG(result == t.expected_return, i + 1);
    }

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}

//