#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <unordered_set>


std::vector<int> arraySampler(int n, std::vector <int> arr, int k){
    std::random_device rd; // O(1)
    std::mt19937 seed(rd()); // O(1)
    for (int i = k; i < n; ++i){ // O(n - k)
        int ind = seed() % k; // O(1)
        if (ind < k) arr[ind] = arr[i]; // O(1)
    }
    arr.resize(k); // O(1)
    return arr;
}


bool check(std::vector<int> arr, int n, std::vector<int> res, int k){
    if (arr.size() != n  || res.size() != k) return false;

    std::unordered_set<int> unique(res.begin(), res.end());
    if (res.size() != unique.size()) return false;

    return true;
}


void test(){
    std::random_device rd;
    std::mt19937 seed(rd());
    int n = seed() % 1000;
    int k = seed() % 1000;
    if (k > n) k -= n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = i;
    
    assert(check(arr, n, arraySampler(n, arr, k), k));
}


int main(){
    int size, k;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) std::cin >> arr[i];
    std::cin >> k;
    
    std::vector<int> arr2 = arraySampler(size, arr, k);
    for (int i = 0; i < k; ++i) std::cout << arr2[i] << ' ';
    test();
}