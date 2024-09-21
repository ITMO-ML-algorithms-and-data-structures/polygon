#include <iostream>
#include <fstream>  
#include <vector>
#include <algorithm> 

using namespace std;

void DeleteDuplicates(vector<int>& vec) {
    // Сортировка, могу объяснить работу
    sort(vec.begin(), vec.end());

    // Само удаление дубликатов
    auto last = unique(vec.begin(), vec.end());

    // Изеняет размер вектора, чтобы убрать неопределенные элементы
    vec.erase(last, vec.end());
}

vector<int> ReadVectorFromFile(const string& filename) {
    
    ifstream inputFile(filename);
    vector<int> vec; 
    // cout << sizeof(vec); 24b
    int number;
    char tab;
    //    cout << sizeof(number) << " " << sizeof(tab); number = 4, tab = 1
    while (inputFile >> number) {
        vec.push_back(number);
        inputFile >> tab;  // Как-то убирает табы GPT
    }
    // cout << sizeof(vec); 24 bytes
    inputFile.close();
    return vec;
}

int main() {
    
    string filename = "numbers.txt";
    //cout << sizeof(filename); 32b

    vector<int> vec = ReadVectorFromFile(filename);
    // cout << sizeof(vec); 24b

    DeleteDuplicates(vec);

    
    for (int i = 0; i < vec.size(); i++) {
        cout << i << " ";
    }
    cout << endl;
    // cout << sizeof(vec); 24 bytes

    return 0;
}
