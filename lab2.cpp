// удалить дублирующиеся значения из входного массива

#include <iostream>
#include <fstream>  
#include <vector>

using namespace std;

vector<short int> read_file(const string& filename) {
    vector<short int> arr; // (O(1)) создание вектора
    
    ifstream in(filename); // открытие файла для чтения
    short int number; // (O(1+1)) 2 байта 
    
    while (in >> number) {
        arr.push_back(number); // + 24 байта * N
        // считывает числа из файла и добавляет их в вектор
    }

    return arr;
}

int main(){
    vector<short int> arr = read_file("numbers.tsv"); // ( O(N + 1) ) заполнение вектора данными из файла
    short int N = arr.size(); //( O(1+1+1) ) + 2 байта 
    // размер вектора 
    vector<short int> unique; // ( O(1) ) вектор с уникальными значениями
    bool is_duplicate = false; // ( O(N)*O(1+1) ) + 1 байт
    for (int i = 0; i < N; i++) { // ( O(1+1),O(1+1) ) + 4 байта в рамках цикла
        // (O(1+1+1...))
        is_duplicate = false; // ( O(N*i+1) )
        
        for (int j = 0; j < i; j++) { //( O(N)*O(1+1),O(N)*O(1+1) )
            // ( O(N)*O(1+1+1...) = O(N)*O(i) = O(N*i) ) + 4 байта в рамках цикла
            if (i != j && arr[i] == arr[j]){ // ( O(N*i)*(O(1+1+1)) )  проверка на дубликаты
                is_duplicate = true; // ( O(N*i+1) )
            }
        }
        if (!is_duplicate) { // ( O(N+1+1) )
            unique.push_back(arr[i]); // + 24 байта * N
            // если дубликата нет, то элемент добавляется в вектор
        }
    }

    for (int i : unique) {  
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// На выходе имеем 2 + 24*N + 2 + 1 + 4 + 4 + 24*N = 13 + 48*N
// Максимальное число байт достигается в строке "unique.push_back(arr[i]);",
//  на последней итерации, и равно 24*N