#include <functional>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int array_length, target;
    cin >> array_length;
    vector<int> array(array_length);
    for (int i = 0; i < array_length; i++) {
        cin >> array[i];
    }
    cin >> target;
    unordered_map<int, int> first_map;
    first_map[0] = 1;
    first_map[array[0]] += 1;

    for (int i = 1; i < array_length; i++) {
        unordered_map<int, int> second_map;
        for (auto& pair : first_map) {
            second_map[pair.first] += pair.second;
            second_map[pair.first + array[i]] += pair.second;
        }
        for (auto& pair : second_map) {
            first_map[pair.first] = second_map[pair.first];
        }
    }

    cout << first_map[target];
}