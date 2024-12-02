#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

// Основная функция Bucket Sort.
vector<int> bucketSort(vector<int> arrayToProcess, int maximumValue) { 
    vector<int> newbucket(maximumValue + 1); // Хранение количества вхождений каждого числа; O(k), 4 * (k + 1) байта, где k - maximumValue.
    vector<int> sortedArray(arrayToProcess); // O(n), 32 + 4n байт, где n - кол-во элементов в массиве.

    for (int num : arrayToProcess) { // O(n).
        newbucket[num]++; // Сколько раз каждый элемент встречается в массиве.
    }

    // Сортируем элементы в корзине и добавляем их в отсортированный массив.
    // Сложность цикла - O(n + k), где k - максимальное значение.
    int position = 0;
    for (int i = 0; i < newbucket.size(); i++) { // O(k)
        for (int j = 0; j < newbucket[i]; j++) { // O(n)
            sortedArray[position++] = i; // Добавление i в отсортированный массив столько раз, сколько оно встречается.
        }
    }

    return sortedArray;
}

int maximumValue(vector<int> arrayToProcess) { 
    return *max_element(arrayToProcess.begin(), arrayToProcess.end()); // O(n)
}

int main() {

    ifstream dataSet("dataset.txt");
    ofstream result("result.txt");

    if (!dataSet.is_open()) {
        cout << "File dataset.csv doesn't exist";
        return 1;
    }
    string dataSetElement; // 40 байт.
    vector<int> arrayToProcess; // O(n), 32 + 4n, где n - кол-во элеменов массива.

    while (getline(dataSet, dataSetElement, ',')) {
        arrayToProcess.push_back(stoi(dataSetElement));
    }

    int maximum_value = maximumValue(arrayToProcess); // O(n).

    dataSet.close();

    auto start = chrono::high_resolution_clock::now();

    vector<int> sortedArray = bucketSort(arrayToProcess, maximum_value); // O(n + k).

    auto stop = chrono::high_resolution_clock::now();

    bool firstOut = true;

    for (int num : sortedArray) { 
        if (firstOut) {
            result << num;
            firstOut = false;
        }
        else {
            result << ", " << num;
        }
    }
    
    result.close();

    auto duration = chrono::duration_cast <chrono::microseconds> (stop - start);

    cout << duration.count() << " microseconds";

    // Итого по памяти примерно имеем 4 * (k + 1) + 32 + 4n + 40 + 32 + 4n = 108 + 8n + 4k байт.
    // Общая временная сложность - O(n + k).
}
