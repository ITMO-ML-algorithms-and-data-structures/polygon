#include <vector>

int index_of_number(std::vector<int> array, int number) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return -1; // если number нет в array, то возвращается -1
}


