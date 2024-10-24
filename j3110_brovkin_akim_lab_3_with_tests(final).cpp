#include <iostream>
#include <string>
using namespace std;

bool isOpen(const string& s) {


    int cnt1 = 0; // Объявление счетчика для '(' (Память: 4 байта для целого числа)
    int cnt2 = 0; // Объявление счетчика для ')' (Память: 4 байта для целого числа)

    // Цикл для перебора каждого символа в строке
    for (int i = 0; i < s.length(); i++) { // s.length() возвращает длину строки (Память: 4 байта для переменной i)
        if (s[i] == '(') { // Проверка, является ли текущий символ открывающей скобкой
            cnt1++; // Увеличение счетчика открывающих скобок (Память: 4 байта для cnt1)
        }
        if (s[i] == ')') { // Проверка, является ли текущий символ закрывающей скобкой
            cnt2++; // Увеличение счетчика закрывающих скобок (Память: 4 байта для cnt2)
        }
    }

    // Сравнение количества открывающих и закрывающих скобок
    if (cnt1 == cnt2) { // (Память: 4 байта для сравнения)
        return false; // Вывод "false", если скобки закрыты
    } else {
        return true; // Вывод "true", если скобки открыты
    }

}

int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nQuantity of passed tests: " << test_passed << "\n";
    std::cout << "\nQuantity of not passed tests: " << test_failed << "\n";
}
int main(){
    assertEqual(isOpen("ab()("), " Test: 0");
    assertEqual(!isOpen("ab()()"), " Test: 1");
    assertEqual(isOpen("(()()"), " Test: 1");
    assertEqual(!isOpen(""), " Test: 2");
    assertEqual(isOpen("((()))(jadncadfa"), " Test: 3");
    report();
    return 0;
}
