#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

int main() {
    ifstream inputFile("/Users/user/CLionProjects/polygon-1/numbers1e4.tsv");
    if (!inputFile) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }
    string line;
    vector<int> a;
    if (getline(inputFile, line)) {
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, '\t')) {
            a.push_back(stoi(cell));
        }
    }
    inputFile.close();
    clock_t begin = clock();

    int size = a.size() - 1;
    bool finish = false;
    while (!finish) {
        finish = true;
        for (int i = 0; i < size; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                finish = false;
            }
        }
        if (finish) {
            break;
        }
        finish = true;
        for (int i = size - 1; i >= 1; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                finish = false;
            }
        }
    }
    clock_t end = clock();
    double elapsed = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << elapsed << endl;
    for (int i = 0; i <= size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}