#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

// Определить являются ли 2 строки изоморфными
// Асимптотическая сложность этого алгоритма O(N), так как алгоритм проходит один раз по всей строке для записи индексов.
// По памяти O(N), где N - длина строк.
// Функция возвращает true - если строки изоморфны, false - нет

// Tests: input: egg add
// Output: true (true, ибо индекс f(g) можно заменить на f(d))

// Tests: input: foo bar
// Output: false (false, ибо индекс f(o) можно заменить на f(a))

// Tests: input: 12 21
// Output: true (true, ибо индекс f(1) можно заменить на f(2))

bool isIsomorphic(std::string string1, std::string string2) {
    // 8 + 8 + 8 + N = 24 + N байт, для двух 2 * (24 + N) = 48 + 2N байт
    if (string1.length() != string2.length()) {
        return false;  // Если длины не равны, значит строки не изоморфны
    }
    // 8 байт (размер ссылки) + 8 байт (указатель) + 8 байт (длина) + 8 байт (емкость) + N байт (массив символов).

    std::unordered_map<char, long long int> index_string1;  // Хранит индексы символов первой строки
    std::unordered_map<char, long long int> index_string2;  // Хранит индексы символов второй строки
    // Я не знаю, надо ли считать память хэш-таблицы, но по идее это будет 1 * M + 8 * N байт, где M - количество ключей(индексов), а N - количество элементов(значений)
    

    // Проходим по каждому символу строки для сравнения индексов элементов (наверное, это можно было сделать при помощи find из мапы за О(1))
    for (long long int i = 0; i < string1.length(); i++) { // 8 байт (локальная видимость)
        // Сравниваем индексы символов
        if (index_string1[string1[i]] != index_string2[string2[i]]) {
            return false;  // Если индексы не совпадают, то строки не изоморфны
        }
        
        // Обновляем индекс символа в хэш-мапе для обоих строчек
        index_string1[string1[i]] = i + 1; 
        index_string2[string2[i]] = i + 1; 
    }

    return true;  // Строки изоморфны
}

int main(int argc, char* argv[]) { // в функции мейн указаны аргументы командной строки для передачи txt файла
    // argc - количество аргументов, argv - сами аргументы
    
    std::ifstream file(argv[1]);  // Открываем файл с данными.

    std::string line;  // Переменная для хранения считанной строки из файла (8 + 8 + 8 + N = 24 + N байт)

    // Считываем строки из файла
    while (std::getline(file, line)) {
        long long int indexofspace = line.find(' ');  // Ищем индекс пробела
        // по памяти 8 байт

        if (indexofspace < line.length()) {  // Проверяем, найден ли пробел, если найден, то
            std::string s = line.substr(0, indexofspace);  // Первая строка будет по индексам от 0 до индекса пробела
            std::string s2 = line.substr(indexofspace + 1);  // Вторая строка будет по индексам от индекса пробела + 1 до конца

            // Проверка на изоморфизм и вывод результата
            if (isIsomorphic(s, s2)) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        }
    }

    file.close();  // Закрываем файл
    return 0;
}

// Общий объём используемой памяти:
// 48 + 2N байт для строк string1 и string2
// (1 * M + 8 * N)*2 байт для двух хэш-таблиц
// 8 байт для локальной переменной i
// 8 байт для локальной переменной indexofspace
// 24 + N байт для переменной line
// Всего: 88 + 19N + 2M байт.
