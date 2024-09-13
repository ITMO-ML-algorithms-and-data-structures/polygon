#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
    test                                S               answer
    {1, 1, 1, 1}                        1               1
    {4, 6, 4}                           10              1
    {-14, 16, 7, 22, -20, 10, 14}       35              2

*/



bool check_unique_sub(vector<vector<int>> unique_subs, vector<int> sub) {
    for (vector <int> el : unique_subs){
        if (el.size() == sub.size()){
            sort(sub.begin(), sub.end());
            if (el == sub) {
                return false;
            }
        }
    }

    return true;
}


int main(){
    int S, sum = 0, cnt = 0;
    vector<vector<int>> subs, tests = {{1, 1, 1, 1}, {4, 6, 4}, {-14, 16, 7, 22, -20, 10, 14}};
    vector<int> arr, s_tests = {1, 10, 35};

    for (int test = 0; test < tests.size(); test++) {
        arr = tests[test];
        S = s_tests[test];
        sum = 0;
        cnt = 0;

        int len_arr = arr.size();
        
        for (int l = 0; l < len_arr; l++) {
            for (int r = l; r < len_arr - l; r++){
                vector<int> sub(arr.begin() + l, arr.begin() + r + 1);

                if (check_unique_sub(subs, sub)) {
                    sort(sub.begin(), sub.end());
                    subs.push_back(sub);
                    sum = accumulate(sub.begin(), sub.end(), 0);

                    if (sum == S) {
                        cnt++;
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}