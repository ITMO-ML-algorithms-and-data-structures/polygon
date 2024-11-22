#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

vector<int> findUniqueElements(const vector<int>& arr) {
    set<int> unique_set(arr.begin(), arr.end());
    return vector<int>(unique_set.begin(), unique_set.end());
}

int main() {
    ifstream input_file("test.txt");

    vector<int> arr;
    int value;
    while (input_file >> value) {
        arr.push_back(value);
    }
    input_file.close();

    vector<int> unique_elements = findUniqueElements(arr);

    for (int elem : unique_elements) {
        cout << elem << " ";
    }

    return 0;
}

//Переменная size — 4 байта. 
//Массив arr[10] — 10 элементов * 4 байта = 40 байт. 
//Объект vector<int> - в этом примере un_el будет содержать 7 уникальных элементов(1, 2, 3, 4, 5, 6, 9), итого: 
//7 × 4 = 28 байт 
//Переменные цикла i, j, и is_duplicates — 4 + 4 + 1 = 9 байт 
//сумма = 105 байт
