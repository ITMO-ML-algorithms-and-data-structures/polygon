#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <time.h>


//тестирующий фреймворк
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../source/doctest.h"

// функция перемешивания массива на основе тасования Фишера-Йетса
// общая сложность O(n)

void shuffle(std :: vector<int> &arr){

    srand(time(nullptr));
    int iter_for_swap;

    for (int i = size(arr) - 1; i > 0; i--){
        iter_for_swap = rand() % i;
        std :: swap(arr[i], arr[iter_for_swap]);
    }

}

TEST_CASE("testing the shuffle() function"){
    std :: fstream file;
    std :: vector<int> test1, test2, test3, test4, test1_init, test2_init, test3_init, test4_init;

    int temp;

    file.open("./tests/test1.txt");
    while (file >> temp) test1.push_back(temp);
    file.close();

    file.open("./tests/test2.txt");
    while (file >> temp) test2.push_back(temp);
    file.close();

    file.open("./tests/test3.txt");
    while (file >> temp) test3.push_back(temp);
    file.close();

    file.open("./tests/test4.txt");
    while (file >> temp) test4.push_back(temp);
    file.close();

    test4_init = test4;
    test3_init = test3;
    test2_init = test2;
    test1_init = test1;

    shuffle(test1);
    shuffle(test2);
    shuffle(test3);
    shuffle(test4);

    CHECK(test1 == test1_init);
    CHECK(!(test2_init == test2));
    CHECK(test3 == test3_init);
    CHECK(!(test4 == test4_init));
}