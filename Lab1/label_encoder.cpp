#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// Необходимо для тестирующего фреймворка
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "../Source/doctest.h"

std::vector<short> label_encoder(const std::string& path) {    // Функция принимает один аргумент - путь до файла

    std::vector<short> encoded;    // Создаем массив для вывода

    std::ifstream file;    // Создаем переменную для нашего файла
    file.open(path);    // Открываем файл

    std::unordered_map<std::string, short> hash_table;    // Создаем хеш-таблицу
    std::string inp;    // Создаем переменную для хранения считанных из файла "слов"
    int next_value = 1;    // Переменная для хранения номера первый раз встреченного "слова"

    while (file >> inp) {    // Пока в файле еще есть "слова":

        if (!hash_table.contains(inp))    // Проверяем, не встречали ли мы это "слово" раньше
            hash_table[inp] = next_value++;    // Если нет, то присваиваем ему номер и увеличиваем переменную next_value на 1

        encoded.push_back(hash_table[inp]);    // Добавляем номер текущего слова в выходной массив

    }

    return encoded;    // Возвращаем итоговый массив

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

    std::string path;    // Создаем переменную для хранения пути к файлу
    std::cin >> path;    // Получаем на вход путь до файла и сохраняем его в path

    std::vector<short> encoded = label_encoder(path);    // Получаем итоговый массив для нашего файла

    // ...

}
