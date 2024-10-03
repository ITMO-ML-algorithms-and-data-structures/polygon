using namespace std;
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <string>

set<long long> mass;
vector<int> vec;

int main() {
    ifstream file("numbers1.txt");
    string line;
    while (getline(file, line)) {
        long long m = stoll(line);
        mass.insert(m);
    }

    vec.assign(mass.begin(), mass.end());
    for (long long i : vec) {
        cout << i << ", ";
    }
}