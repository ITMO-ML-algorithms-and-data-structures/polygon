#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int>> next_let;
        for (int i = 0; i < l2; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < l1; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == l2) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            next_let.push_back({cnt, j});
        }
        int ans = 0;
        int j = 0;
        for (int i = 0; i < n1; i++) {
            ans += next_let[j][0];
            j = next_let[j][1];
        }
        return ans / n2;
    }
};

int main() {
    string s1 = "acb", s2 = "ab";
    int n1 = 4, n2 = 1;
    Solution solution;
    int ans = solution.getMaxRepetitions(s1, n1, s2, n2);
    cout << ans << endl;
}