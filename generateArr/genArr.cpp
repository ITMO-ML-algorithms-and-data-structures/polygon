#include <random>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outputFile("E:/СLabs/lab1/polygon/generateArr/f.txt");

    if (outputFile) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100000);

        for (int i = 0; i < 40000; ++i) {
            outputFile << dis(gen) << " ";
        }
        outputFile.close();
    }

    cout << "Готово" << endl;
}