#include <stdio.h>
#include <string.h>
// ��������� ������� ��������
int counter(const char *brackets) {
    int total, l_b; // счетчики l_b - считает левые скобки
    l_b = 0;
    total = 0; // Итоговое число пар
    for (int i=0; i<sizeof(brackets); i++) {
        if (brackets[i] == '(')
            l_b++;
        else if (brackets[i] == ')' && l_b > 0) {
            total++;
            l_b -= 1;
        }
    }
     return total;
}

int main() {

    char brackets[6] = "()()))"; // тестовая строка

    printf("%d",counter(brackets));
    return 0;

}

