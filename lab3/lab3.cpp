#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <unordered_set>

// O(n - k)
std::vector<int> arraySampler(int n, std::vector <int> arr, int k){
    std::random_device rd; // O(1)
    std::mt19937 seed(rd()); // O(1)
    for (int i = k; i < n; ++i){ // O(n - k)
        int ind = seed() % k; // индекс элемента, на который мы будем заменять текущий O(1)
        if (ind < k) arr[ind] = arr[i]; // O(1) // Если индекс больше k (не сущ в массиве), то заменяем i на ind элемент
    }
    arr.resize(k); // Итоговый массив O(1)
    return arr;
}


// Проверка на правильное сэмплирование
bool check(std::vector<int> arr, int n, std::vector<int> res, int k){
    if (arr.size() != n  || res.size() != k) return false; // Размеры должны совпадать

    std::unordered_set<int> unique(res.begin(), res.end());
    if (res.size() != unique.size()) return false; // Каждый элемент уникальный

    return true;
}


// Тест
void test(){
    std::random_device rd;
    std::mt19937 seed(rd());
    int n = seed() % 1000; // Размер массива
    int k = seed() % 1000; // Размер нового массива
    if (k > n) k -= n; // Проверка на то, что размер нового массива не больше старого

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = i;
    
    assert(check(arr, n, arraySampler(n, arr, k), k)); // Проверка на корректное сэмплирование
}


int main(){
    int size, k;
    // Входные данные 
    std::cin >> size; // Размер массива
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) std::cin >> arr[i]; // Массив
    std::cin >> k; // Размер итогово массива
    
    std::vector<int> arr2 = arraySampler(size, arr, k); // Сэмплированный массив
    for (int i = 0; i < k; ++i) std::cout << arr2[i] << ' ';
    
    test();
}