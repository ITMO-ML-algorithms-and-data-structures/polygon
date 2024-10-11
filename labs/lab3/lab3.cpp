#include <iostream>
#include <fstream>

/*** Функция, которая принимает строку и возвращает false, если все скобки закрыты, и true, если есть открытые скобки (также может выводить ошибку) ***/
bool brackets_check(std::string& input_str) {
    // Задаём два счётчика, через которые будем подсчитывать открывающие и закрывающие скобки
    int open_counter = 0, closed_counter = 0; // O(1) + O(1) - выделяем память и присваиваем значения
    
    // Проходимся по каждому символу строки
    for (int i = 0; i < input_str.length(); i++) { // O(1) + O(1) + O(1) + O(1) + O(1) - выделяем память, задаём значение, получаем доступ к длине строки, сравниваем, производим операцию инкремента
        
        // цикл: O(N) в худшем случае, O(1) в лучшем случае (если уже на первом символе словится ошибка)
        // цикл: O(K) в среднем случае, тк ошибка и завершение цикла может произойти при 1 < K < N

        char symbol = input_str[i]; // O(1) + O(1) + O(1) - получаем доступ к символу по индексу, выделяем память и задаём значение

        // Если встретилась открывающая скобка, увеличиваем open_counter; если встретилась закрывающая, увеличиваем closed_counter
        // O(1) + O(1) - производим сравнение, производим операцию инкремента
        if (symbol == '(') {
            open_counter++;
        } else if (symbol == ')') {
            closed_counter++;
        }

        // Если на каком-то символе оказалось, что у нас есть закрывающая скобка без открывающей (колво закрывающих оказалось больше чем колво открывающих), то выводим ошибку и завершаем работу программы
        if (closed_counter > open_counter) { // O(1) - производим сравнение
            // O(1) + O(1) - вывод ошибки и завершение программы
            std::cout << "Error: there are closed bracket without open bracket!" << std::endl;
            exit(0);
        }
    }

    // Если значения равны, это означает, что все скобки закрыты, и в этом случае возвращаем false
    // Если значения не равны, то это означает, что открывающих скобок у нас больше (меньше их быть не может, тк тогда бы ранее вывелась ошибка), и в этом случае возвращаем true
    return open_counter != closed_counter; // O(1) + O(1) - производим сравнение, делаем return
}

// Итог по сложности алгоритма:
// O(N) - худший случай
// O(1) - лучший случай
// O(K) - средний случай, где 1 < K < N


/*** Функция для тестов ***/
void test_brackets(std::string test_string, bool predicted_res) {
    if (brackets_check(test_string) == predicted_res) {
        std::cout << "Test is passed" << std::endl;
    } else {
        std::cout << "Test is failed." << std::endl;
    }
}


int main() {
    
    // Ввод строки с клавиатуры
    std::string string_from_keyboard;
    std::cout << "Input your string: ";
    std::cin >> string_from_keyboard;

    // Проверяем эту строку, в зависимости от результата выводим на экран TRUE или же FALSE
    bool result = brackets_check(string_from_keyboard);
    if (result == true) {
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "FALSE" << std::endl;
    }

    // Обычные тесты
    test_brackets("a*(b*c())", false);
    test_brackets("(1(2(3(4(5(+(7(8(9(10 )1)2)3)4)5)6)7)8)9", true);
    test_brackets("", false); // если пусто, то и открытых скобок нет - значит false
    test_brackets("()()() linear algebra in my heart ()()()", false);
    test_brackets(":( :( :( :( :(", true);
    test_brackets("52 * (52 + 52)**(52 - 52) ++-- (5252", true);
    test_brackets("()_(((()))_)", false);
    
    // Тест с чтением строки из файла: в строке макс число символов (1e4 для данного задания), 600 открытых скобок, 400 закрытых
    std::ifstream input_file("lab3 dataset.txt");
    std::string input_str;

    std::getline(input_file, input_str);
    test_brackets(input_str, true);

    // Тест, выводящий сообщение об ошибке
    test_brackets(":) :) :) :) :)", false); // в этом тесте будет выведено сообщение об ошибке
    
    return 0;
}