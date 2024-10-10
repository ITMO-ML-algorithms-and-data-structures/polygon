#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    std::ifstream InputFile("input.txt");

    int size; // +4 байта
    InputFile >> size;

    std::string arr[size]; // +size*(len(string1)+len(string2)+...+len(stringn))
    for (int i = 0; i < size; i++) {
        //+4 байта только в рамках цикла
        InputFile >> arr[i];
    }
    std::vector<int> T; // n*4
    std::unordered_map<std::string, int> labelencoder; //кол-во уникальных строк *(len(string)+4)

    int cur_ind = 0; // + 4 байта
    for (int i = 0; i < size; i++) {
        // +4 байта только в рамках цикла
        if (not labelencoder[arr[i]]) {
            labelencoder[arr[i]] = cur_ind + 1;
            cur_ind += 1;
        }
        T.push_back(labelencoder[arr[i]]);
    }

    for (const int value: T) {
        std::cout << value << " ";
    }
    // Общее число байт: 4+size*((len(string1)+len(string2)+...+len(stringn))/n c округлением вверх)
    // + n*4 + n *((len(string1)+len(string2)+len(stringn))/n(с округл. вверх)+4) + 4 = 8 + n*4 + size*((len(string1)+
    // len(string2)+...+len(stringn))/n c округлением вверх)
    // + n *((len(string1)+len(string2)+len(stringn))/n(с округл. вверх)+4)
    return 0;
}
