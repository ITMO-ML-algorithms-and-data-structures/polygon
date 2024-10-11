#include <fstream>
#include <sstream>
#include <vector>

std::string vectorToString(const std::vector<std::pair<char, size_t>> &v) {
    std::stringstream ss; // O(1)
    for (const auto [fst, snd]: v) // O(NofP)
        ss << fst << snd; // O(2)
    return ss.str(); // O(1)
    // O(2 + NofP * 2)
}


std::string stringCompression(const std::string &inp_line) {
    std::vector<std::pair<char, size_t>> out_line; // O(1)
    size_t counter = 1; // O(2)

    for (int i = 0; i < inp_line.size(); i++) // O(N)
        if (i == inp_line.size() - 1 or inp_line[i] != inp_line[i + 1]) // O(3 + 4 = 7)
            out_line.emplace_back(inp_line[i], counter), counter = 1; // O(4)
        else
            counter++; // O(1)

    return vectorToString(out_line); // O(7*N + NofP * 4 + (N - NofP),
    // NofP - количество пар "буква, число"
}


int main() {
    std::ifstream inputFile; // O(1)
    inputFile.open("dataset.txt"); // O(1)
    std::string line; // O(1)
    inputFile >> line; // O(N), N - длина строки на ввод
    inputFile.close(); // O(1)

    line = stringCompression(line); // O(1)

    std::ofstream outputFile; // O(1)
    outputFile.open("output.txt"); // O(1)
    outputFile << line; // O(NofP * 2)
    outputFile.close(); // O(1)
    return 0; // O(N)
}
