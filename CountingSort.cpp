#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end()); //4 байт
    int minVal = *std::min_element(arr.begin(), arr.end()); //4 байт

    int range = maxVal - minVal + 1; //4 байт

    std::vector<int> count(range, 0); //8k байт

    for (int num : arr) { //перебираем все элементы массива - O(N)
        count[num - minVal]++;
    }

    int index = 0; //4 байт
    for (int i = 0; i < range; ++i) { //перебираем k значений, где k - диапазон значений массива; O(k)
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
} //итог - O(N + k)

int main() {
    std::ifstream data_set("dataset.txt");

    std::string element; // 32 байта
    std::vector<int> array; // 24 байта

    while (getline(data_set, element, ';')) {
        array.push_back(stoi(element));
    } //+4*n байт в vector, где n - количество элементов в нем

    //std::cout << "Original array: ";
    //for (int num : array) {
    //    std::cout << num << " ";
    //}
    //std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    countingSort(array);

    auto stop = std::chrono::high_resolution_clock::now();

    //std::cout << "Sorted array: ";
    //for (int num : array) {
    //    std::cout << num << " ";
    //}
    //std::cout << std::endl;

    auto duration = std::chrono::duration_cast <std::chrono::microseconds>(stop - start);
    data_set.close();

    std::cout << duration.count() << " microseconds";
}
