#include <iostream>      // O(1)
#include <vector>        // O(1)
#include <set>           // O(1)
#include <limits>        // O(1)

using namespace std;

bool isCover(const set<int>& X, const vector<set<int>>& subsets, const vector<bool>& selected) {
    set<int> unionSet;   // O(1)
    for (size_t i = 0; i < subsets.size(); ++i) {   // O(m)
        if (selected[i]) {  // O(1)
            unionSet.insert(subsets[i].begin(), subsets[i].end());  // O(n * log(n))
        }
    }
    return unionSet == X;    // O(n)
}

int countSelected(const vector<bool>& selected) {
    int count = 0;       // O(1)
    for (bool sel : selected) {   // O(m)
        if (sel) {       // O(1)
            ++count;     // O(1)
        }
    }
    return count;        // O(1)
}

pair<vector<set<int>>, int> findMinimalCover(const set<int>& X, const vector<set<int>>& subsets) {
    int m = subsets.size();   // O(1)
    int minSize = numeric_limits<int>::max();   // O(1)
    vector<set<int>> minCover;   // O(1)

    for (int mask = 0; mask < (1 << m); ++mask) {   // O(2^m)
        vector<bool> selected(m, false);   // O(m)
        for (int i = 0; i < m; ++i) {      // O(m)
            if (mask & (1 << i)) {         // O(1)
                selected[i] = true;        // O(1)
            }
        }

        if (isCover(X, subsets, selected)) {    // O(m * n * log(n))
            int count = countSelected(selected);    // O(m)
            if (count < minSize) {             // O(1)
                minSize = count;               // O(1)
                minCover.clear();              // O(1)
                for (int i = 0; i < m; ++i) {  // O(m)
                    if (selected[i]) {         // O(1)
                        minCover.push_back(subsets[i]);  // O(1) (амортизировано)
                    }
                }
            }
        }
    }

    return {minCover, minSize};   // O(1)
}

int main() {
    set<int> X = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, //O(1)
              11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
              21, 22, 23, 24, 25};

vector<set<int>> subsets = { //o(1)
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15},
    {16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {1, 4, 7, 10}, 
    {11, 14, 17, 20}, {21, 24, 25}, {3, 6, 9, 12}, 
    {5, 10, 15, 20}, {18, 22, 25}, {8, 16, 24}
};


    auto result = findMinimalCover(X, subsets);    // O(2^m * m * n * log(n))

    cout << "minimum coverage consists of " << result.second << " sets:\n";   // O(1)
    for (const auto& subset : result.first) {    // O(m)
        cout << "{ ";                            // O(1)
        for (int elem : subset) {                // O(n)
            cout << elem << " ";                 // O(1)
        }
        cout << "}\n";                         // O(1)
    }

    return 0;   // O(1)
}
// итог работает за 2**m где m - кол-во подмножеств данных для покрытия