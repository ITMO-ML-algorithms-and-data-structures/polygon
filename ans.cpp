#include "lab1.cpp"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputfail("input.txt"); // 32 байта
    string test;
    while(getline(inputfail, test){
            test.erase(remove_if(test.begin(), test.end(), ::isspace), test.end());
            if (areIsomorphic(test)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
    }
    return 0;
}
