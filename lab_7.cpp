#include <iostream>
#include <vector>
#include <queue>


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& expWage, int k) {
        int n = expWage.size();
        
        vector<pair<double,int>> workers(n);
        for(int i=0; i<n; i++){
            double ratio = (double)expWage[i] / quality[i];
            workers[i] = {ratio, quality[i]};
        }
        sort(workers.begin(), workers.end());
        
        priority_queue<int, vector<int>> maxHeap;
        int sumHeap = 0;
        for(int i=0; i<k; i++){
            maxHeap.push(workers[i].second);
            sumHeap+=workers[i].second;
        }
        double captainRatio = workers[k-1].first;
        double minCost = captainRatio * sumHeap;
        
        for(int captain=k; captain<n; captain++){
            captainRatio = workers[captain].first;
            
            if(!maxHeap.empty() && workers[captain].second < maxHeap.top()){
                sumHeap -= maxHeap.top();
                maxHeap.pop();
                maxHeap.push(workers[captain].second);
                sumHeap += workers[captain].second;
            }
            double cost = captainRatio * sumHeap;
            minCost = min(minCost, cost);
        }
        return minCost;
    }
};