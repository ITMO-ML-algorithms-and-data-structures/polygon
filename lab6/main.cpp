#include <vector>

using std::vector;

class Solution {

public:
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
            }
        // 
        vector<int> dp(31,0);
        dp[0]=1;
        for(int i = 1;i < 31; i++){
            dp[i]=dp[i-1]*2 + 1;
        }
        int steps=0;
        int sign=1;
        for(int i = 30;i >= 0; i--){
            if(n & (1 << i)){
                steps += dp[i] * sign;
                sign = 0 - sign;
            }
            
        }
        return steps;
    }
};