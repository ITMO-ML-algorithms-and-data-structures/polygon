#include <iostream>
#include "lab1_lib.h"

int main()
{
    int numbersSet[] = {1,4,3,5,7,-10};

    int result = CalcResult(numbersSet, std::size(numbersSet));

    std::cout << "Result:" << result << "\n";
}