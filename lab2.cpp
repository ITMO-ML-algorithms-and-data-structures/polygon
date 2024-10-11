#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find_max(vector<int> array) {
    unordered_map<int, int> frequency;
    int most_frequent = array[0], max_count = 0;

    for (int num : array) {
        if (num != NULL)
            frequency[num]++;
    
        if (frequency[num] > max_count) {
            max_count = frequency[num];
            most_frequent = num;
        }
    } 
    return most_frequent;
}

vector<int> SimpleImputer(vector<int> array) {
    int replace = find_max(array);
    for (int i=0; i < array.size(); i++) {
        if (array[i] == NULL) array[i] = replace;
    }
    return array;
}

int main() {
    vector<int> test = {1, 2, NULL, 3, NULL, 1, 5, 2, NULL, 1, NULL, 4, 7, 2, 1};
    vector<int> new_test = SimpleImputer(test);
    cout << "[";
    for (int i=0; i < new_test.size(); i++)
        if (i == new_test.size()-1) 
            cout << new_test[i] << "]";
        else 
            cout << new_test[i] << ", ";
}