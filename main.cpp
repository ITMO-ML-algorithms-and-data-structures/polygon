#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    // тесты
    vector<int> test0 = {1, 2, 3, 1}; // test0: 8 байт (указатель) + 4 байта (size) + 4 байта (capacity) + 4 * 4 байта (элементы) = 24 байта
    vector<int> test1 = {1, 2, 2, 3, 4, 4, 5}; // test1: 8 байт (указатель) + 4 байта (size) + 4 байта (capacity) + 7 * 4 байта (элементы) = 40 байт
    vector<int> test2 = {}; // test2: 8 байт (указатель) + 4 байта (size) + 4 байта (capacity) = 16 байт
    
    vector<int> vec = test0; // vec: 8 байт (указатель) + 4 байта (size) + 4 байта (capacity) + 4 * 4 байта (элементы) = 24 байта
    
    int size = vec.size(); // size: 4 байта (переменная типа int)

    vector<int> uniqueVec; // uniqueVec: 8 байт (указатель) + 4 байта (size) + 4 байта (capacity) = 16 байт
    bool isUnique; // isUnique: 1 байт 

    for (int i = 0; i < size; i++) {
        isUnique = true; // isUnique: 1 байт 
        for (int j = 0; j < uniqueVec.size(); j++) {
            if (vec[i] == uniqueVec[j]) {
                isUnique = false; // isUnique: 1 байт 
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