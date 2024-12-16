#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <set>


std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    const int cols = matrix[0].size();
    const int rows = matrix.size();
    std::vector<std::vector<int>> matrix_t(cols, std::vector<int>(rows, 0));
  
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            matrix_t[i][j] = matrix[j][i];
        }}

    return matrix_t;
}

std::vector<std::vector<int>> CountVectorizer(const int& size, const std::vector<std::string>& texts) {
    std::map<std::string, std::vector<int>> wordcount;

    for (int i = 0; i < size; i++) {
        std::istringstream text(texts[i]);

        std::string word;
        while (std::getline(text, word, ' ')) {
            if (wordcount.find(word) == wordcount.end()) {
                wordcount[word] = std::vector<int>(size);
            }
            ++wordcount[word][i];
        }
    }
    
    std::vector<std::vector<int>> vectorized_t;
    for (const auto& [word, vect] : wordcount) vectorized_t.push_back(vect);

    std::vector<std::vector<int>> vectorized = Transpose(vectorized_t);
    return vectorized;
}

void Checker(bool condition, int& fail, int& done, const bool& debug = false, const std::string& name = "") {
    if (condition) {
        ++done;
        if (debug) std::cout << name << " done\n";
    }
    else {
        ++fail;
        if (debug) std::cout << name << " fail\n";
    }
}

void Test(std::vector<std::vector<std::string>> tests, std::vector<std::vector<std::vector<int>>> valid) {
    int done = 0;
    int fail = 0;

    int length = tests.size();

    for (int i = 0; i < length; ++i) {
        std::vector<std::vector<int>> raw = Transpose(CountVectorizer(tests[i].size(), tests[i]));
        std::multiset<std::vector<int>> predicted(raw.begin(), raw.end());
        std::vector<std::vector<int>> valid_t = Transpose(valid[i]);
        std::multiset<std::vector<int>> truth(valid_t.begin(), valid_t.end());
        Checker(predicted == truth, fail, done);
    }

    std::cout << "Test done: " << done << ", test fail: " << fail;
}

int main() {
    std::vector<std::vector<std::string>> tests = { { "hello world", "hello" },
    { "apple orange", "apple banana", "banana orange" },
    { "cat dog", "dog cat", "cat cat" },
    { "one two three", "four five six" },
    { "a b c", "b c d", "c d e" } };

    std::vector<std::vector<std::vector<int>>> valid = { {{1, 1}, { 1, 0 }},
        { {1, 1, 0}, {1, 0, 1}, {0, 1, 1} },
        { {1, 1}, {1, 1}, {2, 0} },
        { {1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1} },
        { {1, 1, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 1, 1} } };

    Test(tests, valid);
}
