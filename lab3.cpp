#include <iostream>  // 0 bits
#include <string>    // 0 bits
#include <fstream>
using namespace std;

string compressString(const string &s) {         // O(1)+O(1)
    if (s.empty()) return "";  // 0 bits - returning empty string if input is empty  //O(1)

    string compressed;         // 64 bits - memory allocation for compressed string   O(1)
    int count = 1;             // 32 bits - initializing count variable   //O(1)+O(1)

    for (size_t i = 1; i < s.size(); ++i) {  // 64 bits - loop control variable (size_t) //    O(N)
        if (s[i] == s[i - 1]) {              // 64 bits - accessing and comparing characters         // O(1) + O(1)
            count++;                         // 32 bits - incrementing count  // O(1)
        } else {
            // Add the previous character and its count to the result
            compressed += s[i - 1];          // 8 bits per character added to string O(1) + O(N)
            compressed += to_string(count);  // 32 bits - converting count to string and appending O(1)
            count = 1;                       // 32 bits - resetting count O(1)
        }
    }

    // Add the last sequence to the result
    compressed += s.back();    //    O(1) + O(1) + O(1)         // 8 bits - appending last character
    compressed += to_string(count); // O(1)+O(1)+O(1)         // 32 bits - appending last count

    return compressed;                       // 0 bits - returning result
}

int main() {
    ifstream inputFile("C:\\Users\\ASUS\\CLionProjects\\polygon\\compress.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }
    string line; // O(1)                           // 64 bits - memory allocation for input string
    while (getline(inputFile, line)) {  // Read each line from the file
        // Skip empty lines
        if (line.empty()) continue;

        // Apply compression to each line
        string compressedLine = compressString(line);

        // Print the original and compressed strings
        cout << "Original: " << line << " -> Compressed: " << compressedLine << endl;
    }

    // Close the file after reading
    inputFile.close();

    return 0;                                // 0 bits - end of program
}

// Total bit usage calculation:
// Initialization: 256 bits (variables + string allocations)
// Loop operations: (N - 1) * 160 bits (character comparisons and assignments)
// Final sum: 256 + (N - 1) * 160 bits

// totale Сложность времени

// O(N)