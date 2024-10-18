#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool isIsomorf(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    map<char, char> map = {};
    vector<char> v = {};
    for (int i = 0; i < str1.size(); i++) {
        if (map.find(str1[i]) != map.end() ) {
            if (map[str1[i]] != str2[i]) {
                return false;
            }
        } else {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == str2[i]) {
                    return false;
                }
            }
            v.push_back(str2[i]);
            map[str1[i]] = str2[i];
        }
    }
    return true;
} // Эта программа эффективнее по времени O(N), следующая эффективнее по памяти, ее и будем использовать

bool isIzomorf(string str1, string str2) {
    if (str1.size() != str2.size()) { // Если длины строк не равны, то не изоморфны
        return false;
    }
    for (int i = 0; i < str1.size() -1; i++) { // Проходим по строке1 запоминая соответствие между буквами 1 и 2 строк
        char let1 = str1[i]; // Память: 1 байт
        char let2 = str2[i]; // Память: 1 байт
        for (int j = i; j < str2.size(); j++) { // Для соответствия из предыдущего проходим по всей строке
            if ((str1[j] == let1 && str2[j] != let2) || (str2[j] == let2 && str1[j] != let1)) { // Проверяем соответствие букв
                return false;
            }
        }
    }
    return true; // Если все предыдущие проверки прошли, то строки изоморфны
}

int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition,bool need, const std::string& testName) {
    if (condition == need) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nИтого тестов пройдено: " << test_passed << "\n";
    std::cout << "\nИтого тестов не пройдено: " << test_failed << "\n";
}


int main() {
    assertEqual(isIsomorf("",""),true,"Пустые строки");
    assertEqual(isIsomorf("a","b"),true,"Один символ");
    assertEqual(isIsomorf("all","c++"),true,"Изоморфные строки");
    assertEqual(isIsomorf("lol","low"),false,"Не изоморфные строки");
    assertEqual(isIsomorf("true","false"),false,"Разная длина строк");
    report();
    return 0;
}



