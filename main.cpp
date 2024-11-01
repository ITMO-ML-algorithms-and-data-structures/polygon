// Задача: сжать строку, заменяя последовательности одинаковых символов их количеством и символом
// Алгоритм сжимает строку до длины меньше либо равной изначальной (равенство достигается, когда элементы различны или равны в парах)
#include<string>
#include<iostream>
using namespace std;

string press_str(string str) {
    string new_str = ""; // строка для ответа
    string one_symbols = "";
    int count = 1; // счетчик для подряд идущих букв (1 так как взяв букву для сравнения с другими нужно ее посчитать)
    if (str == "") { // проверка для пустой строки
        return "";
    }
    for(int i = 0; i < str.length()-1; i++) { // проходим по строке
        if(str[i] == str[i+1]) { // если следующая буква совпадает с данной, то просто увеличиваем счетчик
            count++;
        } else {
            if (count == 1) {
                one_symbols += str[i]; // если символ одиночный, то добавляем его в строку одиночных
            } else {
                new_str += one_symbols + str[i] + to_string(count); // если следующая буква отличается, то записываем в итоговую строку набор одинаковых символов, последнюю повторяющуюся букву и ее кол-во повторений
                one_symbols = ""; // сбрасываем набор одиночных символов
                count = 1; // не забываем сбросить счетчик для новой буквы
            }
        }
    }
    // повторим действие из цикла для последнего элемента
    if (count == 1) {
        new_str += one_symbols + str[str.size()-1];
    } else {
        new_str += one_symbols + str[str.size()-1] + to_string(count); // так как для последнего ряда букв нет изменений после него, то надо отдельно его внести в ответ
    }
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
    assertEqual(press_str("a"),"a"," Одна буква");
    assertEqual(press_str("ab"),"ab"," ab > ab");
    assertEqual(press_str("aabba"),"a2b2a"," aabba > a2b2a");
    assertEqual(press_str("ac c"),"ac c"," Строка с пробелом");
    assertEqual(press_str("111332"),"13322"," Строка с цифрами");
    assertEqual(press_str("abba"),"ab2a"," abba > ab2a");
    report();
    return 0;
}