#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using std::cout;
using std::vector;

void tests(int x) {
    std::ofstream test;
    test.open("C:/Users/RaZoRis/Desktop/ALGOS/C++/lab-5 (Sort)/test.txt");
    for (int i = 0; i < x; i++) {
        test << rand() / clock() << " ";
    }
    test.close();
    cout << "Dataset is create!" << std::endl;
}

vector<int> read_file(const std::string& filename) {
    vector<int> arr;
    std::ifstream in(filename);
    int number;

    while (in >> number) {
        arr.push_back(number);
    }

    return arr;
}

void countingSort(vector<int>& array, int exp) {
    vector<int> output(array.size()); 
    vector<int> count(10, 0); 

    for (int i = 0; i < array.size(); i++) {
        count[(array[i] / exp) % 10]++;
    }


    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < array.size(); i++) {
        array[i] = output[i];
    }
}

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void radixSort(vector<int>& arr) {

    int maxVal = getMax(arr);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    clock_t start = clock();
    tests(1000000);
    vector<int> arr = read_file("test.txt");

    // cout << "Start dataset:" << std::endl;
    // for (int i = 0; i < std::size(arr); i++) {
    //     cout<< arr[i] << ",";
    // }
    cout << std::endl;
    cout << std::endl;
    
    radixSort(arr);

    // cout << "Sorted dataset:" << std::endl;
    // for (int num : arr) {
    //     cout << num << " ";
    // }
    cout << std::endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}
