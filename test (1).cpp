#include <iostream>
#include <vector>




using namespace std;
void removeDuplicates(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ) {
            if (arr[i] == arr[j]) {
                arr.erase(arr.begin() + j);
            } else {
                j++;
            }
        }
    }
}



int main() {
    vector<int> arr = {1, 2, 3, 1};

    removeDuplicates(arr);

    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}
