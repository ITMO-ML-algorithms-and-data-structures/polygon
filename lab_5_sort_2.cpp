#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(const vector<int>& input_vec, const int& finish) {
    int ind_max = 0;
    for (int i = 1; i <= finish; i++){
        if (input_vec[i] > input_vec[ind_max]){
            ind_max = i;
        }
    }
    return ind_max;
}

void pancake_sort(vector<int>& input_vec) {
    for (int i = input_vec.size() - 1; i > 0; i--){
        int ind_max = find_max(input_vec, i);
        if (ind_max != i){
            reverse(input_vec.begin(), input_vec.begin() + ind_max + 1);
            reverse(input_vec.begin(), input_vec.begin() + i + 1);
        }
    }
}

