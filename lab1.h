//задача
//Реализовать функцию, которая определяет, являются ли две строки изоморфными
//"Вот пример изоморфных строк:
//«egg» и «add» — символы «e» и «a» соответствуют друг другу, а «g» соответствует «d».
//Неизоморфные строки:
//«foo» и «bar» — здесь символ «f» соответствует «b», «o» — «a», но «o» встречается дважды,
//что не может соответствовать единственному «r» в другой строке."
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
bool areIsomorphic(string a, string b)//2n * 1байт
{
    if (a.size() != b.size()){
        return false;
    }
    unordered_map<char, char> ch2;
    unordered_map<char, char> ch;//(sizeof(A) + sizeof(B) + sizeof(_Rb_tree_node_base)) * N + sizeof(_Rb_tree)
    for(int i = 0; i < a.size();i++){//проходим каждый элемент в str1,2
        if(ch.count(a[i]) == 0){     //создаём связь str1[i] c str2[i]
            ch[a[i]] = b[i];
        }
        if(ch[a[i]] != b[i]){        //проверяем связь если она создана
            return false;
        }
        if(ch2.count(b[i]) == 0){     //создаём связь str2[i] c str1[i]
            ch2[b[i]] = a[i];
        }
        if(ch2[b[i]] != a[i]){        //проверяем связь если она создана
            return false;
        }
    }
    return true;
}