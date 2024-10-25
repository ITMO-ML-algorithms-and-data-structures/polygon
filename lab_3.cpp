#include <iostream>
#include <string>
#include <fstream>


std::string minimazer(const std::string& str){
    if (str.size() == 0){ // O(1)
        return str;
    }

    std::string outputStr; // O(1)

    /* Зарезервируем в памяти место для нашей результирующей 
     строки, чтобы избежать перераспределения памяти. */

    outputStr.reserve(2 * str.size()); // O(1) - копировния не происходит

    // Берём short int, тк в строке максимум 1е4 символов. 
    
    short int counter = 1; // O(1)

    char leftPtr = str[0]; // O(1)
    for (size_t i = 1; i <= str.size(); ++i){ // O(n), где n - длина строки
        if (leftPtr == str[i]){ // O(1)
            ++counter;
        } else {
            /* Добавляем в результирующую строку пару 
            символ и его количество */
            
            outputStr += leftPtr; // O(k), k - текущаю длина резул. строки

            /* Добавление происходит со сложностью от 1 до n, в худшем случае,
             когда количество уникальных значений равно длине строки, а 
             в среднем случае незначительно => O(1) */ 
            
            outputStr += std::to_string(counter); // O(1)

            leftPtr = str[i]; // O(1)
            counter = 1; // O(1)
        }
    }

    return outputStr;
}

std::string read_str_from_file(const std::string& path){
    std::string outputStr; // O(1)

    std::ifstream file(path); // O(n), n - кол-во байт в файле
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file");
    }

    getline(file, outputStr); // O(n), n - длина строки в файле

    return outputStr;
}

void test(const std::string& str, const std::string& expectedAns){
    if (str == expectedAns){ // O(n), n - длина короткой строки
        std::cout << "Everything is OK" << "\n";
    } else {
        std::cout << "Wrong answer!" << "\n";
    }
}


int main(){
    // Тест из файлика
    std::string inputString = read_str_from_file("C:/Users/memel/Desktop/C++/Algorithms/Lab_3/testsInt.txt");
    std::string expectedAns = "a2b2c2"; // O(n)
    inputString = minimazer(inputString);

    test(inputString, expectedAns);

    // "Датасет" для 1 теста
    std::string inputStr1 = "aaabbccc"; // O(n), n - длина строки
    std::string expectedAns1 = "a3b2c3"; // O(n)
    inputStr1 = minimazer(inputStr1);

    test(inputStr1, expectedAns1);

    // "Датасет" для 2 теста
    std::string inputStr2 = "bbbbbbbbrrrraoooooooppppppllbbaccnnnmmmmmm"; // O(n)
    std::string expectedAns2 = "b8r4a1o7p6l2b2a1c2n3m6"; // O(n)
    inputStr2 = minimazer(inputStr2);

    test(inputStr2, expectedAns2);

    // Итоговая сложность - O(n)

    return 0;
}
