#include <iostream>
#include <fstream>  
#include <vector>
#include <algorithm> 

using namespace std;

void DeleteDuplicates(vector<int>& array) {
    // Сортировка, могу объяснить работу
    sort(array.begin(), array.end());

    // Само удаление дубликатов
    auto last = unique(array.begin(), array.end());

    // Изеняет размер вектора, чтобы убрать неопределенные элементы
    array.erase(last, array.end());
}

vector<int> ReadVectorFromFile(const string& filename) {
    
    ifstream inputFile(filename);
    vector<int> array; 
    // cout << sizeof(array); 24b
    int number;
    char tab;
    //    cout << sizeof(number) << " " << sizeof(tab); number = 4, tab = 1
    while (inputFile >> number) {
        array.push_back(number);
        inputFile >> tab;  // Как-то убирает табы GPT
    }
    // cout << sizeof(array); 24 bytes
    inputFile.close();
    return array;
}

int main() {
    
    string filename = "numbers.txt";
    //cout << sizeof(filename); 32b

    vector<int> array = ReadVectorFromFile(filename);
    // cout << sizeof(array); 24b

    DeleteDuplicates(array);

    
    for (int i = 0; i < array.size(); i++) {
        cout << i << " ";
    }
    cout << endl;
    // cout << sizeof(array); 24 bytes

    return 0;
}
