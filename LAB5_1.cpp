#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

// Основная функция Comb Sort. 
vector<int> combSort(vector<int> arrayToProcess) {
    const float reductionFactor = 1.3; // Фактор уменьшения шага - 4 байта.
    int gap = arrayToProcess.size(); // 4 байта.
    bool swapped = true; // Отслеживание обменов (для продолжении сортировки) - 1 байт.

    while (gap > 1 or swapped) { // Сложность цикла - O(log n).
        gap = static_cast<int> (gap / reductionFactor); // Шаг.
        if (gap < 1) { // Минимальный шаг не может быть < 1.
            gap = 1;
        }

        swapped = false;

        // Сравниваем элементы с текущим шагом.
        for (int i = 0; i + gap < arrayToProcess.size(); ++i) { // O(n/gap), 4 байта.
            if (arrayToProcess[i] > arrayToProcess[i + gap]) {
                swap(arrayToProcess[i], arrayToProcess[i + gap]);
                swapped = true; // Произошел обмен.
            }
        }
    }

    return arrayToProcess;
}

int main() {
    ifstream dataSet("dataset.txt");
    ofstream result("result.txt");

    if (!dataSet.is_open()) {
        cout << "File dataset.csv doesn't exist";
        return 1;
    }
    string dataSetElement; // 40 байт.
    vector<int> arrayToProcess; // 32 + 4n байта, где n - кол-во элементов в массиве. 
    
    while (getline(dataSet, dataSetElement, ',')) {
        arrayToProcess.push_back(stoi(dataSetElement));
    }

    dataSet.close();

    auto start = chrono::high_resolution_clock::now();

    vector<int> sortedArray = combSort(arrayToProcess); // O(n log n), 32 + 4n байта.

    auto stop = chrono::high_resolution_clock::now();

    bool firstOut = true;

    for (int num : sortedArray) { // O(n).
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

    // Итого по памяти примерно имеем 4 + 4 + 1 + 4 + 40 + 32 + 4n + 32 + 4n = 117 + 8n, где n - кол-во элементов в массиве.
    // Общая временная сложность - O(n log n).
}
