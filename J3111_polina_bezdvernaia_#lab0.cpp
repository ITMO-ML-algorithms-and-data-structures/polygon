#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
// задача: найти последовательность максимальной длины из идущих подряд одинаковых чисел
// ввод: длина массива и сам массив
// вывод: ответ на задачу
// в коде представлены 2 варианта решения задачи: один выводит ответ за большее время, но не требует значительных объёмов памяти; второй требует меньше времени, но гораздо больше памяти.

int main() {
    int num_of_val;
    std::cin >> num_of_val;
    std::vector<int> a;
    a.reserve(num_of_val);
    
    for (int i = 0; i < num_of_val; i++) {
        int inp;
        std::cin >> inp;
        a.push_back(inp);
    }

    // вариант 1. Работает дольше, но почти не затрачивает память
    int b = 1;
    int c = 0;

    for (int i = 1; i < num_of_val; i++) {
        if (a[i - 1] == a[i]) {
            b += 1;
        }
        else {
            c = std::max(c, b);
            b = 1;
        }
    }
    c = std::max(c, b);
    std::cout << c << std:: endl;

    // вариант 2. Работает быстрее, но требует много памяти
    std::vector<int> b1;
    b1.reserve(num_of_val);
    for (int i = 0; i < num_of_val; i++) {
        b1.push_back(1);
    }
    
    for (int i = 1; i < num_of_val; ++i) {
        if (a[i - 1] == a[i]) {
            b1[i] += b1[i - 1];
        }
    }
    int max_b1 = *std::max_element(b1.begin(), b1.end());
    std::cout << max_b1 << std::endl;
    return 0;
}
