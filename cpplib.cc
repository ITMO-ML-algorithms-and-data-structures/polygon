#include "cpplib.h"
#include <vector>
#include <map>

#include "limits"
bool CPPLib::is_isomorph(std::string input1, std::string input2) {
    std::map <char, char> symbols; //создаем map для хранения ключ-значение всех символов
    if (input1.length() != input2.length()) {
        return false; //если длины не равны то строки не могут быть изоморфны, поэтому возвращаем false
    } 
    else {
        for (int i = 0; i < input1.length(); i++) {
            if (symbols.count(input1[i]) == 0) { 
                symbols[input1[i]] = input2[i]; //если символ не был найден в словаре, то заносим его и сопоставляем значение из второй строки
            }
            else { //если значение уже есть в словаре, то проверяем соотвествует ли символу тот же символ, что был раньше
                if (symbols[input1[i]] == input2[i]) {
                    continue;
                }
                else { 
                    return false; //если не соответствует возвр false
                }
            }
        }
        }
        return true; //если ни разу не вернул false и цикл дошел до конца, то возвр true
    }
