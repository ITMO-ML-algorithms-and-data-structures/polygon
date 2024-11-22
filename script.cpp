#include <iostream>
#include <vector>

using namespace std;

vector<int> sampleArray(const vector<int>& arr, int K) {
    //O(n)
    vector<int> result;
    int N = arr.size();

    if (K == 0 || N == 0 || K > N) return result;

    int step = N / K;

    for (int i = 0; i < K; ++i) {
        result.push_back(arr[i * step]);
    }

    return result;
}