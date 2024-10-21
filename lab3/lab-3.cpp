#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>


//тестирующий фреймворк
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../source/doctest.h"

// функция перемешивания массива на основе тасования Фишера-Йетса
// общая сложность O(n)

void shuffle(std :: vector<int> &arr){

    srand(time(nullptr));  // сид для выбора рандомных индексов, O(1)
    int iter_for_swap;  // сам рандомный индекс O(1)

    for (int i = size(arr) - 1; i > 0; i--){
        iter_for_swap = rand() % i; // присвоение рандомного индекса, O(1)
        std :: swap(arr[i], arr[iter_for_swap]); // меняем выбранный элемент и рандомный (который находится "до него" в массиве)
    }
    // n итераций -> O(n)
    // с помощью данного алгоритма можно получить равномерное перемешивание, так как
    // при swap на i итерации есть n - i способов этот swap провести -> при последовательном проведении итераций
    // есть (n - 0) * (n - 1) * (n - 2) * ... * (n - (n - 2)) = n! способов провести последовательные swap, что обеспечивает
    // равновероятные перестановки, так как при i-ой итерации предыдущие позиции (от i + 1 до n - 1) мы не рассматриваем
    
}

// тестики (check ./tests/)
TEST_CASE("testing the shuffle() function"){
    std :: fstream file;
    std :: vector<int> test1, test2, test3, test4, test1_init, test2_init, test3_init, test4_init;

    int temp;

    file.open("./tests/test1.txt");
    while (file >> temp) test1.push_back(temp); // случай пустого массива
    file.close();

    file.open("./tests/test2.txt");
    while (file >> temp) test2.push_back(temp); // обычный случай (небольшое кол-во данных)
    file.close();

    file.open("./tests/test3.txt");
    while (file >> temp) test3.push_back(temp); // случай одинаковых элементов в массиве
    file.close();

    file.open("./tests/test4.txt");
    while (file >> temp) test4.push_back(temp); // обычный случай (большое кол-во данных)
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
    CHECK(((test2_init != test2) && (size(test2_init) == size(test2))));
    CHECK(test3 == test3_init);
    CHECK(((test4 != test4_init) && (size(test4) == size(test4_init))));
}