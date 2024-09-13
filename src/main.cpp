#include <iostream>
#include <stack>

using namespace std;

int main() {

    std::string input;
    std::cout << "int pls >";
    std::cin >> input;
    bool isValid = true;

    /**
     * базированная задачка, генштабное решение
     *
     * создаем стек ->
     * добавляем туда открывающие символы
     * если встречаем закрывающий - смотрим, совпадает ли он с последним открытым.
     * совпадает ? (ну тип лежит скобочка `{` а мы встретили `}`) тогда удаляем их и считаем что они закрыты
     * нет ? гг строка инвалид
     */
    std::stack<char> st;
    int size = input.size();
        for (int i = 0; i < size; i++) { // avg foreach enj, компилятор постоянно просит -std=c++11
            char ch = input[i]; 

            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch); // push = добавить сверху
            } else { // да, по синтаксису плюсов/шарпов и че там скобка открывающая тело конструкции должно быть на следующей строке, но мне после джавы+гошки+коклина так больше нравится
                if (st.empty()) {isValid = false; break;} // ну тип получили элемент закрывающий строку, а открывающего в стеке нет

                else {
                    char top = st.top();
                    if ((ch==')' && top=='(') // вот тут смотрим, совпадают ли строчки
                        || (ch=='}' && top=='{')
                        || (ch==']' && top=='[')) {
                            st.pop(); // скобки сошлись, попаем их
                        }
                    else {isValid = false; break;}
                    
                }
            }
    } 

    if (isValid) {
        std::cout << "valid\n"; return 0;
    } else {
        std::cout << "invalid\n"; return -1;
    }
}
