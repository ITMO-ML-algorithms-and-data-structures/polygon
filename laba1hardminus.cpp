#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Найти все числа, которые встречаются в массиве чётное количество раз

void vdSeekEvenOccurrences(const vector<int>& arr) {
    unordered_map<int, int> frequencyMap;

    // Подсчёт частоты каждого элемента
    for (int num : arr) {
        frequencyMap[num]++;
    }

    // Вывод элементов с чётной частотой
    cout << "Числа, встречающиеся четное количество раз: ";
    for (const auto& pair : frequencyMap) {
        if (pair.second % 2 == 0) {
            cout << pair.first << " ";
        }
    }
    cout << endl;
}



int main() {


vector<int> arr = {10, 7, 2, 9, 10, 9, 8, 23, 3, 8, 4}; // Пример (датасет?) массива
    vdSeekEvenOccurrences(arr);
    return 0;
}
