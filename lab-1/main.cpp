#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> test0 = {1, 2, 3, 1};
    vector<int> test1 = {1, 2, 2, 3, 4, 4, 5};
    vector<int> test2 = {};
    
    vector<int> vec = test0;
    
    int size = vec.size();

    vector<int> uniqueVec;
    bool isUnique;

    for (int i = 0; i < size; i++) {
        isUnique = true;
        for (int j = 0; j < uniqueVec.size(); j++) {
            if (vec[i] == uniqueVec[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueVec.push_back(vec[i]);
        }
    }

    for (int i = 0; i < uniqueVec.size(); i++) {
        cout << uniqueVec[i] << " ";
    }
    cout << endl;

    return 0;
}