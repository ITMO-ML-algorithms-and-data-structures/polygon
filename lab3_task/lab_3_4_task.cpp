#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
 
using namespace std;

void minMaxScaler(const vector<double>& arr, vector<double>& scaledArr) {
    if (arr.empty()) {
        scaledArr.clear();
        return;
    }
    
    double minVal = *min_element(arr.begin(), arr.end());
    double maxVal = *max_element(arr.begin(), arr.end());

    // If min == max, then scaledArr is filled with 0.0
    if (minVal == maxVal) {
        scaledArr.assign(arr.size(), 0.0);
        return;
    }

    

    // Normalizing
    scaledArr.clear();
    for (double num : arr) {
        double scaledValue = (num - minVal) / (maxVal - minVal);
        scaledArr.push_back(scaledValue);
    }
}

int main() {
    vector<double> arr = { 1, 100, 1000001, 2, 900000};
    vector<double> scaledArr;

    minMaxScaler(arr, scaledArr);

    cout << setprecision(1) << "[";
    for (size_t i = 0; i < scaledArr.size(); ++i) {
        cout << scientific << scaledArr[i];
        if (i != scaledArr.size() - 1) cout << " ";
    }
    cout << "]" << endl;

    return 0;
}
