#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

int main() {
    ifstream file;
    file.open("C:/Users/Lena/PycharmProjects/pythonProject1/numbers.tsv");
    string line, str; // + 32 * 2 байт
    while (getline(file, line)) {
        str += line;
    }

    vector <short int> numbers;
    stringstream ss(str);
    int num;
    while (ss >> num) {
        numbers.push_back(num); // + m * 2, где m - кол-во исходных чисел, m = 500 
    }


    unordered_set <short int> visited;
    vector <short int> outt;
    for (int i = 0; i < numbers.size(); i++) {
        if (visited.size() == 0 or (visited.find(numbers[i]) == visited.end())) {
            outt.push_back(numbers[i]); // + n * 2, где n - кол-во чисел в массиве без дубликатов
            visited.insert(numbers[i]); // + n * 2

        }
    }

    for (int symb : outt) {
        cout << symb << ' ';
    }
    // на выходе имеем 32 * 2 + n * (2 + 2) + 500 * 2 = 1064 + 4 * n, где n - кол-во чисел в массиве без дубликатов
    return 0;
}
