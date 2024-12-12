#include <iostream>
#include <vector>
using namespace std;

int solve(string s, string p){
	int m = s.size();
					int n = p.size();

					vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

					dp[0][0] = true;

					for (int j = 1; j <= n; ++j) {
							if (p[j - 1] == '*') {
									dp[0][j] = dp[0][j - 2];
							}
					}

					for (int i = 1; i <= m; ++i) {
							for (int j = 1; j <= n; ++j) {
									if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
											dp[i][j] = dp[i - 1][j - 1];
									} else if (p[j - 1] == '*') {
											dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
									}
							}
					}

					return dp[m][n];
}

signed main(void){
	ios::sync_with_stdio(0); cin.tie(0);

	string s, p;
	cin >> s >> p;
	solve(s, p);

}