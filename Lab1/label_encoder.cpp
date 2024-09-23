#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// Необходимые библиотеки для тестирующего фреймворка
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "../Source/doctest.h"

std::vector<short> label_encoder(const std::string& path) {

    std::vector<short> encoded;

    std::ifstream file;
    file.open(path);    // Открываем файл

    std::vector<std::string> words;
    std::unordered_map<std::string, short> hash_table;
    std::string inp;
    while (file >> inp)
        words.push_back(inp);
    int size = words.size();
    int next_value = 1;

    for (size_t i = 0; i < size; i++) {

        if (!hash_table.contains(words[i]))
            hash_table[words[i]] = next_value++;

        encoded.push_back(hash_table[words[i]]);

    }

    return encoded;

}

// Немного юнит тестов

/*TEST_CASE("testing the label_encoder function") {

    std::string
        path1 = "Tests/test1.csv",
        path2 = "Tests/test2.csv",
        path3 = "Tests/test3.csv";

    std::vector<short>
        res1 {1, 1, 2, 3, 4, 5, 5, 1, 1, 4},
        res2 {1, 2, 3, 4, 5, 4, 5, 5, 3, 6},
        res3 {1, 2, 2, 3, 2, 1, 2, 1, 3, 2, 2, 3, 1, 2, 3};

    bool b1 = label_encoder(path1) == res1,
        b2 = label_encoder(path2) == res2,
        b3 = label_encoder(path3) == res3;

    CHECK(b1);
    CHECK(b2);
    CHECK(b3);

}*/

int main() {

    std::string path;
    std::cin >> path;    // Получаем на вход путь до файла и сохраняем его в path

    std::vector<short> encoded = label_encoder(path);

    for (short i : encoded)
        std::cout << i << " ";

}
