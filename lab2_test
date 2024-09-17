#include <iostream>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("test2.txt", ios_base::in);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1; // Возврат кода ошибки
    }

    set<unsigned long long> uniqueValues;

    unsigned long long value;

    while (file >> value) {
        uniqueValues.insert(value);
    }

    vector<unsigned long long> result;

    for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) {
        result.push_back(*it);
    }

    for (const auto& value : result) {
        cout << value << ' ';
    }

    return 0;
}
