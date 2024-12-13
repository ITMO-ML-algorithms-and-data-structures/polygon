#include <iostream>
using namespace std;

class Solution {
    public:
        int minNumberOperations(vector<int>& target) {
            // память короче немного
            int answer = target[0];
            // сложность цикла O(N)
            for (int i = 1; i < target.size(); i++) {
                if (target[i] > target[i - 1]) {
                    answer += target[i] - target[i - 1];
                }
            }
            return answer;
    }
};
// итого память O(1), время O(N)