#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
typedef unsigned long long ull; //чтобы не писать каждый раз

// тестирующий фреймворк
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../source/doctest.h"

// функция удаления дупликатов в массиве чисел
// общие затраты по памяти = 472 + 8 + 24 + 56 + 8k + 9k =
// = 560 + 17k байт, где k - кол-во уникальных чисел в исходном массиве данных
std :: vector<ull> delete_duplications(const std :: string& path){

    std :: ifstream data; // +472 байт
    data.open(path);

    std :: unordered_map<ull, bool> hash_map; // +56 байт | хеш-таблица, где мы будем "закреплять" уже увиденные элементы
    std :: vector<ull> edited_arr; // +24 байт | конечный массив (с неповторяющимися числами)

    ull temp; // +8 байт

    while (data >> temp){

        if (hash_map.find(temp) == hash_map.end()){  // нет в хеш-таблице -> элемент впервые встречается
            hash_map[temp] = true;                   // добавляем в хеш-таблицу ("помечаем как уже увиденный") | +(1 + 8) * k = +9k байт
            edited_arr.push_back(temp);              // добавляем в конечный массив | +8k байт
        }

    }

    return edited_arr;
}


// тестики (check ./tests/ )
TEST_CASE("testing the delete_duplications() function"){
    std :: string
        path1 = "tests/test1.txt",
        path2 = "tests/test2.txt",
        path3 = "tests/test3.txt",
        path4 = "tests/test4.txt";

    std :: vector<ull>
        ans1,
        ans2 = {12, 31, 123, 4213},
        ans3 = {18000000000000000000, 18000000000000000001, 18000000000000000002, 1800000000000000007},
        ans4;
    
    std :: ifstream file_ans4;
    file_ans4.open("tests/test4_ans.txt");
    ull temp;
    while (file_ans4 >> temp) ans4.push_back(temp);

    CHECK(delete_duplications(path1) == ans1);
    CHECK(delete_duplications(path2) == ans2);
    CHECK(delete_duplications(path3) == ans3);
    CHECK(delete_duplications(path4) == ans4);
}