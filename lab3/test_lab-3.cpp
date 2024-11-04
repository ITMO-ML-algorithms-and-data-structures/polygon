#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("numbers10.txt"); 
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
    }

    for (int i = 0; i < 10; i++)
    {
        cout << numbers[i];
    }
    

    return 0;
}
