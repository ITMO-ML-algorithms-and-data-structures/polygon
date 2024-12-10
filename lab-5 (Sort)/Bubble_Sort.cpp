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

int main() {
    clock_t start = clock();
    tests(1000000);
    vector<int> array = read_file("test.txt");

    // cout << "Start dataset:" << std::endl;
    // // for (int i = 0; i < std::size(array); i++) {
    // //     cout<< array[i] << ",";
    // // }
    cout << std::endl;
    cout << std::endl;
    
    for (int i = 0; i < std::size(array) - 1; i++) {
        for (int j = 0; j < std::size(array) - 1; j++) { // O(n^2) | Память: O(1)
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }

    // cout << "Sorted dataset:" << std::endl;
    // for (int i = 0; i < std::size(array); i++) {
    //     cout << array[i] << " ";
    // }
    cout << std::endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}