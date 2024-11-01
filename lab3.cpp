#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> count_and_replace(const std::vector<int>& arr) {
    std::unordered_map<int, int> count_map;  //Словарь для подсчета вхождений

    for (int value : arr) { //Подсчитываем количество вхождений каждого значения
        count_map[value]++;  //Увеличиваем счетчик для значения
    }
    // В этом цикле мы проходим по каждому элементу массива.
    // Сложность этого цикла: O(N), где N — количество элементов в массиве.

    std::vector<int> result;  //Вектор для хранения результатов
    //Заменяем каждое значение на его количество вхождений
    for (int value : arr) {
        result.push_back(count_map[value]);  //Получаем количество вхождений
    }
    // Сложность этого цикла также: O(N).


    return result;  //Возвращаем новый вектор
}

int main() {
    std::vector<int> input_array = {1, 2, 2, 3, 3, 3};
    std::vector<int> output_array = count_and_replace(input_array);

    for (int count : output_array) {
        std::cout << count << " ";  //Вывод: 1 2 2 3 3 3
    }

    return 0;
}
