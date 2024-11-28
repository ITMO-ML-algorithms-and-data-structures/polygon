#include <iostream>       
#include <vector>        
#include <unordered_set> 
// Удалить дублирующиеся значения из входного массива

int main() {                         
    int size;                    
    std::cin >> size;                
    
    std::vector<int> arr(size); // O(N) для выделения памяти
    for (int i = 0; i < size; ++i) { 
        std::cin >> arr[i];           // O(N) - считывание N элементов
    }                                 

    std::unordered_set<int> unique; // O(1) - выделение памяти для множества
    for (int num : arr) {            // O(N) - итерация по каждому элементу массива
        unique.insert(num);           // O(1) в среднем для добавления элемента в множество
    }                                 

    std::vector<int> res(unique.begin(), unique.end()); // O(K), где K - количество уникальных элементов
    for (int i = 0; i < res.size(); ++i) { 
        std::cout << res[i];       // O(K) - вывод K уникальных элементов
        if (i < res.size() - 1) {   
            std::cout << ", ";    
        }                              
    }                                           
    return 0;                        
}      
// Сложность алгоритма составляет:
// В лучшем случае(все элементы уникальные) - O(N)
// В худшем случае(все элементы повторяются) - O(N+K)
