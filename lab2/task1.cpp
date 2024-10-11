#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;
bool isomorphString(const string& string1,const string& string2){
    if (string1.size() != string2.size()) // O(1)
        return 0;
    const unsigned short& stringSize = string1.size(); // O(1) (макс. длина 1e4 * 2 ~= 2 байт)
    unordered_map <char, char> mapMatch; // O(1) Хэш-таблица соотв элементов первой строки и второй строки
    for (unsigned short i = 0; i < stringSize; ++i){ // O(n)
        const char& symbstring1 = string1[i], symbstring2 = string2[i]; // O(1)
        bool symb1find = mapMatch.find(symbstring1) == mapMatch.end(); // O(1)
        bool symb2find = mapMatch.find(symbstring2) == mapMatch.end(); // O(1)
        if (symb1find && symb2find){
            mapMatch[symbstring1] = symbstring2; // O(1)
            mapMatch[symbstring2] = symbstring1; // O(1)
        }
        else if (!symb1find && !symb2find){ // O(1)
            if (mapMatch[symbstring1] != symbstring2) // O(1)
                return false;
        }
        else 
            return false;
    }
    return true;

}
void test(bool ans){
    if (ans)
        cout << "OK\n";
    else
        cout << "NOT OK\n";
}

int main(){
    // system("python3 generate_dataset.py --mode text --max-length 10000 --num-rows 2 --min-unique 2 --charset alphanumeric --output-file test.txt --delimiter '\n'")
    int n;
    string inputstring1, inputstring2, ans;
    ifstream in("test.txt"); // Вход две строки из файла test.txt
    in >> n;
    for (int i = 0; i < n; ++i){
        in >> inputstring1 >> inputstring2 >> ans;
        bool func_ans = isomorphString(inputstring1, inputstring2);
        bool right_ans = ans == "true";
        test(func_ans == right_ans);
    }
    return 1;
}