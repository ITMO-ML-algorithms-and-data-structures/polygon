#include <iostream>
using namespace std;

class Solution {
    public:
        int minNumberOperations(vector<int>& target) {
            int answer = target[0];
            for (int i = 1; i < target.size(); i++) {
                if (target[i] > target[i - 1]) {
                    answer += target[i] - target[i - 1];
                }
            }
            return answer;
    }
};