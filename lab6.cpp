class Solution {
public:

    bool isMatch(const string& s, const string& p) {
        int sLen = s.length(); // O(1)
        int pLen = p.length(); // O(1)
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false)); // O(n*m)
        dp[0][0] = true;

        for (int j = 1; j <= pLen; j++) { // O(m) - сложность, O(1) - память
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= sLen; i++) { // O(n)
            for (int j = 1; j <= pLen; j++) { // O(m)
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // O(1)
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // O(1)
                }
            }
        }

        return dp[sLen][pLen];
    }
    // Сложность - O(n*m), Память - O(n*m)
};
