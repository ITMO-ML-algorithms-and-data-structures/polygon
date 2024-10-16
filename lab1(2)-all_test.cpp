#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <fstream>
#include <sstream>



// Функция для проверки входных данных
void validate_input(const std::vector<std::string>& arr) {
    if (arr.size() > 10000) {
        throw std::invalid_argument("Количество строк не должно превышать 10^4");
    }
    for (const auto& str : arr) {
        if (str.empty()) {
            throw std::invalid_argument("Строки не должны быть пустыми");
        }
        if (str.length() > 100) {
            throw std::invalid_argument("Длина строки не должна превышать 10^2");
        }
    }

    std::unordered_set<std::string> unique_words(arr.begin(), arr.end());
    if (unique_words.size() > 100) {
        throw std::invalid_argument("Количество уникальных элементов не должно превышать 10^2");
    }
}

// Тесты
TEST_CASE("Input validation tests") {
    SECTION("Valid input") {
        std::vector<std::string> valid_input = { "Hello", "world", "!" };
        REQUIRE_NOTHROW(validate_input(valid_input));
    }

    SECTION("Empty string") {
        std::vector<std::string> invalid_input = { "Hello", "", "world" };
        REQUIRE_THROWS_AS(validate_input(invalid_input), std::invalid_argument);
    }

    SECTION("Too many strings") {
        std::vector<std::string> invalid_input(10001, "Valid string");
        REQUIRE_THROWS_AS(validate_input(invalid_input), std::invalid_argument);
    }

    SECTION("String too long") {
        std::vector<std::string> invalid_input = { "Hello", std::string(101, 'a'), "world" };
        REQUIRE_THROWS_AS(validate_input(invalid_input), std::invalid_argument);
    }

    SECTION("Too many unique elements") {
        std::vector<std::string> invalid_input;
        for (int i = 0; i < 101; ++i) {
            invalid_input.push_back("Word" + std::to_string(i));
        }
        REQUIRE_THROWS_AS(validate_input(invalid_input), std::invalid_argument);
    }
}

TEST_CASE("find_index function tests") {
    std::unordered_set<std::string> test_set = { "Hello", "world", "!" };

    SECTION("Existing element") {
        REQUIRE(find_index(test_set, "Hello") == 0);
        REQUIRE(find_index(test_set, "world") == 1);
    }

    SECTION("Non-existing element") {
        REQUIRE(find_index(test_set, "Nonexistent") == -1);
    }
}
//конец тестов



//Решение задачи


//Считывание данных из сформированного датасета
std::vector<std::string> load_data(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        while (std::getline(ss, item, ',')) {
            data.push_back(item);
        }
    }

    return data;
}
//функция находящая индекс элемента в set по его значению.
int find_index(const std::unordered_set<std::string>& my_set, const std::string& value) {// Вес в нашем примере: 
    auto it = my_set.begin();//размер поступающей строки (кол-во символов) + до 1е2 (тк строка поступит из set)
    for (int i = 0; it != my_set.end(); ++i) {
        if (*it == value) {
            return i;
        }
        ++it;
    }
    return -1;
}
int main() {
    //std::vector<std::string> arr = { "Hello world !","Hello","world","!" };//На вход 21 байт (кол-во символов ,т.е. О(N)) ,из условия может быть до 1е2*1е4 байт(возможное кол-во строк * возможная длинна каждого слова)
    //std::cout << arr.capacity();4 длина с резервом

    std::vector<std::string> arr = load_data("dataset.csv"); // (Если нужно принять данные из сформированного датасета)

    std::vector<std::vector<std::string>> doubl_arr;// двумерный массив для хранения массивов words_in_string (в которых уже разделенные слова)
    std::vector<std::string> words;//для хранения отдельных слов
    for (int i = 0; i < arr.size(); i++) {//+4байта
        std::vector<std::string> words_in_string;
        int pos = 0;//номер позиции пробела в строке; std::cout<<sizeof(pos);//4 байт

        std::string str = arr[i];
        while ((pos = str.find(' ')) != std::string::npos) {
            words_in_string.push_back(str.substr(0, pos)); // добавляем слово до пробела в вектор
            words.push_back(str.substr(0, pos));
            str = str.substr(pos + 1); // обновляем строку
        }
        words.push_back(str); // добавляем последнее слово в вектор
        words_in_string.push_back(str);//после всех добавлений 21 байт (кол-во символов) ,из условия может быть до 1е2*1е4 байт
        doubl_arr.push_back(words_in_string);//после всех добавлений 21 байт (кол-во символов) ,из условия может быть до 1е2*1е4 байт
    }

    std::unordered_set<std::string> set_words(words.begin(), words.end());// 3 элемента, 11 байт ,из условия может быть до 1е2*1е2(кол-во уникальных слов на длинную строки (которая может полностью быть словом))
    for (int j = 0; j < doubl_arr.size(); ++j) { // цикл проходящий по массивам слов входящих в строку +4байта
        std::vector<std::string> results_string(set_words.size(), "0");//3 байта ,может быть до 1е2 байт
        for (int k = 0; k < doubl_arr[j].size(); ++k) { // цикл проходящийся внутри массива строки +4 байта
            int number_str = find_index(set_words, doubl_arr[j][k]); // используем функцию ,чтобы понять индекс этого элемента по множеству и построить все результаты на подобии данного множества
            results_string[number_str] = doubl_arr[j][k]; // заменяем строку ноль на значение строки ,для которой ы должны будем найти количество вхождений
        }
        doubl_arr[j] = results_string;
    }

    for (int j = 0; j < doubl_arr.size(); ++j) { // цикл проходящий по массивам слов входящих в строку+4байта
        for (int k = 0; k < doubl_arr[j].size(); ++k) { // цикл проходящийся внутри массива строки +4 байта
            std::vector<int> results(set_words.size(), 0); // создаем вектор где будет хранится сколько раз встречается слово в строке; 4 байта(int) * 3   ,возможно до 1е2 * 4 байта
            //Так как строк 3 в конце будет 4*3*3 <=> 4*O(l)*O(n)
            if (set_words.contains(doubl_arr[j][k])) {//если "ключ" существует ,то считаем 
                ++results[k];
                std::cout << results[k] << ' ';
            }
            else {
                std::cout << results[k] << ' ';
            }
        }
        std::cout << '\n';
    }
}
//Итого на нашем примере: 21+21+21+4+4+4+4+4+3*4*3=133 байт
//Итого если n-кол-во строк ,m-максимальная длинна строки, l-кол-во уникальных слов , 5 - кол-во перменных : 3*O(n*m) + (4 байта *5) + 4*O(l)*O(n).







