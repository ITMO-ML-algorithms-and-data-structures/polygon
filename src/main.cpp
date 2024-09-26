#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// докинем условия
#define MAX_LINES 10000
#define MAX_LINE_LENGTH 100
#define MAX_UNIQUE_WORDS 100
#define MAX_WORD_LENGTH 100

// немного утилов
std::vector<std::string> splitLine(const std::string& line) {
    std::vector<std::string> splitLines;
    std::string currentLine;

    for (char c : line) {
        if (c == ' ') { 
            if (!currentLine.empty()) {
                splitLines.push_back(currentLine);
                currentLine.clear();
            }
        } else currentLine += c;
    }

    if (!currentLine.empty()) splitLines.push_back(currentLine);
    return splitLines;
}

int main() {
    std::cout << "size=? >";
    short int size;
    std::cin >> size; // не будем устраивать доп проверки на не-интовое значение

    if (size > MAX_LINES) {
        std::cout << "бро в меня столько не вместится (по условиям задачи)" << std::endl;
        return 1;
    }
    std::cin.ignore(); // фиксим прикол с переносом строки
    
    std::vector<std::vector<std::string>> arr;

    for (int i = 0; i < size; i++) {
        std::cout << "line " << i + 1 << " >";
        std::string inputLine;
        std::getline(std::cin, inputLine);
        
        if (inputLine.length() >= MAX_LINE_LENGTH) {
            std::cout << "бро в меня столько не вместится (по условиям задачи)" << std::endl;
            return 1;
        }
        arr.push_back(splitLine(inputLine));
    }

    // вот тут стартуем алгоритм ===========

    // залетим как уважаемые люди через set
    std::unordered_set<std::string> vocab;
    for (const auto& line : arr) { // ну авто и авто че бубнить то
        for (const auto& word : line) {
            vocab.insert(word);
        }
    }

    std::vector<std::string> vecVocab(vocab.begin(), vocab.end());
    vocab.clear(); // я больше не хочу с тобой играть

   for (const auto& lineWords : arr) {
        // развернул цикл в обратную сторону что бы пример совпадал. как сделал - загуглил :/
        for (auto vocabIter = vecVocab.rbegin(); vocabIter != vecVocab.rend(); ++vocabIter) { 
            const std::string& vocabWord = *vocabIter;
            bool found = false;
            for (const auto& word : lineWords) {
                if (vocabWord == word) {
                    found = true;
                    break;
                }
            }
            std::cout << (found ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}