#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        int currentElement = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}

void bucketSort(vector<int>& array) {
    int maxElem = *max_element(array.begin(), array.end());
    int minElem = *min_element(array.begin(), array.end());

    int bucketCount = array.size();

    vector<vector<int>> buckets(bucketCount);

    for (int i = 0; i < array.size(); ++i) {
        int bucketIndex = (array[i] - minElem) * (bucketCount - 1) / (maxElem - minElem);
        buckets[bucketIndex].push_back(array[i]);
    }

    for (int i = 0; i < bucketCount; ++i) {
        if (!buckets[i].empty()) {
            insertionSort(buckets[i]);  
        }
    }

    array.clear();
    for (int i = 0; i < bucketCount; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            array.push_back(buckets[i][j]);
        }
    }
}

int main() {
    ifstream inputFile("numbers1e6.txt");
    vector<int> numbers;
    int num;

    while (inputFile >> num) {
        numbers.push_back(num);
    }

    inputFile.close();

    cout << endl;

    auto start = chrono::high_resolution_clock::now(); 

    bucketSort(numbers); 

    auto end = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed = end - start;

    cout << "First 100 sorted nums: ";
    for (size_t i = 0; i < numbers.size() && i < 100; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(5);
    cout << "Work time: " << elapsed.count() << " sec." << endl;

    return 0;
}
