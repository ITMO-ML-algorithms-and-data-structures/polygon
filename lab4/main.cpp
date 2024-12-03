#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

#include <sstream>

#include <unordered_map>

#include <string>
#include <vector>

#include <cstdint>

#include <fstream>

#include <random>



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

void solve(vector<string>& res, std::istream & in = std::cin, std::ostream & out = std::cout){

}

vector<string> run(const std::string & input) {

    stringstream in(input);
    stringstream out;

    vector <string> res;

    solve(res, in, out);

    return res;
}




void test() {

    ifstream file3("ids_output.txt");
    ifstream file2("inp.txt");

    string small_test((istreambuf_iterator<char>(file3)),
        istreambuf_iterator<char>());
    string big_test((istreambuf_iterator<char>(file2)),
        istreambuf_iterator<char>());

    file3.close();
    file2.close();

    struct {
        string input;
    } tests[] = {
        {big_test},
        {small_test},
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        auto t = tests[i];

        vector<string> out = run(t.input);

        ASSERT_MSG(true, i + 1);
    }

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}

//