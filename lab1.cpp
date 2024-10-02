//задача
//Реализовать функцию, которая определяет, являются ли две строки изоморфными
//"Вот пример изоморфных строк:
//«egg» и «add» — символы «e» и «a» соответствуют друг другу, а «g» соответствует «d».
//Неизоморфные строки:
//«foo» и «bar» — здесь символ «f» соответствует «b», «o» — «a», но «o» встречается дважды,
//что не может соответствовать единственному «r» в другой строке."
#include <iostream>
#include <map>
#include <string>
using namespace std;
bool areIsomorphic(string strglobal)//2n * 1байт
{
    int len = strglobal.size();
    if(len % 2 == 1) {
        return false;
    }
    int lenstr = len / 2;
    map<char, char> ch2;
    map<char, char> ch;//(sizeof(A) + sizeof(B) + sizeof(_Rb_tree_node_base)) * N + sizeof(_Rb_tree)
    for(int i = 0; i < len/2;i++){//проходим каждый элемент в str1,2
        if(ch.count(strglobal[i]) == 0){     //создаём связь str1[i] c str2[i]
            ch[strglobal[i]] = strglobal[i + lenstr];
        }
        if(ch[strglobal[i]] != strglobal[i + lenstr]){        //проверяем связь если она создана
            return false;
        }
        if(ch2.count(strglobal[i + lenstr]) == 0){     //создаём связь str2[i] c str1[i]
            ch2[strglobal[i + lenstr]] = strglobal[i];
        }
        if(ch2[strglobal[i + lenstr]] != strglobal[i]){        //проверяем связь если она создана
            return false;
        }
    }
    return true;
}