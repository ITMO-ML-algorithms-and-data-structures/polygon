#include <iostream>
#include <fstream>  
#include <vector>
#include <algorithm> 

using namespace std;

void DeleteDuplicates(vector<int>& array) { //8 байт
    sort(array.begin(), array.end());   
    array.erase(unique(array.begin(), array.end()), array.end()); 
}

vector<int> ReadVectorFromFile(const string& filename) { // 8 байт
    
    ifstream inputFile(filename);
    vector<int> array; // 24 байта
    int number; // 4 байта
    
    while (inputFile >> number) { 
        array.push_back(number);
        inputFile.ignore(1, ';'); //1 байт
    }
    // Размер вектора будет равен 4*n байтов, где n - колво элементов 
    return array;
}

int main() {
    string filename = "numbers.txt"; // 32 байта
    vector<int> array = ReadVectorFromFile(filename); // 24 байта

    DeleteDuplicates(array);

    for (int i : array) {  
        cout << i << " "; // 4 байта
    }
    cout << endl;

    return 0;
}
