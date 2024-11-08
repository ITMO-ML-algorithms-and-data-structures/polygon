#include <iostream>
#include <vector>
using namespace std;

bool isin(vector<int> arr, int target) {
    // O(N) - в худшем случае, нужно просмотреть весь массив
    for (int i = 0; i < size(arr); i++) {  
        // O(1) - доступ к элементу по индексу
        if (arr[i] == target) { 
            // O(1) - возврат из функции
            return true; 
        }
    }
    // O(1) - возврат из функции
    return false;  
}
int main() {
    int n, K;
    vector<int> arr; // O(1) - выделение памяти для вектора
    // O(1) - ввод данных
    cin >> n >> K;  
    int c = 0;
    while (cin >> c) {
        arr.push_back(c); // O(1) - добавление элемента в конец вектора (амортизированная сложность)
    }
    vector<int> ans; // O(1) - выделение памяти
    srand(static_cast<unsigned int>(time(0))); // O(1) - инициализация генератора случайных чисел
    vector<int> shuffled_arr = arr; // O(N) - копирование массива
    // O(K) - цикл для выборки K элементов
    for (int i = 0; i < K; ++i) {
        int j = rand() % n; // O(1) - выбор случайного индекса
        // O(N) - проверка уникальности выбранного элемента с помощью функции isin
        while (isin(ans, arr[j])) {
            j = rand() % n; // O(1) - повторный выбор случайного индекса
        }
        swap(shuffled_arr[i], shuffled_arr[j]); // O(1) - обмен элементов
    }
    // O(K) - создание вектора из первых K элементов
    ans = vector<int>(shuffled_arr.begin(), shuffled_arr.begin() + K); 
    // O(K) - вывод элементов вектора
    for (vector<int>::iterator i = ans.begin(); i != ans.end(); ++i) {
        cout << *i; // O(1) - вывод
        cout << " "; // O(1) - вывод
    }
}