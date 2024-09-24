#include <fstream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<size_t> > CountVectorizer(const std::vector<std::string> &input) {
    std::vector<std::vector<size_t> > answer;
    answer.reserve(input.size());
    std::unordered_map<std::string, size_t> word_number;

    for (const auto &input_line: input) {
        std::string line = input_line + ' ';
        answer.push_back(std::vector<size_t>(word_number.size(), 0));
        size_t word_start_index = 0;

        for (size_t curr_index = 0; curr_index < line.length(); curr_index++)
            if (line[curr_index] == ' ') {
                std::string word = line.substr(word_start_index, curr_index - word_start_index);
                word_start_index = curr_index + 1;

                if (word_number.find(word) == word_number.end()) {
                    word_number[word] = word_number.size();
                    answer.back().push_back(1);
                } else
                    answer.back()[word_number[word]]++;
            }
    }

    for (auto &answer_line: answer)
        answer_line.resize(word_number.size(), 0);

    return answer;
}

int main() {
    std::ifstream input_file("dataset.txt");
    std::vector<std::string> input;
    for (std::string line; std::getline(input_file, line);)
        input.push_back(line);
    input_file.close();

    std::vector<std::vector<size_t> > answer = CountVectorizer(input);

    std::fstream output_file("output.txt", std::ios::out);
    for (const auto &i: answer) {
        for (const auto &j: i)
            output_file << j << ' ';
        output_file << '\n';
    }
    output_file.close();
    return 0;
}
