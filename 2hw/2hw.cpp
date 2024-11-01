#include <fstream>
#include <sstream>
#include <vector>
#include "../execute.h"


std::string vector_to_string(const std::vector<std::pair<char, size_t>> &v) {
    std::stringstream ss; // O(1) - создание потока
    for (const auto [fst, snd]: v) // O(NofP) - перебор всех пар
        if (snd > 1) // O(1) - сравнение
            ss << fst << snd; // O(2) - добавление в поток
        else
            ss << fst; // O(1) - добавление в поток
    return ss.str(); // O(2*NofP) - возвращение строки

    // O(NofP) - общая сложность
}


std::string string_compression(const std::string &inp_line) {
    std::vector<std::pair<char, size_t>> out_line; // O(1) - выделение памяти
    size_t counter = 1; // O(1 + 1) - выделение + присваивание

    for (size_t i = 0; i < inp_line.size(); i++) // O(1 + 1 - выделение + присваивание
        // + (1 + 1 + 1) * N - (обращение к методу + сравнение + инкремент) * количество символов строке)
        if (i == inp_line.size() - 1 or inp_line[i] != inp_line[i + 1]) // O(1 + 1 + 1 - обращение к методу + вычитание + сравнение
            // + 1 - логическое или, если первое верно, то второе не будет проверяться
            // + 1 + 1 + 1 - 2 обращения по индексу + сравнение)
            out_line.emplace_back(inp_line[i], counter), counter = 1; // O(1 + 1 + 1 - обращение по индексу + создание пары + метод добавления в массив
            // + 1 - присваивание)
        else
            counter++; // O(1) - инкремент

    return vector_to_string(out_line);
    // O(N + NofP) - общая сложность
    // NofP - количество пар "буква, число"
}


bool compare_function(const std::string &s1, const std::string &s2) {
    return s1 == s2;
}


int main() {
    tester(3, string_compression, "C:/Users/vorandpav_mini/Documents/CppProject/polygon/2hw/tests/", compare_function);
    return 0;
}
