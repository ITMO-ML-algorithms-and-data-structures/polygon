#include <iostream>
#include <vector>
#include <cassert>

int findCombinations(const std::vector<double>& input) {
    std::vector<std::vector<int>> result;
    for (int x1 = 0; x1 < input.size(); x1++) {
        for (int x2 = x1 + 1; x2 < input.size(); x2++) {
            for (int x3 = x2 + 1; x3 < input.size(); x3++) {
                for (int x4 = x3 + 1; x4 < input.size(); x4++) {
                    for (int x5 = x4 + 1; x5 < input.size(); x5++) {
                        for (int x6 = x5 + 1; x6 < input.size(); x6++) {
                            // Проверяем, равна ли сумма 6 выбранных элементов нулю
                           if (input[x1] + input[x2] + input[x3] + input[x4] + input[x5] + input[x6] == 0){
                                std::cout << "[" << x1 << "," << x2 << "," << x3 << "," << x4 << "," << x5 << "," << x6 << "]" << " ";
                                // Если сумма равна нулю, сохраняем индексы
                                result.push_back({x1, x2, x3, x4, x5, x6});
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    return result.size(); // Возвращаем количество найденных комбинаций
}

void testFindCombinations() {
    // Тест 1: Ожидается несколько комбинаций
    assert(findCombinations({1, -1, 1, -1, 1, -1, 1}) > 1);

    // Тест 2: Нет комбинаций
    assert(findCombinations({1, 2, 3, 4, 5, 6}) == 0);

    // Тест 3: Все элементы равны нулю
    assert(findCombinations({0, 0, 0, 0, 0, 0}) == 1);

    // Тест 4: Проверка на работу с дробными значениями
    assert(findCombinations({1, 5, -1, 5, 2.6, -2.6, 5.1, -5.1, -5, 1}) > 0);
}

int main() {
    testFindCombinations();
    std::cout << std::endl << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
