#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cassert>


void CountVectorizer(std::vector<std::string>& data, std::vector<std::vector<int>>& result) {
    // Глоссарий для хранения уникальных слов и Matches для сопоставления слов индексам
    
//    (кол-во уникальных слов) раз по (sizeof(std::string) + длина слова * sizeof(char) + sizeof(bool) + доп расходы Хеш-таблицы)
//    (кол-во уникальных слов) раз по (24 + длина слова + 1 + доп расходы Хеш-таблицы)
//    (кол-во уникальных слов) раз по (25 + длина слова + доп расходы Хеш-таблицы)
    std::unordered_map<std::string, bool> glossariy;
    
//    (кол-во уникальных слов) раз по (sizeof(std::string) + длина слова * sizeof(char) + sizeof(int) + доп расходы Хеш-таблицы)
//    (кол-во уникальных слов) раз по (24 + длина слова + 4 + доп расходы Хеш-таблицы)
//    (кол-во уникальных слов) раз по (28 + длина слова + доп расходы Хеш-таблицы)
    std::unordered_map<std::string, int> matches;
    
    // Заполнение Глоссария
    for (const auto& line: data) {
        if (line.length() == 0) {
            continue;
        }
        std::string current_word = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ') {
                current_word += line[i];
            } else if ((line[i] == ' ') && (current_word.length() > 0)) {
                glossariy[current_word] = true;
                current_word = "";
            }
        }
        if (line[line.length() - 1] != ' ') {
            glossariy[current_word] = true;
        }
    }
    
    // Объявление Matches
    int i = 0;
    for (const auto& val : glossariy) {
        matches[val.first] = i;
        i++;
    }
    
    // Зааполнение result по шаблону Matches
    for (const auto& line : data) {
        std::string current_word = "";
        std::vector<int> current_line_bow(i, 0);
        if (line.length() == 0) {
            result.push_back(current_line_bow);
            continue;
        }
        for (int j = 0; j < line.length(); j++) {
            if (line[j] != ' ') {
                current_word += line[j];
            } else if ((line[j] == ' ') && (current_word.length() > 0)) {
                current_line_bow[matches[current_word]]++;
                current_word = "";
            }
        }
        if (line[line.length() - 1] != ' ') {
            current_line_bow[matches[current_word]]++;
        }
        result.push_back(current_line_bow);
    }
}


void TestCountVectorizer_Simple() {
    std::vector<std::string> data = {
        "hello world",
        "hello",
        "world hello"
    };
    std::vector<std::vector<int>> result;
    CountVectorizer(data, result);

    std::vector<std::vector<int>> expected = {
        {1, 1},
        {0, 1},
        {1, 1}
    };
    bool done = true;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (result[i][j] != expected[i][j]) {
                done = false;
                break;
            }
        }
        if (!done) {
            break;
        }
    }
    if (done) {
        std::cout << "Тест 1 прошел успешно." << std::endl;
    } else {
        std::cout << "Тест 1 НЕ прошел успешно." << std::endl;
    }
}

void TestCountVectorizer_EmptyAndDuplicates() {
    std::vector<std::string> data = {
        "",
        "test test test",
        "example test"
    };
    std::vector<std::vector<int>> result;
    CountVectorizer(data, result);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 3},
        {1, 1}
    };
    
    bool done = true;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (result[i][j] != expected[i][j]) {
                done = false;
                break;
            }
        }
        if (!done) {
            break;
        }
    }
    if (done) {
        std::cout << "Тест 2 прошел успешно." << std::endl;
    } else {
        std::cout << "Тест 2 НЕ прошел успешно." << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    TestCountVectorizer_Simple();
    TestCountVectorizer_EmptyAndDuplicates();
    std::ifstream fin;
    fin.open("dataset.txt");
    
//    sizeof(std::vector<std::string>) + сумма n раз (sizeof(std::string) + длина слова * sizeof(char))
//    24 + сумма n раз (24 + длина слова)
    std::vector<std::string> data;
    
//    n * (sizeof(std::vector<int>) + кол-во уникальных слов * sizeof(int))
//    n * (24 + кол-во уникальных слов * 4)
    std::vector<std::vector<int>> result;
    
//    sizeof(std::string) + длина слова * sizeof(char)
//    24 + длина слова
    std::string line;
    while (getline(fin, line)) {
        data.push_back(line);
    }
    fin.close();
    
    CountVectorizer(data, result);

    
    for (auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}

