#include <iostream>
using namespace std;

//Найти количество пар скобок (открытая и закрытая), корректно расположенных в строке
string str = "";
int answer = 0, open_bracket = 0, close_bracket = 0;

int main()
{
    cin >> str;
    for(int i; i < str.length(); i++){
        if (str[i] == '(' && close_bracket == 0)
            open_bracket += 1;
        else if(str[i] == '(' && close_bracket > 0){
            open_bracket = 1;
            close_bracket = 0;
        }
       
        if(str[i] == ')' && open_bracket == 0)
            close_bracket += 1;
        else if(str[i] == ')' && open_bracket > 0){
            answer += 1;
            open_bracket -= 1;
        }
    }
    cout << answer;
}