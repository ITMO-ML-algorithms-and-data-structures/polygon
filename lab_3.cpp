#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int size = 4;
    vector<string> arr = {"Orange", "Red", "Green", "Orange"};

    unordered_map<string, int> countMap;

    for (const auto& value : arr) {
        countMap[value]++;
    }

    vector<int> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = countMap[arr[i]];
    }

    cout << "[ ";
    for (const auto& count : result) {
        cout << count << " ";
    }
    cout << "]" << endl;

    return 0;
}