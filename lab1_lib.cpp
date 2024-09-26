#include "lab1_lib.h"

int CalcLab1Result(vector<int> numbers) {
    int result = 0;
    int numbersSize = numbers.size();

    for (int i = 0; i < numbersSize; i++) {
        for (int j = 0; j < numbersSize; j++) {
            if (i != j) {
                int numberI = numbers[i];
                int numberJ = numbers[j];

                if (numberI > numberJ) {
                    result++;
                }
            }
        }
    }
    return result;
}