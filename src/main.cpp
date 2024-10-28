#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> 
#include <sstream>

#define LOG(X) std::cout<<X<<"\n";

size_t GLOB_MEM_USED = 0;
void* operator new(size_t size) {
    GLOB_MEM_USED += size;
    return malloc(size);
}

int main() {
    std::cout << "size=? >";
    size_t size;
    std::cin >> size; // не будем устраивать доп проверки на не-интовое значение

    std::vector<std::vector<std::string>> input;
    std::string line;
    std::cin.ignore();

    for (int i = 0; i < size; ++i) {
        std::cout << ">";
        std::getline(std::cin, line);

        std::vector<std::string> words;
        std::istringstream iss(line);
        std::string word;

        while (std::getline(iss, word, ' ')) {
            words.push_back(word);
        }

        input.push_back(words);
    }

    // вот тут стартуем алгоритм ===========

    // залетим как уважаемые люди через set
    std::unordered_set<std::string> vocab;
    for (const auto& line : input) { // ну авто и авто че бубнить то, все равно set заполняем
        for (const auto& word : line) {
            vocab.insert(word);
        }
    }

    std::vector<std::string> vecVocab(vocab.begin(), vocab.end());

   for (const auto& lineWords : input) {
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

    /* считаем память */

    size_t MEM_USED = 0;
    for (const auto& inner1 : input) {
        for (const auto& inner2 : inner1) {
            MEM_USED += inner2.capacity() * sizeof(char);
        }
    }
    for (const auto& word : vocab) {
        MEM_USED += word.capacity() * sizeof(char);
    }
    for (const auto& word : vecVocab) {
        MEM_USED += word.capacity() * sizeof(char);
    }

    LOG("mem:" << MEM_USED);
    LOG("mem by overloaded `operator new`:" << GLOB_MEM_USED << "\n");

    return 0;
}