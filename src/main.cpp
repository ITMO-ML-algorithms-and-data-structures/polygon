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
    std::vector<std::string> splitLines;            // [24]
    std::string currentLine;                        // [32]
                                                    // [сколько бы я не тестил, тут будет 24+32=56 байт]

    for (char c : line) {                           // [1]
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
    short int size;                                     // [2]
    std::cin >> size; // не будем устраивать доп проверки на не-интовое значение

    if (size > MAX_LINES) {
        std::cout << "бро в меня столько не вместится (по условиям задачи)" << std::endl;
        return 1;
    }
    std::cin.ignore(); // фиксим прикол с переносом строки
    
    std::vector<std::vector<std::string>> arr;          // [24]

    for (int i = 0; i < size; i++) {                    // [ну тут в цикле +4]
        std::cout << "line " << i + 1 << " >";
        std::string inputLine;                          // [32]
        std::getline(std::cin, inputLine);          
        
        if (inputLine.length() >= MAX_LINE_LENGTH) {
            std::cout << "бро в меня столько не вместится (по условиям задачи)" << std::endl;
            return 1;
        }
        arr.push_back(splitLine(inputLine));            // [24 так и остается]
    }

                                                        // [итого: 2 + 24. возможно, остальное - динамическая память, но я, честно, не шарю]

    // вот тут стартуем алгоритм ===========

    // залетим как уважаемые люди через set
    std::unordered_set<std::string> vocab;              // [56]
    for (const auto& line : arr) { // ну авто и авто че бубнить то, все равно set заполняем
        for (const auto& word : line) {
            vocab.insert(word);                         // [сколько бы не sizeof() все равно 56 говорит... похоже правда динамическая память. не бейте(]
        }
    }

    std::vector<std::string> vecVocab(vocab.begin(), vocab.end()); // [24]
    delete vocab // я больше не хочу с тобой играть

   for (const auto& lineWords : arr) {                  // [24]
        // развернул цикл в обратную сторону что бы пример совпадал. как сделал - загуглил :/
        for (auto vocabIter = vecVocab.rbegin(); vocabIter != vecVocab.rend(); ++vocabIter) {       // [8 байт на указатель]    
            const std::string& vocabWord = *vocabIter;  // [32]
            bool found = false;                         // [1]
            for (const auto& word : lineWords) {        // [std::string=32]
                if (vocabWord == word) {
                    found = true;
                    break;
                }
            }
            std::cout << (found ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }

    /* считаем. хотя динамическая память нам такое не позволит
        2 + 24 + 24(vecVocab) - то, что с нами всегда
        дальше
        1) в arr лежат `size` стрингов * splitLine(x), точно подсчитать не получится.
        2) в vocab лежат от 56 до 32(стринга)*MAX_UNIQUE_WORDS

        пик используемой памяти, скорее всего, будет достигаться на 76 строке
    */

    return 0;
}