#include "pch.h"
#include <set>
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;
using Uniquenums = std::set<unsigned long long>; // 16 bite каждый пустой set


void delete_duplicates(std::vector<unsigned long long>& values, Uniquenums& uniqueValues) {
    for (const unsigned long long& value : values) {
        uniqueValues.insert(value);   // 8*n bite (где n - кол-во уникальных эл-в)
    }

    values.clear();
    for (const auto& uniqueValue : uniqueValues) {
        values.push_back(uniqueValue);// 8*n bite (где n - кол-во уникальных эл-в)
    }
}

int other_main() {
    Uniquenums uniqueValues; //16 bite
    std::vector<unsigned long long> numbers; //24 bite

    // Удаление дубликатов
    delete_duplicates(numbers, uniqueValues);


    // Вывод результата
    for (const auto& num : numbers) {
        std::cout << num;
        if (&num != &numbers.back()) {
            std::cout << ", "; // Добавление запятой между элементами
        }
    }
    return 0;
}

//ИТОГ: (8n+8n+16+24)bite (вроде посчитал правильно не бейте пж, я с юнит тестами мучался)

// Класс для тестирования
class RemoveDuplicatesTest : public testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Тесты


TEST_F(RemoveDuplicatesTest, RemovesDuplicateNumbers1) {
    std::vector<unsigned long long> input;
    std::vector<unsigned long long> expected;
    std::ifstream infile("C:/Users/agafo/Desktop/input.txt");
    string line; // переменная для хранения одной строки файла (ее вес неизвестен тк варьируется от входного файлика)

    while (getline(infile, line, ',')) { // читаем строки
        istringstream ss(line);
        unsigned long long number; // 8bite

        while (ss >> number) { // 
            input.push_back(number); // O(1)
        }
    }

    infile.close();

    std::ifstream outfile("C:/Users/agafo/Desktop/expected.txt");
    string line_out; // переменная для хранения одной строки файла (ее вес неизвестен тк варьируется от входного файлика)

    while (getline(outfile, line_out, ',')) { // читаем строки
        istringstream ss(line_out);
        unsigned long long number_out; // 8bite

        while (ss >> number_out) { // 
            expected.push_back(number_out); // O(1)
        }
    }

    infile.close();
    outfile.close();


    Uniquenums uniqueValues;

    delete_duplicates(input, uniqueValues);

    ASSERT_EQ(expected, input);
}


TEST_F(RemoveDuplicatesTest, RemovesDuplicateNumbers2) {
    std::vector<unsigned long long> input;
    std::vector<unsigned long long> expected = {5, 6, 8, 9, 12, 45, 577, 5215};
    
    std::ifstream infile("C:/Users/agafo/Desktop/input2.txt");
    string line;

    while (getline(infile, line, ',')) { // читаем строки
        istringstream ss(line);
        unsigned long long number; // 8bite

        while (ss >> number) { // 
            input.push_back(number); // O(1)
        }
    }

    infile.close();
    
    Uniquenums uniqueValues;

    delete_duplicates(input, uniqueValues);

    ASSERT_EQ(expected, input);
}


TEST_F(RemoveDuplicatesTest, RemovesDuplicateNumbers3) {
    std::vector<unsigned long long> input = { 1, 7, 8, 9, 2, 1, 7, 4, 9, 8 };
    std::vector<unsigned long long> expected = { 1, 2, 4, 7, 8, 9 };
    Uniquenums uniqueValues;

    delete_duplicates(input, uniqueValues);

    ASSERT_EQ(expected, input);
}


TEST_F(RemoveDuplicatesTest, PreservesOrderOfElements) {
    std::vector<unsigned long long> input = {1, 2, 3, 4, 5, 6};
    std::vector<unsigned long long> expected = {1, 2, 3, 4, 5, 6};
    Uniquenums uniqueValues;

    delete_duplicates(input, uniqueValues);

    ASSERT_EQ(expected, input);
}

TEST_F(RemoveDuplicatesTest, HandlesEmptyInputCorrectly) {
    std::vector<unsigned long long> empty;
    std::vector<unsigned long long> expected;
    Uniquenums uniqueValues;

    delete_duplicates(empty, uniqueValues);

    ASSERT_EQ(expected, empty);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
