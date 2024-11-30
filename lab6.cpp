#include <vector>
using namespace std;


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int>  lst(n, 0);
       
        lst[0] = target[0];
       
        for (int i = 1; i < n; ++i) {
            if (target[i] > target[i - 1]) {
                lst[i] = lst[i - 1] + (target[i] - target[i - 1]);
            } else {
                lst[i] = lst[i - 1];
            }
        }
       
        return lst[n - 1];
    }
};
