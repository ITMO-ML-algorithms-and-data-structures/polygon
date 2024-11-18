// удалить дублирующиеся значения из входного массива

#include <iostream>
#include <fstream>  
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

vector<short int> read_file(const string& filename) {
    vector<short int> arr; // (O(1)) создание вектора
    
    ifstream in(filename); // открытие файла для чтения
    short int number; // (O(1+1))
    
    while (in >> number) {
        arr.push_back(number);
        // считывает числа из файла и добавляет их в вектор
    }

    return arr;
}

int main(){
    vector<short int> arr = read_file("numbers3.tsv"); //(O(N))

    unordered_set<short int> num(arr.begin(), arr.end()); // (O(1))

    list<short int> unique; // (O(1))
    short int N = num.size(); // (O(1+1+1))

    for (int i = 0; i < N; i++) { // (O(1 + 1), O(1 + 1))
        // (O(1 + 1 + 1...)) = O(N) - для каждого элемента
        if ((num.size() == 0) || (num.find(arr[i]) == num.end())) {
            // (O(1 + 1 + 1|| + 1 + 1 + 1== + 1))
            unique.push_back(arr[i]); // (O(1))
            num.insert(arr[i]); //(O(1))
        }
    }
    // в худшем случае O(N)
    // в лучшем - O(1)
    // в среднем O(N)
    vector<short int> res(unique.begin(), unique.end());

    for (int i : num) {  
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
