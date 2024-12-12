#include <iostream>
#include <vector>

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        std::vector<std::vector<long long>> dp(goal + 1, std::vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] += dp[i - 1][j - 1] * (n - (j - 1)) % MOD;
                if (j > k) {
                    dp[i][j] += dp[i - 1][j] * (j - k) % MOD;
                }

                dp[i][j] %= MOD;
            }
        }

        return dp[goal][n];
    }
    
};