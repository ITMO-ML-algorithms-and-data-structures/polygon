#include <cstddef>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

class CountVectorizer {
private:
    std::vector<std::string> vocabulary;
    std::unordered_map<std::string, int> word_to_index;
    
    size_t memory_usage = 0;

    void update_memory_usage() {
        memory_usage = 0;
        memory_usage += vocabulary.capacity() * sizeof(std::string);
        for (const auto& word : vocabulary) {
            memory_usage += word.capacity() * sizeof(char);
        }

        // I've used gpt for counting memory usage for unordered_map
        memory_usage += word_to_index.bucket_count() * sizeof(void*);
        for (const auto& pair : word_to_index) {
            memory_usage += pair.first.capacity() * sizeof(char);
            memory_usage += sizeof(int);
        }
    }

public:
    CountVectorizer() = default;

    std::vector<std::vector<int>> fit_transform(const std::vector<std::string>& texts) {
        vocabulary.clear();
        word_to_index.clear();

        for (const auto& text : texts) {
            std::istringstream iss(text);
            std::string word;
            while (iss >> word) {
                if (word_to_index.find(word) == word_to_index.end()) {
                    word_to_index[word] = static_cast<int>(vocabulary.size());
                    vocabulary.push_back(word);
                }
            }
        }

        std::vector<std::vector<int>> result(texts.size(), std::vector<int>(vocabulary.size(), 0));

        for (size_t i = 0; i < texts.size(); ++i) {
            std::istringstream iss(texts[i]);
            std::string word;
            while (iss >> word) {
                int const index = word_to_index[word];
                result[i][index]++;
            }
        }

        update_memory_usage();
        return result;
    }

    [[nodiscard]]
    const std::vector<std::string>& get_vocabulary() const {
        return vocabulary;
    }

    [[nodiscard]]
    size_t get_memory_usage() const {
        return memory_usage;
    }
};


// Test main, if you want to use test.cpp you should comment this.

// int main() {
//     std::vector<std::string> const texts = {
//         "This is the first document",
//         "This document is the second document",
//         "And this is the third one",
//         "Is this the first document"};

//     CountVectorizer vectorizer;
//     auto result = vectorizer.fit_transform(texts);

//     std::cout << "Vocabulary:" << '\n';
//     const auto& vocab = vectorizer.get_vocabulary();
//     for (size_t i = 0; i < vocab.size(); ++i) {
//         std::cout << i << ": " << vocab[i] << '\n';
//     }

//     std::cout << "\nResult matrix:" << '\n';
//     for (const auto& row : result) {
//         for (int const count : row)
//         {
//             std::cout << count << " ";
//         }
//         std::cout << '\n';
//     }

//     std::cout << "\nMemory usage: " << vectorizer.get_memory_usage() << " bytes" << '\n';

// }