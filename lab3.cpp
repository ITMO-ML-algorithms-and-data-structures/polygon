#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("dataset.txt"); 
    vector<float> numbers; 
    float number;

    float mini = numeric_limits<float>::max();
    float maxi = numeric_limits<float>::lowest();

    while (inputFile >> number) {
        numbers.push_back(number);
        if (number < mini) mini = number;
        if (number > maxi) maxi = number;
    }

    for (float &num : numbers) {
        num = (num - mini) / (maxi - mini);
        cout << num << " ";
    }
    return 0;

}
