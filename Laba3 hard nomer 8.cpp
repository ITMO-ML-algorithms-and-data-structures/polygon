#include <iostream>
#include <random>
#include <vector>
using namespace std;

void shuffleArray(vector<int>& array) {
    minstd_rand gen(random_device{}()); // несколько килобайт (обычно менее 1 КБ)
    shuffle(array.begin(), array.end(), gen);
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);            

    size_t size; //обычно 8 байт 
    cin >> size;

    vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {  // i = по 8 байт каждая
        cin >> arr[i]; //размер массива = n * 4 байт
    }

 
    shuffleArray(arr);

  
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << (i < size - 1 ? ' ' : '\n');
    }

    return 0;
}

//пример Память= количество элементов * 4 байт