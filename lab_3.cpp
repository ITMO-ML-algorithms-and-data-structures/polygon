#include <iostream>
#include <string>
using namespace std;


bool def (const string& s) {  // O(1)
    // cоздаем стек для скобок
    stack<char> stack;  // O(1), память в худшем случае O(N) байт если все скобки ( | заметка для себя: сделать дома через очередь
    // бежим по строке
    for (int i = 0; i < s.length(); i++) {  //слож. O(n), память 4 байта для указателя
        // скобку ( добавляем в стек
        if (s[i] == '(') {  // слож. O(1) + O(1)
            stack.push(s[i]);  // сложн. O(1) + O(1)
        }
        // если скобка ) отрабатываем случаи
        else if (s[i] == ')') {  // сложн. O(1) + O(1)
            // если ) ничего не закрывает то это ошибка
            if (stack.empty()) {  // сложн.O(1)
                try {  // сложн. O(1)
                    throw std::runtime_error("Скобка без открытой");  // сложн. O(1)
                } catch (const exception& error) {  // сложн. O(1)
                    std::cout << "Ошибка: " << error.what() << endl;  // сложн. O(1)
                    return false;  // сложн. O(1)
                }
            }
            // иначе скобка ( закрывается ) и мы удаляем ее из стека
            stack.pop(); // сложн. O(1)
        }
    }
    // если все ( закрыты ), то фалз
    if (stack.empty()) { // сложн. O(1)
        return false;  // сложн. O(1)
    }
    // иначе все гуд
    return true; // O(1)
}


// итоговая сложность 18 * O(1) + O(N) = O(N), итоговая память O(4) + O(N) = O(N) в худшем случае
int test_passed = 0;
int test_failed = 0;


void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std:: cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}


int main () {
    // тест 1
    string s = "()()()()((((((("; // O(1)
    assertEqual(def(s) == true, " test 1");

    // тест 2
    s = "()()()()()";
    assertEqual(!def(s), " test 2");

    // тест 3
    s = "";
    assertEqual(!def(s), " test 3");

    // тест 4
    s = std::string(pow(1, 1), *"(");
    assertEqual(def(s), " test 4");

    // тест 5
    s = "(()))(";
    assertEqual(!def(s) , " test 5");

    // тест 6
    s = std::string(pow(10, 4), *"(") + std::string(pow(10, 4),*")");;
    assertEqual(!def(s), " test 6");
    cout << test_passed << "/" << test_failed << "\n";
    return 0;
}