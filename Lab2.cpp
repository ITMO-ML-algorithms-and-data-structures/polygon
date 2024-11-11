#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

int main() {

    int size = 10;
    int arr[] = { 1,2,3,3,1,4,5,6,5,9 };

    vector<int> un_el;

    for (int i = 0; i < size; i++) {
        bool is_duplicetes = false;

        for (int j = 0; j < un_el.size(); j++) {
            if (arr[i] == un_el[j]) {
                is_duplicetes = true;
                break;
            }
        }
        if (!is_duplicetes) {
            un_el.push_back(arr[i]);
        }
    }
    for (int elem : un_el) {
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