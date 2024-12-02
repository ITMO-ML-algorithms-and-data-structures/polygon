#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
using namespace std; // не требуют памяти

// Функция для замены строк в массиве на количество их вхождений 
void processFrequencies(vector<string>& arr) { // память для указателя на вектор +4
    unordered_map<string, int> frequencyMap; // счетчик числа вхождений строки // 40 + (32 + 4) * N, где N - кол-во пар ключей


    // считаем количество вхождений каждой строки
    for (const auto& str : arr) {
        frequencyMap[str]++;  // операция увеличения значения в мапе, требует памяти для временного хранения значения
    }

    // меняем значения в массиве на число вхождений согласно условию
    for (int i = 0; i < arr.size(); i++) { // +4 байта в рамках цикла
        arr[i] = std::to_string(frequencyMap[arr[i]]); 
    }
}


int main() // память для хранения возвращаемого значения +4
{
    //задаем тестовые массивы строк
    std::vector<std::string> inputArray = { "apple", "banana", "pineapple", "orange", "banana", "apple" };
    std::vector<std::string> inputArray2 = { "apple", "banana", "apple" };
    std::vector<std::string> inputArray3 = { " ", " ", " ", " ", " ", " " };
    std::vector<std::string> inputArray4 = { "banana", "banana", "banana", "banana", "banana" }; // память для векторов можно не учитывать

    //вызываем функцию для каждого заданного массива
    processFrequencies(inputArray);
    processFrequencies(inputArray2);
    processFrequencies(inputArray3);
    processFrequencies(inputArray4); // + 4*4 = 16


    return 0; // память для возвращаемого значения +4
}
// память = 4 + 40 + ((32 + 4)* N) + 4 + 4 + 16 + 4 = 72 + 36*N байтов
