#include <iostream>
#include <vector>
#include <fstream>  // For file input/output
#include <algorithm>  // For std::max
using namespace std;

// Helper function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

// Counting sort for a specific digit
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    // Update count[i] to hold actual position
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    // Build the sorted array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy sorted numbers back to original array
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

// Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Sort each digit place
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    // File path
    string filePath = "D:\\program\\C++program\\lab5algo\\polygon\\lab5\\togomori.txt"; 
    
    // Open file for reading
    ifstream inputFile(filePath);
    
    // Check if the file is open
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;  // Exit if the file cannot be opened
    }

    vector<int> arr;
    int num;

    // Read integers from the file and store in the vector
    while (inputFile >> num) {
        arr.push_back(num);
    }

    inputFile.close();  // Close the file after reading

    // Sort the array using Radix Sort
    radixSort(arr);

    // Output the sorted result
    cout << "Radix Sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
