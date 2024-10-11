#include <iostream>
#include <unordered_map>

/*** Функция, которая принимает две строки и проверяет, что каждому символу первой строки соответствует ровно один символ второй строки ***/

bool check_strings(std::string first_str, std::string second_str) { // +32 + 32 байт
    // Создаём хэш-таблицу, где ключ - это символ, и значение - тоже символ
    std::unordered_map<char, char> table_with_letters; // +56 байт

    // Перебираем символы первой строки по индексу
    for (int i = 0; i < first_str.length(); i++) { // +4 байт
        char key = first_str[i]; // +1 байт

        // Проверяем, соответствует ли уже что-то букве из первой строки, и если оказывается, что ей должны соответствовать уже две буквы, то возвращаем false
        if (table_with_letters.count(key) == 1) {
            if (table_with_letters[key] != second_str[i]) {
                return false;
            }
        // Если же для какой-то буквы ещё не было найдено соответствий ранее, задаём для неё букву-пару из второй строки
        } else {
            table_with_letters[key] = second_str[i]; // вроде бы после выполнения 56 байт и остаётся…
        }
    }
    // Если мы перебрали все буквы первой строки, и каждой из них соответствует одна буква из второй, то всё ок и возвращаем true
    return true;
}


/*** Функция для тестов ***/

std::string compare_results(bool predicted_res, std::string first_str, std::string second_str) { // +1 +32 +32 байт
    // Проверяем длину
    if (first_str.length() != second_str.length()) {
        return "The length of strings shouldn't be different!";
    } else {
        // Теперь загоняем строки в функцию и проверяем их. Функция вызывается дважды, тк не только каждой букве первой строки должна соответствовать одна из второй, но и каждой букве второй строки должна соотвествовать одна из первой
        bool result = false; // +1 байт
        if ((check_strings(first_str, second_str) == true) && (check_strings(second_str, first_str) == true)) {
            result = true;
        }

        // Если результат совпал с ожидаемым результатом, то тест пройден
        if (predicted_res == result) {
            return "Test is passed.";
        }
        return "Test if failed.";
    }
}


int main() {
    // Ввод строк с клавиатуры
    std::string string1, string2;

    std::cout << "Enter first string: ";
    std::cin >> string1; // +32 байт
    std::cout << "Enter second string: ";
    std::cin >> string2; // +32 байт

    if ((check_strings(string1, string2) == true) && (check_strings(string2, string1) == true)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    // Тесты
    std::cout << compare_results(false, "swass", "swarr") << std::endl;
    std::cout << compare_results(true, "goooll", "tyyyww") << std::endl;
    std::cout << compare_results(true, "watermelon", "waterlemon") << std::endl;
    std::cout << compare_results(false, "porridge", "powvidge") << std::endl;
    std::cout << compare_results(false, "porridge", "porrrdge") << std::endl;
    std::cout << compare_results(true, "isomorph", "izanarpk") << std::endl;
}
// Итог по памяти: 32 + 32 + 56 + 4 + 1 + 1 + 32 + 32 + 1 + 32 + 32 == 255 байт. Посчитано в основном с помощью sizeof, сверялся с gpt и презентацией с лекции.
// Про тесты: учитывая тематику задачи, не уверен, что генерацией входных данных удастся получить что-то дельное. Вы, помнится, говорили на практике, что можно прописать результат для некоторых данных и его сравнение с ожидаемым результатом (если я вас правильно тогда понял). По размеру входных строк: я брал задачу с самым маленьким ограничением, так что ну при длине в 1е4 символов всё тоже работает.