#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

//тк сказано что длина строчки<10000, то string, который вмещает в себя 2147483647 символов подойдет с запасом
bool AreIsomorphic(const string &str1, const string &str2){ 
    if (str1.size() != str2.size()) return false; // Разная длина = не изоморфны
    
    unordered_map<char, char> mapping; //для хранения сопоставления символов из первой строки с символами второй строки
    unordered_map<char, bool> mapped; // для хранения проверенных символов
    
    for (int i = 0; i < str1.size(); i++) {
        char l1 = str1[i], l2 = str2[i]; // l - letter 
        if (mapping.find(l1) != mapping.end()) {    // сопоставление есть 
            if (mapping[l1] != l2) return false; //не совпало с базой

        } else {                                    // сопоставления нет 
            if (mapped[l2]) return false; //если проверенно 
            mapping[l1] = l2;             //если не проверенно 
            mapped[l2] = true;
        }
    }

    return true;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
	
    if (AreIsomorphic(str1, str2)) cout << "isomorphic";
    else cout << "not isomorphic";

    return 0;
}
