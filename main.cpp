#include <iostream>
#include <vector>

int main() {
    int n, k = 7; // n - размер массива, k - количество вложенных циклов
    long long int p=0,m=0;
    std::cin >> n;
    std::vector<int> begin_list(n);

    // Ввод элементов массива
    for (int i = 0; i < n; i++) {
        std::cin >> begin_list[i];
    }

    // Вложенные циклы для перебора всех комбинаций индексов
    for (int zero = 0; zero < n; zero++) {
        for (int one = 0; one < n; one++) {
            for (int two = 0; two < n; two++) {
                for (int three = 0; three < n; three++) {
                    for (int four = 0; four < n; four++) {
                        for (int five = 0; five < n; five++) {
                            for (int six = 0; six < n; six++) {
                                p++; // Инкрементируем p для каждой итерации

                                // Проверяем, чтобы индексы шли в строго возрастающем порядке
                                if ((six > five) && (five > four) && (four > three) &&
                                    (three > two) && (two > one) && (one > zero)) {
                                    std::vector<int> end_list_1 = { zero, one, two, three, four, five, six };

                                    // Выводим найденные индексы
                                    for (int g = 0; g < 7; g++) {
                                        std::cout << end_list_1[g] << " ";
                                    }
                                    std::cout << std::endl;
                                    m++; // Увеличиваем m, если последовательность индексов возрастающая
                                    }
                            }
                        }
                    }
                }
            }
        }
    }

    // Выводим итоговые значения переменных
    std::cout << p << " " << m << std::endl;

    return 0;
}
