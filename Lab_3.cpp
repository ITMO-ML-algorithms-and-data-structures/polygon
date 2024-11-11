#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Функция для подсчета повторений слов в массиве
std::vector<int> count(const std::vector<std::string>& inputArray) {
    std::unordered_map<std::string, int> frequencyMap;
    
    // Считаем повторения слов
    for (const std::string& word : inputArray) {
        frequencyMap[word]++;
    }

    // Заменяем слова на число их повторений
    std::vector<int> result;
    for (const std::string& word : inputArray) {
        result.push_back(frequencyMap[word]);
    }

    return result;
}

// Функция для проверки результата теста и вывода соответствующего сообщения
void asert(bool ans) {
    if (ans) {
        std::cout << "The test is passed" << '\n';
    } else {
        std::cout << "The test is not passed" << '\n';
    }
}

// Тесты
void runTests() {
    // Тест 1
    std::vector<std::string> inputArray_1 = {"Orange", "Orange", "Orange", "Orange"};
    std::vector<int> expected_output_1 = {4, 4, 4, 4};
    std::vector<int> result_1 = count(inputArray_1);
    asert(result_1 == expected_output_1);

    // Тест 2
    std::vector<std::string> inputArray_2 = {"Red", "Green", "Red", "Blue", "Green"};
    std::vector<int> expected_output_2 = {2, 2, 2, 1, 2};
    std::vector<int> result_2 = count(inputArray_2);
    asert(result_2 == expected_output_2);

    // Тест 3
    std::vector<std::string> inputArray_3 = {" ", " ", " ", " ", " "};
    std::vector<int> expected_output_3 = {5, 5, 5, 5, 5};
    std::vector<int> result_3 = count(inputArray_3);
    asert(result_3 == expected_output_3);

    // Тест 4 - пустой массив
    std::vector<std::string> inputArray_4 = {};
    std::vector<int> expected_output_4 = {};
    std::vector<int> result_4 = count(inputArray_4);
    asert(result_4 == expected_output_4);
}

int main() {
    runTests();
    
    return 0;
}
