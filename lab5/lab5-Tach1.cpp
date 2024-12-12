#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void combSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    bool sorted = false;
    const double shrink = 1.3;

    while (gap > 1 || !sorted) {
        gap = max(1, (int)(gap / shrink));
        sorted = true;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = false;
            }
        }
    }
}

int main() {
    string filePath = "D:\\program\\C++program\\lab5algo\\polygon\\lab5\\togomori.txt";
    vector<int> arr;

    // Reading input file
    ifstream inputFile(filePath);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
    }
    inputFile.close();

    // Applying Comb Sort
    combSort(arr);

    // Displaying results in the terminal
    cout << "Comb Sort Result: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}   
 