#include <iostream>
#include <vector>
#include <iostream>
int index_of_number(std::vector<int> array, int number) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return -1; // если number нет в array, то возвращается -1
}
int main() {
    std::vector<int> array = {1,2,3};
    int number = 4;
    std::cout << index_of_number(array, number);
    return 0;
}

