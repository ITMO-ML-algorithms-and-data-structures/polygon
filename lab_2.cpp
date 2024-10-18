#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> arr = {1, 2, -1, 1};
    
    unordered_map<int, int> F;
    for (int val : arr) {
        if (val != -1) {
            F[val]++; 
        }
    }
    
    int most_frequent = -1;
    int max_count = 0;
    
    for (auto& entry : F) {
        if (entry.second > max_count) {
            most_frequent = entry.first;
            max_count = entry.second;
        }
    }

    for (int& val : arr) {
        if (val == -1) {
            val = most_frequent;
        }
    }

    cout << "Результат: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}