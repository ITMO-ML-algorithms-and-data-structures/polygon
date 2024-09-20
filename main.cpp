#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <unordered_set>
using namespace std;

bool isSquare(int n) {
    int sqrt_n = sqrt(n);
    return(sqrt_n * sqrt_n == n);
}

int main() {
    string input_line;
    getline(cin, input_line);

    vector<int> arr;

    stringstream ss(input_line);

    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    ///////////////////////////
    int n = arr.size();
    vector<int> prefS(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefS[i + 1] = prefS[i] + arr[i];
    }

    //////////////////////
    unordered_set<string> uniqArrays;

    for (int st = 0; st < n; ++st) {
        for (int end = st; end < n; ++end) {
            int sum = prefS[end + 1] - prefS[st];

            if (isSquare(sum)) {
                string subArr;
                for (int j = st; j <= end; ++j) {
                    subArr += to_string(arr[j]) + " ";
                }
                subArr.pop_back();
                uniqArrays.insert(subArr);
            }
        }
    }

    cout << "подмассивы: " << endl;
    for (auto& x : uniqArrays) {
        cout << x << endl;
    }

    return 0;
}