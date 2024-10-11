#include <iostream> 
#include <fstream> 
#include <unordered_map>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>


//  проверка на изоморфность
bool areIsomorphic(const std::string &str1, const std::string &str2) { 
        if (str1.length() != str2.length()) {
        return false;
    }

    // контейнеры для сопоставления
    std::unordered_map<char, char> mapping1;
    std::unordered_map<char, char> mapping2;


    for (size_t i = 0; i < str1.length(); ++i) {
        char char1 = str1[i];
        char char2 = str2[i];

        // проверка соответствия для первого
        if (mapping1.count(char1)) {
            if (mapping1[char1] != char2) {
                return false;
            }
        } else {
            mapping1[char1] = char2;
        }

        // проверка соответствия для второго
        if (mapping2.count(char2)) {
            if (mapping2[char2] != char1) {
                return false;
            }
        } else {
            mapping2[char2] = char1;
        }
    }

    return true;
}

// читаем строки из файла и проверка изоморфности
bool checkIsomorphismFromFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return false;
    }

    std::string line;
    if (getline(file, line)) {
        std::istringstream inputString(line);
        std::string str1, str2;
        if (inputString >> str1 >> str2) {
            return areIsomorphic(str1, str2);
        }
    }

    return false;
}

// тестируем
void testAreIsomorphic() {
    assert(areIsomorphic("egg", "add") == true);
    assert(areIsomorphic("foo", "bar") == false);
    assert(areIsomorphic("paper", "title") == true);
    assert(areIsomorphic("badc", "baba") == false);
    assert(areIsomorphic("", "") == true);
    assert(areIsomorphic("a", "a") == true);
    assert(areIsomorphic("a", "b") == true);
    assert(areIsomorphic("a", "aa") == false);
    assert(areIsomorphic("xyz", "abc") == true);
    assert(areIsomorphic("xyz", "xyy") == false);
    std::cout << "Все тесты пройдены успешно." << std::endl;
}


// главная функция
int main() {
    testAreIsomorphic();


    // тест датасета
    std::string filePath = "C:/Users/gelkk/Documents/GitHub/polygon1/dataset.txt";
    bool result = checkIsomorphismFromFile(filePath);
    std::cout << (result ? "true" : "false") << std::endl;
    
    // считаем память
    std::cout << "Размер char: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Размер size_t: " << sizeof(size_t) << " байт" << std::endl;
    std::cout << "Размер string: " << sizeof(std::string) << " байт" << std::endl;
    std::cout << "Размер unordered_map: " << sizeof(std::unordered_map<char, char>) << " байт" << std::endl;
    std::cout << "Общий размер: " << sizeof(char) + sizeof(size_t) + sizeof(std::string) + sizeof(std::unordered_map<char, char>) << " байт" << std::endl;

    return 0;
}