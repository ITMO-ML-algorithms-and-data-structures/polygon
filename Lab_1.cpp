// #include <iostream>
// #include <vector>

// int main() {
//     int size;
//     unsigned long long v;
//     std::cin >> size;   
//     std::vector<unsigned long long> arr; // прочитать сколько занимает памяти 
//     for (int s = 0; s < size; s++) {
//         std::cin >> v;
//         arr.push_back(v);
//     }
//     for (int i = 0; i < size; i++) {
//         for (int j = i+1; j < size; j++) {
//             if (arr[i] == arr[j]) {
//                 for (int n = j; n < (size - 1); n++) {
//                     arr[n] = arr[n + 1];
//                 }
//                 size--;
//                 j--;
//             }
//         } 
//     } 
    
//     for (int i = 0; i < size; i++) {
//         std::cout << arr[i] << " ";
//     }
// }

// // разобраться как удалять элементы 
// // разобраться с хэш таблицами


#include <iostream>
#include <vector>
#include <set>

// std::vector<int> removeDuplicates(const std::vector<int>& vec) {
//     std::set<int> uniqueElements(vec.begin(), vec.end());

//     return std::vector<int>(uniqueElements.begin(), uniqueElements.end());
// }

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5, 6, 6};

    // Удаление дубликатов
    std::set<int> uniq (numbers.begin(), numbers.end());
    std::vector<int> uniqNum (uniq.begin(), uniq.end());
    // Вывод результата
    std::cout << "Вектор без дубликатов: ";
    for (int num : uniqNum) {
        std::cout << num << " ";
    }

    return 0;
}
