//Перемешивание элементов массива hard. Tischenko Pavel J3112

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <gtest/gtest.h>

using namespace std;

vector<unsigned long long> replace_two_elements(std::vector<unsigned long long>& values, unsigned long long a, unsigned long long b) {
    unsigned long long ghost; // 8 bit
    ghost = values[a];
    values[a] = values[b];
    values[b] = ghost;
    return values;
}


void replace_objects(vector<unsigned long long>& values, unsigned long long randomIndex, unsigned long long lowHalfArrayInd, unsigned long long len_arr) {
    if (values.empty()) {
        return;
    }
    replace_two_elements(values, randomIndex, values.size() - 1); //O(1)
    for (unsigned long long j = 1; (j + randomIndex) < lowHalfArrayInd; j++) {
        replace_two_elements(values, randomIndex + j, len_arr - 1 - j); //O(n/2)
    }
    for (unsigned long long i = 1; (i + randomIndex) < lowHalfArrayInd && randomIndex > i; i++) {
        replace_two_elements(values, randomIndex - i, len_arr - 1 - lowHalfArrayInd + i); //O(n/2)
    }
    if (len_arr % 2 == 1) {
        replace_two_elements(values, lowHalfArrayInd, randomIndex); // O(1)
    }
}//summary: O(n)

void pushResult(vector<unsigned long long>& numbers) {
    // Вывод результата
    for (const auto& num : numbers) { //вывод за O(n)
        std::cout << num;
        if (&num != &numbers.back()) {
            std::cout << ", "; // Добавление запятой между элементами
        }
    }
    std::cout << std::endl;
}

int other_main() {
    std::vector<unsigned long long> numbers; //24 bite + 8*n (n - колво элементов)
    if (numbers.size() >= 2) {
        ///определяем рандом индекс эл-а исход массива
        unsigned long long len_arr = numbers.size(); // 8 bit; O(1)

        unsigned long long lowHalfArrayInd = len_arr / 2 - ((len_arr % 2) / 2);// 8 bit
        std::random_device rd;
        unsigned long long randomIndex = rd() % (lowHalfArrayInd);// 8 bit
        // перемешка

        replace_objects(numbers, randomIndex, lowHalfArrayInd, len_arr); //O(n)

        pushResult(numbers);
    }
    if (numbers.size() == 1) {
        pushResult(numbers);
    }
    else {
        cout << "" << endl;
    }
    return 0;
}

//ИТОГ: O(n); Memory: 24 + 8*n + (8 + 8 + 8) + (8) + (8 + 8) = 72 + 8*n (n - колво элементов массива)   

// Тесты!!!!!!





class RandomPermutationTest1 : public testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};




TEST_F(RandomPermutationTest1, EmptyArray) {
    std::vector<unsigned long long> input = {};
    unsigned long long randomIndex = 0; // не имеет значения
    unsigned long long lowHalfArrayInd = 0; // не имеет значения
    unsigned long long len_arr = input.size(); // 0
    replace_objects(input, randomIndex, lowHalfArrayInd, len_arr);

    // Проверяем, что массив остается пустым
    ASSERT_TRUE(input.empty());
}

TEST_F(RandomPermutationTest1, SingleElement) {
    std::vector<unsigned long long> input = { 42 };
    unsigned long long randomIndex = 0;
    unsigned long long lowHalfArrayInd = 0;
    unsigned long long len_arr = input.size();

    replace_objects(input, randomIndex, lowHalfArrayInd, len_arr);

    // Проверяем, что массив остается без изменений
    ASSERT_EQ(input.size(), 1);
    ASSERT_EQ(input[0], 42);
}

class RandomPermutationTest2 : public testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};


TEST(RandomPermutationTest2, MultipleElements) {
    std::vector<unsigned long long> input = {1, 2, 3, 4};
    std::vector<unsigned long long> result = {1, 2, 3, 4};
    unsigned long long randomIndex = 0;
    unsigned long long lowHalfArrayInd = 2;
    unsigned long long len_arr = input.size();
    replace_objects(result, randomIndex, lowHalfArrayInd, len_arr);
    ASSERT_EQ(result.size(), 4);
    ASSERT_TRUE(std::find(result.begin(), result.end(), 1) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), 2) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), 3) != result.end());
    ASSERT_TRUE(std::find(result.begin(), result.end(), 4) != result.end());
    ASSERT_NE(result, input); // порядок должен отличаться
}

TEST(RandomPermutationTest2, overMnogoElementov) {
    std::vector<unsigned long long> input; //24 bite + 8*n (n - колво элементов)

    std::ifstream infile("numbers.txt");
    string line;

    while (getline(infile, line, ',')) { // читаем строки
        istringstream ss(line);
        unsigned long long number; // 8bite

        while (ss >> number) { // 
            input.push_back(number); // O(1)
        }
    }

    infile.close();
    vector<unsigned long long> copy_input;
    copy_input = input;

    unsigned long long randomIndex = 0;
    unsigned long long lowHalfArrayInd = (pow(10, 6))/2;
    unsigned long long len_arr = input.size();
    replace_objects(input, randomIndex, lowHalfArrayInd, len_arr);
    ASSERT_EQ(input.size(), pow(10, 6));
    ASSERT_NE(input[0], copy_input[0]);

}




int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



