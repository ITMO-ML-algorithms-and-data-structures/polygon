#include <iostream>
using namespace std;

//Найти количество пар скобок (открытая и закрытая), корректно расположенных в строке
string str = "";
bool open_bracket = false;
int answer = 0;

int main()
{
   cin >> str;
   for(int i; i < str.length(); i++){
       if (open_bracket == false and str[i]==('('))
           open_bracket = true;
       if (open_bracket == true and str[i]==(')')){
           answer++;
           open_bracket = false;
       }
   }
   return answer;
}