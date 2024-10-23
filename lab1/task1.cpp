#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
bool isomorphString(const string& string1,const string& string2){
    if (string1.size() != string2.size()) // O(1)
        return 0;
    const unsigned short& stringSize = string1.size(); // O(1) (макс. длина 1e4 * 2 ~= 2 байт)
    unordered_map <char, char> mapMatch; // O(1) Хэш-таблица соотв элементов первой строки и второй строки
    unordered_set <char> setExist; // O(1) Множество элементов, которые уже в хэш-табл
    for (unsigned short i = 0; i < stringSize; ++i){ // O(n)
        const char& symbstring1 = string1[i], symbstring2 = string2[i]; // O(1)
        if (setExist.find(symbstring1) == setExist.find(symbstring2) && setExist.find(symbstring1) == setExist.end()){ // O(1) Проверка - оба элемента нет в setExist
            setExist.insert(symbstring1); // O(1) 
            setExist.insert(symbstring2); // O(1)
            mapMatch[symbstring1] = symbstring2; // O(1)
        }
        else if (setExist.find(symbstring1) != setExist.end()){ // O(1)
            if (mapMatch[symbstring1] != symbstring2) // O(1) Проверка - совп ли элементы в mapMatch
                return 0;
        }
    }
    return 1;
}

int main(){
    // system("python3 generate_dataset.py --mode text --max-length 10000 --num-rows 2 --min-unique 2 --charset alphanumeric --output-file task1.txt --delimiter '\n'")
    string inputstring1, inputstring2;
    ifstream in("test.txt"); // Вход две строки из файла test.txt
    in >> inputstring1 >> inputstring2;
    if (isomorphString(inputstring1, inputstring2)) // O(n)
    // Вывод true/false
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 1;
}