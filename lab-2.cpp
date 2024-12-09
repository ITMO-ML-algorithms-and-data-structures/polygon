
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

std::vector<int> count_element(std::vector<std::string> arr){
    int size = arr.size();  //Вычисление размера массива - 4 байта

    std::map<std::string, int> counts; //Создание map для подсчета количества вхождений - n * (32 + 4) байта

    for (int i = 0; i < size; ++i) { //Цикл подсчета вхождений имен
        counts[arr[i]]++;
    }

    std::vector<int> result; //Создание результата (массив с количеством вхождений) - 24 + size * 4 байт
    for (int i = 0; i < size; ++i) {
        result.push_back(counts[arr[i]]);
    }

    return result;
}


void Test(){
    std::vector<std::string> arr {"яблоко", "яблоко", "яблоко", "апельсин", "груша", "апельсин", "киви", "вишня"}; 
    std::vector<int> test_1 {3,3,3,2,1,2,1,1};
    assert(count_element(arr) == test_1);
    std::cout<<"OK";
}



int main() {
   std::vector<std::string> arr {"яблоко", "яблоко", "яблоко", "апельсин", "груша", "апельсин", "киви", "вишня"}; //Объявляется массив строк - 24 + 32 * size байт 

   std::vector<int> result = count_element(arr); //  24 + size * 4 байт

    for (int i = 0; i < result.size(); ++i) { //Вывод результата
        std::cout << result[i] << " ";
    }
    Test();
}


