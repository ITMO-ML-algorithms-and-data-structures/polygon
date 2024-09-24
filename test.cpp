#include "script.cpp"
#include <string>

using namespace std;

int main() {
    string greeting = "input.txt"; // 32 байта
    string result = isostrings(greeting); // 32 байта
    cout << result << endl;
    return 0;
}