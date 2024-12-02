#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isValid(const vector<pair<int, int>>& subset) { //made a bool with that parameters
    unordered_set<int> used; // we made an unordered called used //we save here every number that already apears in subset
    for (const auto& p : subset) { //we made a bucle with better logic
        if (used.count(p.first) || used.count(p.second)) {// verify p in the first posicion or the second one in the used group
            return false;// if it already any of them already exist subset is not valid
        }
        used.insert(p.first);//if not exist we add to used
        used.insert(p.second);//if not exist we add to used
    }
    return true;//we show that the subconj is valid
}


//we made a vector with to find the  pair that works or a single element if it doesnt work
//we need a vector with pairs
vector<vector<int>> findMaxMatching(const vector<pair<int, int>>& pairs) {
    int n = pairs.size();//the size of pairs save in n
    vector<pair<int, int>> maxSubset; // vector to save the final exit


    for (int mask = 0; mask < (1<<n); ++mask) { //
        vector<pair<int, int>> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) {
                subset.push_back(pairs[i]);
            }
        }
        if (isValid(subset) && subset.size() > maxSubset.size()) {
            maxSubset = subset;
        }
    }


    unordered_set<int> included;
    for (const auto& p : maxSubset) {
        included.insert(p.first);
        included.insert(p.second);
    }

    unordered_set<int> singlesSet;
    for (const auto& p : pairs) {
        if (!included.count(p.first)) singlesSet.insert(p.first);
        if (!included.count(p.second)) singlesSet.insert(p.second);
    }


    vector<vector<int>> result;
    for (const auto& p : maxSubset) {
        result.push_back({p.first, p.second});
    }
    for (int single : singlesSet) {
        result.push_back({single});
    }

    return result;
}

int main() {

    vector<pair<int, int>> pairs = {{3, 2}, {2, 6}, {2, 4},{6,5},{5,2},{1,7}};

    vector<vector<int>> result = findMaxMatching(pairs);

    cout << "Maximum agreement:" << endl;
    for (const auto& group : result) {
        cout << "(";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i + 1 < group.size()) cout << ", ";
        }
        cout << ")" << endl;
    }

    return 0;
}
