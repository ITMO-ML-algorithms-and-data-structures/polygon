#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include "countvectorizer.cpp" 

void test_empty_input() {
    CountVectorizer vectorizer;
    std::vector<std::string> const texts;
    auto result = vectorizer.fit_transform(texts);
    assert(result.empty());
    assert(vectorizer.get_vocabulary().empty());
    assert(vectorizer.get_memory_usage() == 0);
    std::cout << "test_empty_input passed.\n";
    std::cout << "Memory used: " << vectorizer.get_memory_usage() << " bytes.\n\n";

}

void test_single_document() {
    CountVectorizer vectorizer;
    std::vector<std::string> const texts = {"hello world hello"};
    auto result = vectorizer.fit_transform(texts);
    const auto& vocab = vectorizer.get_vocabulary();
    assert(vocab.size() == 2);
    assert(vocab[0] == "hello");
    assert(vocab[1] == "world");
    assert(result.size() == 1);
    assert(result[0].size() == 2);
    assert(result[0][0] == 2);
    assert(result[0][1] == 1);
    std::cout << "test_single_document passed.\n";
    std::cout << "Memory used: " << vectorizer.get_memory_usage() << " bytes.\n\n";

}

void test_multiple_documents() {
    CountVectorizer vectorizer;
    std::vector<std::string> const texts = {
        "apple banana apple",
        "banana fruit banana",
        "fruit apple banana"};
    auto result = vectorizer.fit_transform(texts);
    const auto& vocab = vectorizer.get_vocabulary();
    assert(vocab.size() == 3);
    assert(vocab[0] == "apple");
    assert(vocab[1] == "banana");
    assert(vocab[2] == "fruit");
    assert(result.size() == 3);
    assert(result[0][0] == 2);
    assert(result[0][1] == 1);
    assert(result[0][2] == 0);
    assert(result[1][0] == 0);
    assert(result[1][1] == 2);
    assert(result[1][2] == 1);
    assert(result[2][0] == 1);
    assert(result[2][1] == 1);
    assert(result[2][2] == 1);
    std::cout << "test_multiple_documents passed.\n";
    std::cout << "Memory used: " << vectorizer.get_memory_usage() << " bytes.\n\n";

}

void test_i_hate_linal_and_matan() {
    CountVectorizer vectorizer;
    std::vector<std::string> const texts = {
        "i hate matan",
        "i hate linal"
    };
    auto result = vectorizer.fit_transform(texts);
    const auto& vocab = vectorizer.get_vocabulary();
    
    assert(vocab.size() == 4);
    assert(vocab[0] == "i");
    assert(vocab[1] == "hate");
    assert(vocab[2] == "matan");
    assert(vocab[3] == "linal");
    
    assert(result.size() == 2);
    assert(result[0].size() == 4);
    assert(result[1].size() == 4);
    
    assert(result[0][0] == 1);
    assert(result[0][1] == 1);
    assert(result[0][2] == 1);
    assert(result[0][3] == 0);
    
    assert(result[1][0] == 1);
    assert(result[1][1] == 1);
    assert(result[1][2] == 0);
    assert(result[1][3] == 1);
    
    std::cout << "test_i_hate_linal_and_matan passed (I really do).\n";
    std::cout << "Memory used: " << vectorizer.get_memory_usage() << " bytes.\n\n";
}


void test_large_input() {

    // Количество строк - до 1e4
    // Длина строки - до 1e2
    // Кол-во уникальных слов - до 1e2
    // Кол-во повторений одного слова в строке - до 100

    const int num_texts = 10000;
    const int words_per_text = 100;
    const int unique_words = 100;
    const int max_repeats = 100;

    std::vector<std::string> uniqueWordList;
    uniqueWordList.reserve(unique_words);
    for (int i = 0; i < unique_words; ++i)
    {
        uniqueWordList.push_back("word" + std::to_string(i));
    }

    std::vector<std::string> texts;
    texts.reserve(num_texts);
    for (int i = 0; i < num_texts; ++i) {
        std::string text;
        for (int j = 0; j < words_per_text; ++j) {
            std::string const word = uniqueWordList[j % unique_words];
            for (int r = 0; r < max_repeats; ++r) {
                text += word + " ";
            }
        }
        texts.emplace_back(text);
    }

    CountVectorizer vectorizer;
    auto result = vectorizer.fit_transform(texts);
    const auto& vocab = vectorizer.get_vocabulary();

    assert(vocab.size() == unique_words);
    assert(result.size() == static_cast<size_t>(num_texts));
    for (const auto& row : result) {
        assert(row.size() == static_cast<size_t>(unique_words));
        for (int const count : row)
        {
            assert(count == max_repeats);
        }
    }

    std::cout << "test_large_input passed.\n";
    std::cout << "Memory used: " << vectorizer.get_memory_usage() << " bytes.\n\n";

}

int main() {
    test_empty_input();
    test_single_document();
    test_multiple_documents();
    test_i_hate_linal_and_matan();
    test_large_input();
    std::cout << "All tests passed successfully.\n";
}

// Output:
// test_empty_input passed.
// Memory used: 0 bytes.

// test_single_document passed.
// Memory used: 160 bytes.

// test_multiple_documents passed.
// Memory used: 280 bytes.

// test_i_hate_linal_and_matan passed (I really do).
// Memory used: 328 bytes.

// test_large_input passed.
// Memory used: 9448 bytes.

// All tests passed successfully.