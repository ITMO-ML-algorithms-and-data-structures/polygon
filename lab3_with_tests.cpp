#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using std::cout;
using std::vector;

void tests(int x) {
    std::ofstream test;
    test.open("C:/Users/RaZoRis/Desktop/C++/polygon/test.txt");
    for (int i = 0; i < x; i++) { // O(n)
        test << rand() << " ";
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
    tests(10000);
    vector<int> arr = read_file("test.txt");
    cout << "Start dataset:" << std::endl;
    for (int i = 0; i < std::size(arr); i++) { // O(n)
        cout<< arr[i] << ",";
    }
    cout << std::endl;
    cout << std::endl;
    cout << "Shiffle arr" << std::endl;
    for (int i = 0; i < std::size(arr); i++) { // O(n)
        std::swap(arr[i], arr[std::rand() * time(0) % std::size(arr)]);
    }
    for (int i = 0; i < std::size(arr); i++) { // O(n)
        cout<< arr[i] << ",";
    }
}