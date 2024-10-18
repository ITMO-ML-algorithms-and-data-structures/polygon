// Задача: сжать строку, заменяя последовательности одинаковых символов их количеством и символом
#include<string>
#include<iostream>
using namespace std;

string press_str(string str) {
    string new_str = ""; // строка для ответа
    int count = 1; // счетчик для подряд идущих букв (1 так как взяв букву для сравнения с другими нужно ее посчитать)
    if (str == "") { // проверка для пустой строки
        return "";
    }
    for(int i = 0; i < str.length()-1; i++) { // проходим по строке
        if(str[i] == str[i+1]) { // если следующая буква совпадает с данной, то просто увеличиваем счетчик
            count++;
        } else {
            new_str += str[i] + to_string(count); // если следующая буква отличается, то записываем в итоговую строку букву и ее кол-во повторений
            count = 1; // не забываем сбросить счетчик для новой буквы
        }
    }
    new_str += str[str.length()-1] + to_string(count); // так как для последнего ряда букв нет изменений после него, то надо отдельно его внести в ответ
    return new_str;
}

// Тесты:
int test_passed = 0;
int test_failed = 0;

void assertEqual(string new_str,string required_str, const std::string& testName) {
    if (new_str == required_str) {
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
    assertEqual(press_str(""),""," Пустая строка");
    assertEqual(press_str("aaabb"),"a3b2"," aaabb > a3b2");
    assertEqual(press_str("a"),"a1"," Одна буква");
    assertEqual(press_str("ab"),"a1b1"," ab > a1b1");
    assertEqual(press_str("aabba"),"a2b2a1"," aabba > a2b2a1");
    assertEqual(press_str("ac c"),"a1c1 1c1"," Строка с пробелом");
    assertEqual(press_str("111332"),"133221"," Строка с цифрами");
    report();
    return 0;
}