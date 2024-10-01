#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> removeDuplicates(vector<int>& vec) { // 24 bytes
    vector<int> vecNew; // 24 bytes

    for (int i = 0; i < vec.size(); i++) { // int 4 bytes
        bool isDuplicate = false; // 1 byte

        for (int j = 0; j < vecNew.size(); j++) { // int 4 bytes
            if (vec[i] == vecNew[j]) { // 4 и 4 bytes
                isDuplicate = true; // 1 byte
                break;
            }
        }       
        if (!isDuplicate) {
            vecNew.push_back(vec[i]); // 4 bytes
        }
    }
    return vecNew; // 24 bytes
}


vector<int> readVectorFromFile(const string& filename) { // 32 bytes
    ifstream inputFile(filename); // 32 bytes
    vector<int> vec;  // 24 bytes

    int number; //4 bytes
    while (inputFile >> number) {  // 4 bytes int
        vec.push_back(number);  // 4 bytes
    }
    inputFile.close(); 
    return vec; // 24 vytes
}


int main() {
    vector<int> vec = readVectorFromFile("numbers.txt"); // 24 bytes + 4*n bytes, n - колво элем.
    vector<int> vecNew = removeDuplicates(vec); // 24 bytes + 4*n bytes 

    for (int i : vecNew) { // 4 bytes
        cout << i << " ";
    } // Весь вывод - 4*n bytes, зависит от длины вектора 
    return 0;
}
