#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isCover(vector<set<int>> sets, set<int> universe, vector<int> combination) {
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

vector<set<int>> findCover(vector<set<int>> sets, set<int> universe) {
    int n = sets.size();
    int min_size = numeric_limits<int>::max();
    vector<set<int>> best;

    for (int subset_size = 1; subset_size <= n; subset_size++) {
        vector<int> combination(subset_size);
        for (int i = 0; i < subset_size; i++) {
            combination[i] = i;
        }

        while (nextCombination(combination, n)) {
            if (isCover(sets, universe, combination)) {
                min_size = subset_size;
                best.clear();
                for (int index : combination) {
                    best.push_back(sets[index]);
                }
            }
            
            if (min_size != numeric_limits<int>::max()) {
                break;
            }
        }
        
        nextCombination(combination, n);
        if (isCover(sets, universe, combination)) {
            min_size = subset_size;
            best.clear();
            for (int index : combination) {
                best.push_back(sets[index]);
            }
        }

        
    }

    return best;
}

void Testing(vector<set<int>> sets, set<int> universe) {
    auto start = high_resolution_clock::now();
    vector<set<int>> result = findCover(sets, universe);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    
    cout << "[ ";
    for (const set<int>& s : result) {
        cout << "{ ";
        for (int item : s) {
            cout << item << " ";
        }
        cout << "} ";
    }
    cout << "]\n";
    cout << "Тест занял: " << duration.count() << " мс" << endl;
}

int main() {
    // Тест 1: 3 множеств, 4 элементов
    vector<set<int>> sets1 = {{1, 2}, {2, 3}, {3, 4}};
    set<int> universe1 = {1, 2, 3, 4};
    cout << "Тест 1:\n";
    Testing(sets1, universe1);

    // Тест 2: 4 множеств, 10 элементов
    vector<set<int>> sets2 = {{1, 5, 9}, {2, 5, 6, 7}, {3, 8}, {4, 10}};
    set<int> universe2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Тест 2:\n";
    Testing(sets2, universe2);

    // Тест 3: 15 множеств, 30 элементов
    vector<set<int>> sets3 = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12},
        {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24},
        {25, 26, 27}, {28, 29, 30}, {1, 10, 20}, {5, 15, 25},
        {3, 8, 12, 17}, {2, 6, 18, 24}, {11, 13, 14}
    };
    set<int> universe3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                          11, 12, 13, 14, 15, 16, 17, 18,
                          19, 20, 21, 22, 23, 24, 25, 26,
                          27, 28, 29, 30};
    cout << "Тест 3:\n";
    Testing(sets3, universe3);

    // Тест 4: 20 множеств, 40 элементов
    vector<set<int>> sets4 = {
        {1, 5, 10, 15}, {2, 6, 11, 16}, {3, 7, 12, 17}, {4, 8, 13, 18},
        {9, 14, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32},
        {33, 34, 35, 36}, {37, 38, 39, 40}, {1, 6, 11, 16, 21}, {2, 7, 12, 17, 22},
        {3, 8, 13, 18, 23}, {4, 9, 14, 19, 24}, {5, 10, 15, 20, 25},
        {26, 27, 28, 29, 30}, {31, 32, 33, 34, 35}, {36, 37, 38, 39, 40},
        {1, 2, 3, 4, 5}, {15, 25, 35, 30, 20}
    };
    set<int> universe4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                          15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                          27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                          39, 40};
    cout << "Тест 4:\n";
    Testing(sets4, universe4);

    // Тест 5: 25 множеств, 50 элементов
    vector<set<int>> sets5 = {
        {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}, {31, 32, 33, 34, 35}, {36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}, {1, 11, 21, 31, 41}, {2, 12, 22, 32, 42},
        {3, 13, 23, 33, 43}, {4, 14, 24, 34, 44}, {5, 15, 25, 35, 45},
        {6, 16, 26, 36, 46}, {7, 17, 27, 37, 47}, {8, 18, 28, 38, 48},
        {9, 19, 29, 39, 49}, {10, 20, 30, 40, 50}, {1, 10, 20, 30, 40, 50},
        {5, 15, 25, 35, 45}, {4, 14, 24, 34, 44}, {3, 13, 23, 33, 43},
        {2, 12, 22, 32, 42}
    };
    set<int> universe5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
                          17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
                          45, 46, 47, 48, 49, 50};
    cout << "Тест 5:\n";
    Testing(sets5, universe5);

    return 0;
}




