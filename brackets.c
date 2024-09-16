#include <stdio.h>
#include <string.h>
// задача: посчитать пары скобочек 
int counter(const char *brackets) {
    int total, l_b; // счетчики l_b - считает левые скобки
    l_b = 0;
    total = 0; // Итоговое число пар
    for (int i=0; i<sizeof(brackets); i++) {
        if (bracket == '(')
            l_b++;
        else if (bracket == ')' && l_b > 0) {
            total++;
            l_b -= 1;
        }
    }
     return total;
}

int main() {

    char[6] brackets = "()()))"; // тестовая строка

    printf("%d", counter(brackets));
    return 0;

}

