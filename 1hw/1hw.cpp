#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<unsigned short>>
CountVectorizer(const std::vector<std::string> &input) { // функция векторизации
    std::vector<std::vector<unsigned short>> answer; // создаём массив выходных данных
    // вес N * U * 2, где N - число строк и U - число уникальных слов
    // максимальный вес 10000 * 100 * 2 байт = 2000000 байт
    answer.reserve(input.size()); // указываем, что будем расширять answer до количества строк
    std::unordered_map<std::string, unsigned short> word_number; // создаём хеш-таблицу, в которой
    // каждому слову будет соответствовать свой индекс
    // вес - L1 + 2 + ... + Ln + 2 байт, где L1 - вес i уникальной строки, где её вес равен l байт, где l - количество
    // символов максимальный вес 100 * 102 байт = 10200 байт

    for (const std::string &input_line: input) { // рассматриваем каждую строку
        std::string line = input_line + ' '; // добавляем пробел в конец каждой рассматриваемой строки,
        // чтобы разделять слова в строке по пробелу
        // вес равен l байт, где l - количество символов
        // максимальный вес 101 байт

        answer.push_back(
                std::vector<unsigned short>(word_number.size(), 0)); // добавляем в answer рассматриваемую строку
        // заполняем нулями каждый столбец, который принадлежит уже известному уникальному слову

        unsigned short word_start_index = 0;
        // задаём начало слова, как 0 индекс
        // вес 2 байта

        for (unsigned short curr_index = 1; curr_index < line.length();
             curr_index++) // пробегаемся по всем элементам строки
            // вес 2 байта
            if (line[curr_index] == ' ') { // если находим пробел, то слово закончилось
                std::string word = line.substr(word_start_index, curr_index - word_start_index); // считываем это слово
                // вес равен l байт, где l - количество символов
                // максимальный вес 100 байт
                word_start_index = curr_index + 1; // переносим начало нового слово за пробел

                if (word_number.find(word) == word_number.end()) { // проверка, если слово новое уникальное
                    word_number[word] = word_number.size(); // даём индекс новому слову в хеш-таблице
                    answer.back().push_back(1); // добавляем в выходной массив в новый столбец для этого слова 1,
                    // так как один раз встретили уже
                } else
                    answer.back()[word_number[word]]++; // увеличиваем в выходном массиве значение, соответствующее
                                                        // найденному слову, на один
            }
    }

    for (auto &answer_line: answer) // выравниваем массив, заполняя недобавленные столбцы в каждой строке
        answer_line.resize(word_number.size(), 0);

    return answer; // возвращаем выходной массив
}


int main() {
    std::ifstream input_file("dataset0.txt"); // принимаем на вход файл "dataset.txt"
    std::vector<std::string> input; // создаём массив данных из входного файла
    for (std::string line; std::getline(input_file, line);) // заполняем массив данных из входного файла
        // вес равен l байт, где l - количество символов
        // максимальный вес 100 байт
        input.push_back(line);
    input_file.close(); // закрываем входной файл
    // вес input - L1 + ... + Ln байт, где Li - вес i строки, где её вес равен l байт, где l - количество символов
    // значит максимальный вес 10000 * 100 = 1000000 байт

    std::vector<std::vector<unsigned short>> answer =
            CountVectorizer(input); // создаём и заполняем массив для выходного файла
    // вес N * U * 2, где N - число строк и U - число уникальных слов
    // максимальный вес 10000 * 100 * 2 байт = 2000000 байт

    std::fstream output_file("output.txt", std::ios::out); // открываем выходной файл
    for (const auto &i: answer) { // выводим данные в выходной файл
        for (const auto &j: i)
            output_file << j << ' ';
        output_file << '\n';
    }
    output_file.close(); // закрываем выходной файл
    return 0;

    // максимальный вес за всё время 1000000 + 2000000 + 10200 + 101 + 2 + 2 + 100 байт = 3010405 байт
}
