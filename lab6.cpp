class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n, 0); // dp[i] хранит длину самой длинной корректной подстроки, заканчивающейся на индексе i
        int maxSize = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // Если текущая ')' образует пару с предыдущей '('
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    // Если текущая ')' образует пару с открывающей скобкой, которая находится перед предыдущей корректной подстрокой
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxSize = max(maxSize, dp[i]);
            }
        }

        return maxSize;
    }
};
