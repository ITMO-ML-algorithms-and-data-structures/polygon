#include <iostream.h>
#include "lab1_lib.h"

int CalcResult(int* numbersSet, size_t numbersSize) {
    int result = 0;

    for (int i = 0; i < numbersSize; i++) {
        for (int j = 0; j < numbersSize; j++) {
            if (i != j) {
                int numberI = numbersSet[i];
                int numberJ = numbersSet[j];

                if (numberI > numberJ) {
                    std::cout << numberI << ":" << numberJ << "\n";
                    result++;
                }
            }
        }
    }
    return result;
}