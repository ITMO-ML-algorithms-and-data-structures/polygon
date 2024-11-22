#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

vector<int> removeDuplicates(vector<int>& vec) { 
    vector<int> vecNew; // 24 bytes

    for (int i = 0; i < vec.size(); i++) { // int 4 bytes
        bool isDuplicate = false; // 1 byte

        for (int j = 0; j < vecNew.size(); j++) { 
            if (vec[i] == vecNew[j]) { // 4 и 4 bytes
                isDuplicate = true; // 1 byte
                break;
            } // Итого переменные 4+4+1 = 9 байт
        }       
        if (!isDuplicate) {
            vecNew.push_back(vec[i]); // 24 + i*4 bytes 
        }
    
    }
    return vecNew; // 4i + 4n  + 24 + 4 + 4 + 1 bytes = 4i + 4n + 33 bytes - итоговая память функции, (худший случай, если все уникальные, то i=n, 8n+33)
    // где 4i - исходный вектор,
    //  4n+24 - новый вектор,  4 + 4 + 1 = переменные i,j и bool в циклах. Максимальный размер в строке vecNew.push_back(vec[i]), равно
    // 4n+4i+37 bytes
    
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
    } // Весь вывод - 4*n bytes
    return 0;
}
