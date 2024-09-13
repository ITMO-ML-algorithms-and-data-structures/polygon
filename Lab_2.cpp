#include <iostream> 
#include <vector> 
#include <set>

using namespace std;

vector<int> findUniqueElements(const int arr[], size_t size) {
    vector<int> un_el;

    for (size_t i = 0; i < size; i++) {
        bool is_duplicate = false;

        for (int j = 0; j < un_el.size(); j++) {
            if (arr[i] == un_el[j]) {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate) {
            un_el.push_back(arr[i]);
        }
    }
    return un_el;
}


int main() {
    int size = 10;
    int arr[] = { 1, 2, 3, 3, 1, 4, 5, 6, 5, 9 };

    vector<int> unique_elements = findUniqueElements(arr, size);

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
