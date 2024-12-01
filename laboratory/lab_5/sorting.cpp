#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <cmath> 
#include <string>
#include <fstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <deque>
#include "sorting.h"

#define ll long long
using namespace std;

void shaker_sort(vector <ll> &ass){
    ll l = 0, r = ass.size() - 1;
    while (l < r){
        for (int i = l; i < r; i++){
            if (ass[i] > ass[i+1]) swap(ass[i], ass[i+1]);  
        }
        r--;
        for (int i = r; i > l; i--){
            if (ass[i] < ass[i-1]) swap(ass[i], ass[i-1]);
        }
        l++;
    } 
}


void merge(vector<ll> &ass, int l, int r){
    vector <ll> temp_merge;
    int i = l, mid = (l + r) / 2, j = mid;
    
    while (i < mid && j < r){
        temp_merge.push_back(min(ass[i], ass[j]));
        (ass[i] <= ass[j] ? i : j)++;
    }
    while (i < mid){
        temp_merge.push_back(ass[i]);
        i++;
    }
     while (j > r){
        temp_merge.push_back(ass[j]);
        j++;
    }
    for (int k = 0; k < temp_merge.size(); k++) ass[l + k] = temp_merge[k];
}

void merge_sort(vector <ll> &ass, int left, int right){
    if (left + 1 >= right) return;
    merge_sort(ass, left, (right+left) / 2);
    merge_sort(ass, (right+left) / 2, right);
    merge(ass, left, right);
} 


void heap(vector <ll> &ass, int n, int jj){ 
    int maxel = jj, first = 2 * maxel + 1, second = 2 * maxel + 2;

    if (first < n && ass[first] > ass[maxel]) maxel = first;

    if (second < n && ass[second] > ass[maxel]) maxel = second;

    if (maxel != jj){
        swap(ass[maxel], ass[jj]);
        heap(ass, n, maxel);
    }
}

void heap_sort(vector <ll> &ass){
    int n = ass.size();
    for(int i = n / 2 - 1; i >= 0; i--) heap(ass, n, i);

    for (int i = n - 1; i > 0; i--){
        swap(ass[0], ass[i]);
        heap(ass, i, 0);
    }
}

// int main(){
//     vector <ll> ass = {1, 4, 3, 4, 4, 4, 5, 6, 7, 8};
//     // shaker_sort(ass);
//     // merge_sort(ass, 0, ass.size());
//     heap_sort(ass);
//     for (int i = 0; i < ass.size(); i++) cout << ass[i] << " ";
// }