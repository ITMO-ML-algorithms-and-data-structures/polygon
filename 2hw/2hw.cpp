#include <fstream>
#include <sstream>
#include <vector>
#include "../execute.h"


std::string vector_to_string(const std::vector<std::pair<char, size_t>> &v) {
    std::stringstream ss; // O(1)
    for (const auto [fst, snd]: v) // O(NofP)
        if (snd > 1)
            ss << fst << snd;
        else
            ss << fst;
    return ss.str(); // O(1)
    // O(2 + NofP * 2)
}


std::string string_compression(const std::string &inp_line) {
    std::vector<std::pair<char, size_t>> out_line; // O(1)
    size_t counter = 1; // O(2)

    for (size_t i = 0; i < inp_line.size(); i++) // O(N)
        if (i == inp_line.size() - 1 or inp_line[i] != inp_line[i + 1]) // O(3 + 4 = 7)
            out_line.emplace_back(inp_line[i], counter), counter = 1; // O(4)
        else
            counter++; // O(1)

    return vector_to_string(out_line); // O(7*N + NofP * 4 + (N - NofP),
    // NofP - количество пар "буква, число"
}


bool compare_function(const std::string &s1, const std::string &s2) {
    return s1 == s2;
}


int main() {
    tester(3, string_compression, "C:/Users/vorandpav_mini/Documents/CppProject/polygon/2hw/tests/", compare_function);
    return 0;
}
