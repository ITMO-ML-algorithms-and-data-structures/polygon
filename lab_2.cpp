#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool Isomorph(string stroka1, string stroka2){
    //Следующие 2 строчки задают хештаблицы для проверки соответсвия букв
    unordered_map<char, char> map1; // память же будет 1байт для ключа, 1байт для элемента, те O(2*U) где U -кол-во уник символов
    unordered_map<char, char> map2; // тут также O(2 * U)
    //если строки разной длины, то сразу неизоморфны
    if (stroka1.length() != stroka2.length()) { // O(1)
        return false;
    }
    // идем циклом, по каждой букве первого слова  проверяем соответствие букв
    for (int i = 0; i < stroka1.length(); i++) {// O(N)
        // проверяем есть ли соответсвие буквам 1го и 2го слова
        if (!map1.contains(stroka1[i]) && !map2.contains(stroka2[i])) { // O(1), 4 байта i
            map1[stroka1[i]] = stroka2[i]; // O(1)
            map2[stroka2[i]] = stroka1[i]; // O(1)
        } // тут проверяем что буква первого слова соответсвует второй, а буква второй соответствует первой
        else if(map1[stroka1[i]] != stroka2[i] || map2[stroka2[i]] != stroka1[i]) { // O(1)
            return false;
        }
    }
    //если все выполнено, то все супер
    return true;
}
int main() {
    //определяем строки
    string stroka1, stroka2; // память O(N + M байт)
    //задаем строки
    cin >> stroka1 >> stroka2;
    //вызываем функцию для проверки выполнения задачи
    if (Isomorph(stroka1, stroka2)) {
        cout << "True" << endl;
    } else {cout << "False" << endl;}

    //тесты, а итог памяти в последней строке
    // if (Isomorph("123", "456") == true) {
    //     cout << "True" << endl; // с цифрами тоже
    // } else {cout << "false" << endl;}
    //
    // if (Isomorph("paper", "title") == true) { // тест просто
    //     cout << "True" << endl;
    // } else {cout << "false" << endl;}
    //
    // if (Isomorph("abcd" + std::string(9996, 'e'), "wxyz" + std::string(9996, 'f')) == true) {
    //     cout << "True" << endl; // тест для длинных строк
    // } else {cout << "false" << endl;}
    //
    // if (Isomorph("paper111", "title000") == true) { //true
    //     cout << "True" << endl;
    // } else {cout << "false" << endl;}
    //
    // if (Isomorph("paper111", "paper111") == true) { //true
    //     cout << "True" << endl;
    // } else {cout << "false" << endl;}
    //
    // if (Isomorph("abccba", "ababab")) { // false
    //     cout << "True" << endl;
    // } else {cout << "false" << endl;}
    // if (Isomorph("apple101", "buuka124") == true) { // false
    //     cout << "True" << endl;
    // } else {cout << "false" << endl;}
}
// в итоге память N + M + 4 + 4 * U
