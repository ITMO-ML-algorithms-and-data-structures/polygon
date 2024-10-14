#include <iostream>
#include <string>
#include <cassert>

std::string minimazer(const std::string& str){
    std::string outputStr; // 0

    // Зарезервируем в памяти место для нашей результирующей 
    // строки, чтобы избежать перераспределения памяти. 
    // (Пытался найти универсальный метод, который позволил бы 
    // максимально эффективно зарезервировать память, но так и не смог)

    outputStr.reserve(2 * str.size());

    // Берём short int, тк в строке максимум 1е4 символов и
    // short int хватит за глаза. 
    // Инициализируем его как 1, тк первый символ
    // уже составляет подпоследовательность

    short int counter = 1; // O(1)

    char leftPtr = str[0]; // O(1)
    for (size_t i = 1; i <= str.size(); ++i){ // O(n), где n - длина строки
        if (leftPtr == str[i]){
            ++counter;
        } else {
            // Добавляем в результирующую строку пару 
            // символ и его количество
            
            outputStr += leftPtr; // O(k), k - текущаю длина резул. строки

            // Добавление происходит со сложностью от 1 до n, в худшем случае,
            // когда количество уникальных значений равно длине строки, а 
            // в среднем случае это будет проходить куда быстрее, в том числе 
            // и из-ра резервирования памяти, следовательно средняя сложность 
            //O(1)
            
            outputStr += std::to_string(counter); // O(1)
            // O(c) - конвертация counter в число, где с - разряд числа
            // в моем случае c <= 5, тк у меня short int, следовательно O(1)

            leftPtr = str[i]; // O(1)
            counter = 1; // O(1)
        }
    }

    return outputStr;
}


int main(){
    // "Датасет" для 1 теста
    std::string inputStr1 = "aaabbccc"; // O(n), n - длина строки
    std::string expectedAns1 = "a3b2c3"; // O(n)

    // "Датасет" для 2 теста
    std::string inputStr2 = "bbbbbbbbrrrraoooooooppppppllbbaccnnnmmmmmm"; // O(n)
    std::string expectedAns2 = "b8r4a1o7p6l2b2a1c2n3m6"; // O(n)

    assert(expectedAns1 == minimazer(inputStr1));
    assert(expectedAns2 == minimazer(inputStr2));

    // Итоговая сложность - O(n)

    return 0;
}