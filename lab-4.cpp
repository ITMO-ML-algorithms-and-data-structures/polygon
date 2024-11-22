#include <iostream>
#include <vector>
#include <cassert>


std::vector<std::vector<int>> ZeroSum(const std::vector<int>& arr) {
    std::vector<std::vector<int>> result;
    int N = arr.size();

    // Проверяем достаточно ли элементов в массиве
    if (N < 6) return result;

    for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = i1 + 1; i2 < N; i2++) {
            for (int i3 = i2 + 1; i3 < N; i3++) {
                for (int i4 = i3 + 1; i4 < N; i4++) {
                    for (int i5 = i4 + 1; i5 < N; i5++) {
                        for (int i6 = i5 + 1; i6 < N; i6++) {
                            // Проверяем равна ли сумма 6 выбранных элементов нулю
                           if (arr[i1] + arr[i2] + arr[i3] + arr[i4] + arr[i5] + arr[i6] == 0){
                                // Сохраняем индексы
                                result.push_back({i1, i2, i3, i4, i5, i6});
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}


void runTests() {
    // Тест 1: Проверка на пустой массив (меньше 6 элементов)
    {
        std::vector<int> arr = {1, -1, 2};
        auto result = ZeroSum(arr);
        assert(result.empty());
    }

    // Тест 2: Проверка на массив с комбинацией, сумма которой равна 0
    {
        std::vector<int> arr = {1, -1, 2, -2, 3, -3};
        auto result = ZeroSum(arr);
        assert(result.size() == 1);
        assert(result[0] == std::vector<int>({0, 1, 2, 3, 4, 5}));
    }

    // Тест 3: Проверка на массив без комбинаций с нулевой суммой
    {
        std::vector<int> arr = {1, 2, 3, 4, 5, 6};
        auto result = ZeroSum(arr);
        assert(result.empty());
    }

    // Тест 4: Проверка на массив с количеством элементов больше 6, но без комбинаций
    {
        std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
        auto result = ZeroSum(arr);
        assert(result.empty());
    }

    std::cout << "Все тесты прошли успешно!" << std::endl;
}


int main() {
    runTests();
}