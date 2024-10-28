#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;

void minMaxScaler(const vector<double>& arr, vector<double>& scaledArr) {
    // If array is empty, then scaledArr is empty too
    if (arr.empty()) {
        scaledArr.clear();
        return;
    }

    double minVal = *min_element(arr.begin(), arr.end());
    double maxVal = *max_element(arr.begin(), arr.end());

    // if minVal == maxVal, fill scaledArr with 0.0
    if (minVal == maxVal) {
        scaledArr.assign(arr.size(), 0.0);
        return;
    }

    // Calculating each scaledValue and adding them in scaledArr
    for (double num : arr) {
        double scaledValue = (num - minVal) / (maxVal - minVal);
        scaledArr.push_back(scaledValue);
    }
}

int main() {
    vector<double> arr = { 1, 100, 1000001, 2, 900000, 1000000, 7};
    vector<double> scaledArr = {};

    minMaxScaler(arr, scaledArr);

    cout << setprecision(1) << "[";
    for (size_t i = 0; i < scaledArr.size(); ++i) {
        cout << scientific << scaledArr[i];
        if (i != scaledArr.size() - 1) cout << " ";
    }
    cout << "]" << endl;

    return 0;
}
