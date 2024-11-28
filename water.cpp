#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
        int n;
        n = height.size();
        int cur_m = 0;
        vector<int> max_l(n,0);
        vector<int> max_r(n,0);
        vector<int> ans(n,0);
        for (int i = 1; i < n; i++) {
            max_l[i] = max(height[i-1], max_l[i-1]);
            }
        for (int i = n - 2; i > 0; i--) {
            max_r[i] = max(height[i+1], max_r[i+1]);
            } 
        
        for (int i = 1; i < n; i++) {
            cur_m = min(max_l[i], max_r[i]);
            if (cur_m - height[i] > 0) { 
                ans[i] = ans[i-1] + cur_m - height[i];
            }
            else {ans[i] = ans[i-1];}
        }

        return ans[n-1];
    }

int main() {
    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    trap(vec);
    return 0;
}