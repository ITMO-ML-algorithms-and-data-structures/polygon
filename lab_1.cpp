#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main() {
    std::map<int, int> spisok;
    int array[] = {0, 1, 1, 1, 2, 5, 6, 7, 8, 9, 1, 2, 5, 6, 7, 8, 15, 18, 19, 20, 23, 30, 31, 32, 32};
    std::set<int> answer;
    for (auto i : array) {
        spisok[i] = spisok[i] + 1;
    }
    for (auto i : spisok) {
        if (i.second % 2 == 0) {
            answer.insert(i.first);
        }
    }
    for (auto i : answer) {
        cout << i << " ";
    }
}
