#include <iostream>
#include <vector>
#include <queue> 
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
const int max_size = 10000000; // 4 байта.

// Функция для обработки элементов через турнирную сетку.
vector<int> tournamentGrid(vector<int> arrayToProcess) {
    priority_queue<int, vector<int>, greater<int>> priorityQueue; // Приоритетная очередь (вспомогательная куча); 32 + 4k байт, где k - кол-во элементов очереди.
    vector<int> winners; // 32 + 4m байта, где m - кол-во элементов в этом массиве.
    vector<int> losers; // 32 + 4p байта, где p - кол-во элементов в массиве.

    for (int i = 0; i < max_size and not arrayToProcess.empty(); ++i) {
        priorityQueue.push(arrayToProcess.front()); //O(log k), где k - размер очереди; 4k байт.
        arrayToProcess.erase(arrayToProcess.begin()); //O(n).
    }

    while (!arrayToProcess.empty()) {
        if (winners.empty()) {
            winners.push_back(priorityQueue.top()); // Добавление самого верхнего элемента из очереди в "победители".
            priorityQueue.pop(); // Восстановление кучи; O(log k).
        }

        if (arrayToProcess.front() > winners.back()) { // Если очередной элемент из массива больше, чем последний "победитель".
            priorityQueue.push(arrayToProcess.front());
            arrayToProcess.erase(arrayToProcess.begin());
        }
        else {
            losers.push_back(arrayToProcess.front());
            arrayToProcess.erase(arrayToProcess.begin());
        }

        if (!priorityQueue.empty()) {
            winners.push_back(priorityQueue.top());
            priorityQueue.pop();
        }
    }

    // Проверка на наличие элементов в куче, когда массив пуст.
    while (!priorityQueue.empty()) {
        winners.push_back(priorityQueue.top());
        priorityQueue.pop();
    }

    // Если нет "проигравших, то "победители" - это итоговый отсортированный массив.
    if (losers.empty()) {
        return winners;
    }

    arrayToProcess = losers;
    arrayToProcess.insert(arrayToProcess.end(), winners.begin(), winners.end());

    while (arrayToProcess.size() > max_size) {
        arrayToProcess.pop_back();
    }

    return tournamentGrid(arrayToProcess); // O(n log n) - в худшем случае.
}

// Основная функция Tournament Sort.
vector<int> tournamentSort(vector<int> arrayToProcess) {
    return tournamentGrid(arrayToProcess);
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

    vector<int> sortedArray = tournamentSort(arrayToProcess); // O(n log n), 32 + 4n байта.

    auto stop = chrono::high_resolution_clock::now();

    bool firstOut = true;

    for (int num : sortedArray) {
        if (firstOut) {
            result << num;
            firstOut = false;
        } else {
            result << ", " << num;
        }
    }

    result.close();

    auto duration = chrono::duration_cast <chrono::microseconds> (stop - start);

    cout << duration.count() << " microseconds";

    // Итого по памяти примерно имеем 4 + 32 + 4k + 32 + 4m + 32 + 4p + 32 + 4n + 32 + 4n = 164 + 4k + 4m + 4p + 8n байта.
    // Общая временная сложность - O(n log n).
}