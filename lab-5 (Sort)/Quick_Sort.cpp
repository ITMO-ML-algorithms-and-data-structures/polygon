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

void quicksort(vector<int>& array) {
    if (array.size() <= 1) {
        return;
    }
    int s_elm = array[0];
    vector<int> low, up;

    for (int i = 1; i < array.size(); i++) {
        if (array[i] < s_elm) {
            low.push_back(array[i]);
        }
        else {
            up.push_back(array[i]);
        }
    }
    quicksort(low);
    quicksort(up);

    array = low;
    array.insert(array.end(), s_elm);
    array.insert(array.end(), up.begin(), up.end());
}


int main() {
    clock_t start = clock();
    tests(1000000);
    vector<int> array = read_file("test.txt");

    // cout << "Start dataset:" << std::endl;
    // for (int i = 0; i < std::size(array); i++) {
    //     cout<< array[i] << ",";
    // }
    cout << std::endl;
    cout << std::endl;

    quicksort(array);

    // cout << "Sorted dataset:" << std::endl;
    // for (auto i : array) {
    //     cout << i << " ";
    // }
    cout << std::endl;
    clock_t end = clock();
    double time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << time;
}