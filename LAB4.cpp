//Ксения Автономова 05.11.2024
//Поток: 4
//Задача: Дан массив размера N целых чисел. В нем необходимо найти все подмассивы размера K, сумма элементов которых равна 0 (не только уникальные пары).
//Основная программа
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <chrono>
using namespace std;

int main()
{
    ifstream dataSet("dataset.txt");
    ofstream result("result.txt");

    if (!dataSet.is_open()) {
        cout << "File dataset.csv doesn't exist";
        return 1;
    }

    string dataSetElement; // 40 байт
    vector<int> arrayToProcess; // 8 + 8 = 16 байт

    while (getline(dataSet, dataSetElement, ',')) {
        arrayToProcess.push_back(stoi(dataSetElement));
    }

    int arrayToProcessSize = arrayToProcess.size(); //4 байта, O(1)

    auto start = chrono::high_resolution_clock::now();

    for (int k1 = 0; k1 < arrayToProcessSize - 3; k1++) { //4 байта
        for (int k2 = k1 + 1; k2 < arrayToProcessSize - 2; k2++) { //4 байта
            for (int k3 = k2 + 1; k3 < arrayToProcessSize - 1; k3++) { //4 байта
                for (int k4 = k3 + 1; k4 < arrayToProcessSize - 0; k4++) { //4 байта
                    if ((arrayToProcess[k1] + arrayToProcess[k2] + arrayToProcess[k3] + arrayToProcess[k4]) == 0) { // O(1) + O(1) + O(1) + O(1) 
                        result << "[" << k1 << ", " << k2 << ", " << k3 << ", " << k4 << "]\n"; //Сложность цикла O(N^4)
                    }
                }
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast < chrono::microseconds > (stop - start);

    dataSet.close();
    result.close();

    cout << duration.count() << " microseconds";
}
