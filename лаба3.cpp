#include <iostream>
#include <string>
#include <cassert>

//Сжать строку, заменяя последовательности одинаковых символов их количеством и символом

std:: string ShortStr(std:: string str){
    std:: string NewStr; // выделение памяти O(1)
    short int count = 0; // выделение памяти и присваивание O(1) + O(1)
    char x = str[0]; // выделение памяти, взятие элемента по индексу и присваивание O(1) + O(1) + O(1)
    if (str.length() > 10000) { // сравнение, str.length O(1) + O(1)
        std::cout << "the string size must not exceed 10, 000 characters."  << std::endl; // вывод O(1)
        NewStr = "Run the program again but within the correct range."; // присваивание O(1)
    }else{for (char i : str) { // выделение памяти O(1) + перебор каждого элемента строки O(N), где N - длина строки 
        if (i == x) { // сравнение O(1)
            count += 1; // O(1)
        }else {
            NewStr += x + std::to_string(count); // O(1) - добавление символа + O(k) - добавление количества,
                                                //где k - количество цифр в числе
            x = i; // присваивание 
            count = 1; // присваивание 
        
        }
    }
    NewStr += x + std::to_string(count); // O(1) - добавление символа + O(M) - добавление количества,
                                        //где M - количество цифр в последнем числе
    }
    return NewStr;
    // сложность алгоритма составляет O(N)
}

void testShortStr() {              // функция для теста 

    std::string TestStr1 = "";
    std::string result1=  ShortStr(TestStr1);
    assert((result1 == 0));
    std::cout << result1 << std::endl;

    std::string TestStr2 = "abbccc";
    std::string result2=ShortStr(TestStr2);
    assert((result2== "a1b2c3"));
    std::cout << result2 << std::endl;

    std::string TestStr3 = "200000002";
    std::string result3= ShortStr(TestStr3);
    assert((result3 == "210721"));
    std::cout << result3 << std::endl;

    std::cout << "All tests done!" << std::endl;
}

    int main(){
    testShortStr();
    }
