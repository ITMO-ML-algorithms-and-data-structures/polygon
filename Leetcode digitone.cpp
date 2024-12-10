// #include <iostream>
// using namespace std;

class Solution { // такой класс потому что просит leetcode
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;

        long count = 0;
        long factor = 1;

        while (n / factor > 0) {
            long lower = n % factor; // Остаток справа от текущей позиции
            long current = (n / factor) % 10; // Текущая цифра
            long higher = n / (factor * 10); // Часть числа слева

            if (current == 0) {
                count += higher * factor; // Только старшие цифры
            } else if (current == 1) {
                count += higher * factor + lower + 1; // Учитываем и текущие младшие
            } else {
                count += (higher + 1) * factor; // Полный диапазон
            }

            factor *= 10; // Переходим к следующей позиции
        }

        return count;
    }
};

// int main() {
//     Solution s; //объект класса Solution
//     int count = s.countDigitOne(1000000);
//     std::cout<<count;
//     return 0;
// }
