#include <iostream>
#include <vector>
#include <string>


const int MOD = 1000000007;

int main() {
    std::string s;
    std::cin >> s;

    for (char x : s) {
        if (x == 'w' || x == 'm') {
            std::cout << 0 << '\n';
            return 0;
        }
    }

    int n = s.size();
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    std::cout << dp[n] << '\n';

    return 0;
}
