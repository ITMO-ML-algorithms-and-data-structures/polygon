#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip> 

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

    insertionSort(numbers);

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