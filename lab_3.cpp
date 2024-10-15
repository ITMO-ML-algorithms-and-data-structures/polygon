#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <list>
#include <unordered_set>

using namespace std;

int main() {
    ifstream file; // O(1)
    file.open("C:/Users/Lena/PycharmProjects/pythonProject1/numbers_2.tsv"); // O(1)
    string line, str; // O(1)
    while (getline(file, line)) {
        str += line; // O(l) - добавление значений из исходного файла в строку, l - длина строки
    }

    vector <short int> numbers; // O(1)
    stringstream ss(str); // O(1)
    int num; // O(1)
    while (ss >> num) {
        numbers.push_back(num); // O(n) - добавление элемента в массив, где n - кол-во исходных чисел, n = 1000000
    }


    list <short int> outt; // O(1)
    unordered_set <short int> visited; // O(1)
    for (int i = 0; i < numbers.size(); i++) { // O(1) + O(1)
        // O(n) - в худшем случае, когда все элементы уникальны, в лучшем - O(1), когда все элементы одинаковые
        // O(k) - в среднем случае, который равномерно распределён от 1 до n 
        if (visited.size() == 0 or (visited.find(numbers[i]) == visited.end())) { // O(1) + O(1) + O(1) + O(1) + O(1)
            outt.push_back(numbers[i]); // O(1) - добавление элементов в связный список
            visited.insert(numbers[i]); // O(1) - добавление элементов в неупорядоченное множество
        }
    }

    for (int symb : outt) {
        cout << symb << ' ';// O(m) - вывод уникальных значений, где m - количество уникальных значений
    }
    // Сложность алгоритма составляет:
    // O(n) - в худшем случае
    // O(1) - в лучшем случае
    // O(k) - в среднем случае, который равномерно распределён от 1 до n
    return 0;
}
