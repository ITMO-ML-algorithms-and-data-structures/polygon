#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>



void CountVectorizer(std::vector<std::string> * data, std::vector<std::vector<int>> * result) {
    // Глоссарий для хранения уникальных слов и Matches для сопоставления слов индексам
    std::unordered_set<std::string> glossariy;
    std::unordered_map<std::string, int> matches;
    
    // Заполнение Глоссария
    for (const auto& line: *data) {
        std::string current_word = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ') {
                current_word += line[i];
            } else if (line[i] == ' ') {
                glossariy.insert(current_word);
                current_word = "";
            }
        }
        if (line[line.length() - 1] != ' ') {
            glossariy.insert(current_word);
        }
    }
    
    // Объявление Matches
    int i = 0;
    for (const auto& val : glossariy) {
        matches[val] = i;
        i++;
    }
    
    // Зааполнение result по шаблону Matches
    for (const auto& line : *data) {
        std::string current_word = "";
        std::vector<int> current_line_bow(i, 0);
        for (int j = 0; j < line.length(); j++) {
            if (line[j] != ' ') {
                current_word += line[j];
            } else if (line[j] == ' ') {
                current_line_bow[matches[current_word]]++;
                current_word = "";
            }
        }
        if (line[line.length() - 1] != ' ') {
            current_line_bow[matches[current_word]]++;
        }
        result -> push_back(current_line_bow);
    }
    
    for (auto& pair : matches) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }
//    std::cout << sizeof(glossariy) << " " << sizeof(matches) << std::endl;
}


int main(int argc, const char * argv[]) {
    /*std::cout << "ДАТАСЕТ ДОЛЖЕН ЛЕЖАТЬ В dataset.txt И БЫТЬ НЕ ПУСТЫМ" << std::endl;*/
    std::ifstream fin;
    fin.open("dataset.txt");
    std::vector<std::string> data;
    std::vector<std::vector<int>> result;
    
    std::string line;
    while (getline(fin, line)) {
        data.push_back(line);
    }
    fin.close();
    
    CountVectorizer(&data, &result);

    
    for (auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
//    std::cout << sizeof(data) << " " << sizeof(result) << std::endl;

    
    return 0;
}
