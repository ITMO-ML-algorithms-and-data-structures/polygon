#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Function to find all subarrays of size K (here K=5) with a sum of zero
vector<vector<int>> findZeroSumSubarrays(const vector<int>& arr, int K = 5) {
    int N = arr.size();
    vector<vector<int>> results;

    // Loop to generate all possible subarrays of size K
    for (int i = 0; i <= N - K; ++i) {
        int sum = 0;
        vector<int> indices;

        // Calculate the sum of elements in the subarray of size K
        for (int j = 0; j < K; ++j) {
            sum += arr[i + j];
            indices.push_back(i + j);
        }

        // If the sum is zero, add the indices to results
        if (sum == 0) {
            results.push_back(indices);
        }
    }

    return results;
}

// Function to clean a line by removing non-numeric characters
string cleanLine(const string& line) {
    string cleaned;
    for (char ch : line) {
        if (isdigit(ch) || ch == '-' || ch == ' ') { // Keep digits, minus signs, and spaces
            cleaned += ch;
        }
    }
    return cleaned;
}

// Main function to load data from file, perform tests, and display results
int main() {
    string filePath = "D:\\program\\C++program\\lab4algos\\lab4.txt";
    ifstream inputFile(filePath);

    if (!inputFile.is_open()){
        cerr << "Error opening file at: " << filePath << endl;
        return 1;
    }

    vector<vector<int>> tests;
    int K = 5;

    // Read test data from file
    string line;
    while (getline(inputFile, line)) {
        line = cleanLine(line); // Clean the line
        vector<int> arr;
        stringstream ss(line);
        string temp;

        // Parse each line as a space-separated list of integers
        while (ss >> temp) {
            try {
                int num = stoi(temp);
                arr.push_back(num);
            } catch (const invalid_argument&) {
                cerr << "Invalid input detected after cleaning: '" << temp << "' is not an integer." << endl;
                return 1;
            } catch (const out_of_range&) {
                cerr << "Number out of range detected in the file: '" << temp << "'." << endl;
                return 1;
            }
        }

        if (!arr.empty()) {
            tests.push_back(arr);
        }
    }

    inputFile.close();

    // Loop over each test array
    for (int i = 0; i < tests.size(); ++i) {
        cout << "Test " << i + 1 << " with arr = {";
        for (int val : tests[i]) cout << val << " ";
        cout << "}, K = " << K << "\n";

        auto results = findZeroSumSubarrays(tests[i], K);
        if (results.empty()) {
            cout << "No subarray of size " << K << " with zero sum found.\n";
        } else {
            cout << "Subarrays of size " << K << " with zero sum:\n";
            for (const auto& indices : results) {
                cout << "[ ";
                for (int idx : indices) {
                    cout << idx << " ";
                }
                cout << "]\n";
            }
        }
        cout << "-----------------------------------\n";
    }

    return 0;
}