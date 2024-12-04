#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <cassert>
#define ll long long

using namespace std;

vector <vector <ll> > your_fucking_result (const vector <vector<ll>>& sets, const vector <ll>& universe){
    vector <vector <ll>> result;
    
    vector <ll> uncovered = universe;

    while (!uncovered.empty()){
        ll ind = -1, mx_cover = 0; 
        for (int i = 0; i < sets.size(); i++){
            ll cover = 0;
            for (int el : sets[i]){
                if (count(uncovered.begin(), uncovered.end(), el)) cover++;
            }   
            if (cover > mx_cover){
                ind = i;
                mx_cover = cover;
            } 
        }
        if (ind == -1) break;

        for (int el : sets[ind]) uncovered.erase(remove(uncovered.begin(), uncovered.end(), el), uncovered.end());
        result.push_back(vector<ll>());
        result.back().insert(result.back().begin(), sets[ind].begin(), sets[ind].end());
      
    }
    sort(result.begin(), result.end());
    return result;
}

int main(){
    // ifstream fin("test0.txt");
    // ofstream fout("test_result.txt");

    // ll set_s, uni_s; fin >> set_s >> uni_s;
    // vector <vector <ll> > sets(set_s);
    // vector <ll> universe(uni_s);

    // for (int i = 0; i < set_s; i++){
    //     ll n; fin >> n;
    //     sets[i].resize(n);
    //     for (int j = 0; j < n; j++) fin >> sets[i][j];
    // }
    // for (int i = 0; i < uni_s; i++) fin >> universe[i];
    
    vector <vector <ll> > sets = {{1, 2}, {1, 2, 3}, {2, 4, 5}};
    vector <ll> universe = {1, 2, 4, 5};
    cout << "Answer: ";
    vector <vector<ll>> result = your_fucking_result(sets, universe);
    
    for (int i = 0; i < result.size(); i++){
        cout << "{ ";
        for (int el : result[i]) cout << el << " ";
        cout << "} ";
    }
    return 0;
}