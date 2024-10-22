#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;

void find_min_max(ifstream &inputFile, float &mini, float &maxi, vector<int> &numbers) {
    int number; // o(1)
    while (inputFile >> number) { // o(n)
        numbers.push_back(number); // o(1)
        if (number < mini) mini = number; // o(1)
        if (number > maxi) maxi = number; // o(1)
    }
}


void normalize_and_print(const vector<int> &numbers, float mini, float maxi) {
    cout << scientific << setprecision(1); // o(1)
    int count = 0; // o(1)
    for (int number : numbers) { // o(n)
        if (count >= 100) break; // o(1)
        float normalized = (static_cast<float>(number) - mini) / (maxi - mini); // o(1)
        cout << normalized << " "; // o(1)
        count++; // o(1)
    }
}

int main() {
    ifstream inputFile("numbers10.txt"); // o(1) 

    vector<int> numbers; // o(1)
    float mini = numeric_limits<float>::max(); // o(1)
    float maxi = numeric_limits<float>::lowest(); // o(1)

    find_min_max(inputFile, mini, maxi, numbers); // o(n)
    normalize_and_print(numbers, mini, maxi); // o(n)
    
    inputFile.close(); // o(1)
    return 0;
} // общая сложность алгоритма o(1) * 10 + o(n) * 2 = O(n)
