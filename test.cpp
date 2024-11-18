#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

//-1 - это null

void replaceNullsWithAverage(std::vector<int>& arr) {
    int sum = 0;
    int count = 0;

    for (int val : arr) {
        if (val != -1) {
            sum += val;
            count++;
        }
    }

    if (count == 0) {
        std::cerr << "В массиве все значения null или массив пустой" << std::endl;
        return;
    }

    int average = sum / (count + 1);

    for (int& val : arr) {
        if (val == -1) {
            val = average;
        }
    }
}

int main() {
    ifstream File("C:\Users\Ольга\Downloads\numbers.tsv"); ///обратилась к файлу  O(1)
    unordered_set<int> dbl; /// unourder_set это как у нас set в питоне   O(1)

    replaceNullsWithAverage(File);

    for (int val : File) {
        std::cout << val << " ";
    }

    return 0;
    }
    // Сложность O(N)