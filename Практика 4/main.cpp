#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

bool isCover(const vector<set<int>> sets, set<int> universe, vector<int> combination) {
    for (int index : combination) {
        for (int item : sets[index]) { 
            universe.erase(item);
        }
    }
    return universe.empty();
}


bool nextCombination(vector<int>& combination, int n) {
    int k = combination.size();
    for (int i = k - 1; i >= 0; i--) {
        if (combination[i] < n - k + i) {
            combination[i]++;
            for (int j = i + 1; j < k; j++) {
                combination[j] = combination[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

vector<set<int>> findCover(vector<set<int>>& sets, set<int>& universe) {
    int n = sets.size();
    int min_size = numeric_limits<int>::max();
    vector<set<int>> best;

    for (int subset_size = 1; subset_size <= n; subset_size++) {
        vector<int> combination(subset_size);
        for (int i = 0; i < subset_size; i++) {
            combination[i] = i;
        }

        while (nextCombination(combination, n)) {
            if (isCover(sets, universe, combination) && subset_size < min_size) {
                min_size = subset_size;
                best.clear();
                for (int index : combination) {
                    best.push_back(sets[index]);
                }
            }
        }

        if (min_size != numeric_limits<int>::max()) {
            break;
        }
    }

    return best;
}

int main() {
    vector<set<int>> sets = {{1, 2}, {2, 3}, {3, 4}};
    set<int> universe = {1, 2, 3};

    vector<set<int>> result = findCover(sets, universe);
    cout << "[";
    for (set<int> set : result){
        cout << "{ ";
        for (int item : set) {
            cout << item << " ";
        }
        cout << "}";
    }
    cout << "]";
    

    return 0;
}
