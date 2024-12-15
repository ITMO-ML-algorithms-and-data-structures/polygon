#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int average(const vector<int> machines) {
        int sum = 0;
        int size = machines.size();
        for (int i = 0; i < size; i++) {
            sum += machines[i];
        }
        if (sum % size == 0) {
            return sum / size;
        }
        return -1;
    }
    
    int findMinMoves(vector<int> machines) {
        int avr = average(machines);
        if (avr == -1) {
            return -1;
        }
        int sum = 0;
        int minMoves = 0;
        for (int elem : machines) {
            sum += elem - avr;
            minMoves = max(minMoves, abs(sum), elem - avr);
        }
        return minMoves;
    }
};

int main() {
    vector machines = {1,0,5};
    Solution solution;
    cout << solution.findMinMoves(machines) << endl;
}
