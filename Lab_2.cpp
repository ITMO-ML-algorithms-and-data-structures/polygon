#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

//Функция, проверяющая строки на изоморфность 
bool areIsomorphic(const std::string& str1, const std::string& str2) {
    //Проверка длины строк
    if (str1.length() != str2.length()) {
        return false;
    }
    
    //Создание ассоциативных массивов для соответствий
    //map1 хранит соответствия символов из str1 к символам из str2
    //map2 аналогчно map1
    std::unordered_map<char, char> map1; // O(n), где n-кол-во уник. эл-тов + 3*(1+1) байт
    std::unordered_map<char, char> map2; // O(n), где n-кол-во уник. эл-тов + 3*(1+1) байт
    //

    //Итерация по символам
    for (size_t i = 0; i < str1.length(); ++i) {
        char char1 = str1[i]; //Символ из первой строки + 1 байт
        char char2 = str2[i]; //Символ из второй строки + 1 байт

        //Проверка соответствий для первой строки
        if (map1.find(char1) != map1.end()) {
            if (map1[char1] != char2) {
                return false;
            }
        } 
        else {
            map1[char1] = char2;
        }

        //Проверка соответствий для второй строки
        if (map2.find(char2) != map2.end()) {
            if (map2[char2] != char1) {
                return false;
            }
        } 
        else {
            map2[char2] = char1;
        }
    }

    return true;
}

//Объявление функции, предназначенной для загрузки тестовых случаев из файла
std::vector<std::pair<std::string, std::string>> loadTestCases(const std::string &filename) {
    //Объявление переменной, которой будет хранить все загруженные тестовые случаи в виде вектора пар строк
    std::vector<std::pair<std::string, std::string>> testCases;
    //Открытие файла
    std::ifstream file(filename);
    //Объявление переменной, котрая будет хранить каждую строку, считанную из файла
    std::string line;
    
    //Цикл, который построчно считывает файл до конца
    while (std::getline(file, line)) {
        //Поток строк
        std::istringstream ss(line);
        //Объявление строк
        std::string s1, s2;
        
        //Считывание подстрок из потока строк
        if (std::getline(ss, s1, ',') && std::getline(ss, s2)) {
            //Добавление пары строк в вектор
            testCases.emplace_back(s1, s2);
        }
    }
    
    //Функция возвращает, заполненный вектор тестовых случаев
    return testCases;
}

//Объявление функции, которая будет запускать тесты
void runTests() {
    auto testCases = loadTestCases("dataset.csv");
    
    for (const auto &testCase : testCases) {
        const auto &s1 = testCase.first;
        const auto &s2 = testCase.second;
        
        bool result = areIsomorphic(s1, s2);
        std::cout << "areIsomorphic("" << s1 << "", "" << s2 << "") = " << (result ? "true" : "false") << std::endl;
    }
}



//Функция для проверки результата теста и вывода соответствующего сообщения
/*void asert(bool ans){
    if(ans){
        std::cout << "The test is passed";
    }
    else{
        std::cout << "The test is not passed";
    }
}*/

int main() {
    std::string str1 = "egg"; // 3*char + 1(нуль-терминатор) + 4(длина строки) байт
    std::string str2 = "add"; // 3*char + 1(нуль-терминатор) + 4(длина строки) байт

    if (areIsomorphic(str1, str2)) {
        std::cout << "true" << std::endl;
    } 
    else {
        std::cout << "false" << std::endl;
    }

    runTests();

    //Тест
    /*asert(areIsomorphic("egg", "add") == true);
    asert(areIsomorphic("bag", "add") == true);
    asert(areIsomorphic("cool", "add") == true);
    asert(areIsomorphic(" ", " ") == true);*/

//Подсчёт памяти
//На выходе имеем: 2*(O(n) + 3(1+1)) + 1 + 1 + 2*(3+1+4) = 16 + 2 + 16 = 34 байта

    return 0;
}
