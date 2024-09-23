#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void delete_duplicates(vector<int>& array) { // вектор весит 4*n байтов
    sort(array.begin(), array.end());
    array.erase(unique(array.begin(), array.end()), array.end());
}

vector<int> read_vector_from_file(const string& filename) {
    ifstream input_file(filename);
    vector<int> array;
    int number; // 4 байта
    while (input_file >> number) {
        array.push_back(number);
        input_file.ignore(1, ';'); // 1 байт
    }
    return array;
}

int main() {
    string filename = "numbers.txt"; //32 байта
    vector<int> array = read_vector_from_file(filename); // 4 * n байт

    delete_duplicates(array);

    for (int i : array) {
        cout << i << " "; //4 байта
    }
    cout << endl;

    return 0;
}