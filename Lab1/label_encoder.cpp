#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// Необходимо для тестирующего фреймворка
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Source/doctest.h"


// Сложность алгоритма - o(n), где n - количество строк в файле
// память - 24 + n + 56 + m + s * 1 + 488 + 1 + k = 
// = 569 + n + m + s + k байт, где n - кол-во строк в файле,
// m - кол-во уникальных строк в файле, s - сумма длин уникальных строк в файле, k - длина самой длинной строки в файле
std::vector<unsigned char> label_encoder(const std::string& path) {    // Функция принимает один аргумент - путь до файла

    std::vector<unsigned char> encoded;    // Создаем массив для вывода, память - (24 + n * 1) = n + 24 байт, где n - кол-во строк в файле

    std::ifstream file;    // Создаем переменную для нашего файла, память - 488 байт
    file.open(path);    // Открываем файл

    std::unordered_map<std::string, unsigned char> hash_table;    // Создаем хеш-таблицу, память - (56 + m + s) = 56 + m + s,
                                                                  // где m - кол-во уникальных строк, s - сумма длин уникальных строк
    std::string inp;    // Создаем переменную для хранения считанных из файла "слов", память - (k), где K - кол-во эл-тов строки
    unsigned char next_value = 1;    // Переменная для хранения номера первый раз встреченного "слова", память - (1)

    while (file >> inp) {    // Пока в файле еще есть "слова":

        if (!hash_table.contains(inp))    // Проверяем, не встречали ли мы это "слово" раньше
            hash_table[inp] = next_value++;    // Если нет, то присваиваем ему номер и увеличиваем переменную next_value на 1

        encoded.push_back(hash_table[inp]);    // Добавляем номер текущего слова в выходной массив

    }

    return encoded;    // Возвращаем итоговый массив

}

// Немного юнит тестов

TEST_CASE("testing the label_encoder function") {

    std::string
        path1 = "Tests/test_label_encoder_1.txt",
        path2 = "Tests/test_label_encoder_2.txt",
        path3 = "Tests/test_label_encoder_3.txt";

    std::vector<unsigned char>
        res_path1 = {},
        res_path2(441, 1),
        res_path3;

    for (size_t i = 1; i <= 100; i++)
        res_path3.push_back(i);

    CHECK(label_encoder(path1) == res_path1);
    CHECK(label_encoder(path2) == res_path2);
    CHECK(label_encoder(path3) == res_path3);

}
