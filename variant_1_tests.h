#ifndef variant_1_tests_h
#define variant_1_tests_h
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include "variant_1.h"
class Variant_1_tests {
  public:
  static void palindrome_test () {
    std::vector<std::string> test_strings{"madam","mad", "", "a", "121", "133", " "};
    for(std::string test: test_strings) {
      if(Variant_1::palindrome(test)) std::cout<<"String " << "(" << test << ")" <<  " is a palindrome" << std::endl;
      else std::cout<<"String " << "(" << test << ")" <<  " is not a palindrome" << std::endl;
    }
    std::cout<< std::endl;
  }
  static void binary_search_test () {
    std::vector<std::vector<int>> test_massives{{1, 3, 5, 7, 9, 11}, {1, 3, 5, 7, 9, 11}, {}, {5}, {5}};
    std::vector<int> test_targets{1,6,5,5,10};
    for (size_t i = 0; i < test_massives.size(); ++i) {
        const auto& arr = test_massives[i];
        int target = test_targets[i];
        int result = Variant_1::binary_search(arr, target);
        std::cout << "Test " << (i + 1) << ":\n";
        std::cout << "Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\nTarget: " << target;
        std::cout << "\nResult: " << result << "\n\n";
    }
  }
  static void is_massive_sorted_test() {
    std::vector<std::vector<int>> test_massives{
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},   
        {},                 
        {3},              
        {1, 2, 3, 2, 5}    
    };
    for (size_t i = 0; i < test_massives.size(); ++i) {
        const auto& arr = test_massives[i];
        bool result = Variant_1::is_massive_sorted(arr);
        std::cout << "Test " << (i + 1) << ":\n";
        std::cout << "Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\nIs sorted: " << (result ? "True" : "False") << "\n\n";
    }
}
  static void sum_div_by_3_test() {
    std::vector<std::vector<int>> test_massives{
        {3, 6, 9, 12},     // Все элементы делятся на 3
        {1, 2, 4, 5},      // Нет элементов, делящихся на 3
        {},                // Пустой массив
        {3},               // Один элемент, который делится на 3
        {1, 2, 3, 4, 5, 6} // Смешанный массив
    };

    for (size_t i = 0; i < test_massives.size(); ++i) {
        const auto& arr = test_massives[i];
        int result = Variant_1::sum_div_by_3(arr);
        std::cout << "Test " << (i + 1) << ":\n";
        std::cout << "Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\nSum of elements divisible by 3: " << result << "\n\n";
    }
}
  static void submassives_of_S_test() {
    std::vector<std::vector<int>> test_massives{
        {1, 2, 3, 4, 5},     // Подмассивы с суммой 5: {2, 3}, {5}
        {5, 2, -3, 1, 2},    // Подмассивы с суммой 4: {5}, {2, -3, 1, 2}
        {},                   // Пустой массив
        {1, 2, 3},           // Подмассивы с суммой 6: {1, 2, 3}
        {1, 2, 3, 4, 5, 6}   // Подмассивы с суммой 10: {1, 2, 3, 4}, {4, 5, 6}
    };
    std::vector<int> test_targets{5, 4, 0, 6, 10}; // Целевые суммы

    for (size_t i = 0; i < test_massives.size(); ++i) {
        const auto& arr = test_massives[i];
        int target = test_targets[i];
        auto result = Variant_1::submassives_of_S(arr, target);

        // Вывод массива и целевой суммы
        std::cout << "Test " << (i + 1) << ":\n";
        std::cout << "Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\nTarget Sum: " << target << "\n";

        // Вывод найденных подмассивов
        std::cout << "Subarrays with sum " << target << ": ";
        if (result.empty()) {
            std::cout << "None";
        } else {
            for (const auto& subarr : result) {
                std::cout << "{ ";
                for (int num : subarr) {
                    std::cout << num << " ";
                }
                std::cout << "} ";
            }
        }
        std::cout << "\n\n";
    }
}
};
#endif