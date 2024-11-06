#include <iostream>
#include <vector>


void generate_combinations(const std::vector<int>& array, int start, std::vector<int>& current, std::vector<std::vector<int>>& combinations) {
    combinations.push_back(current); // O(1)

    for (int i = start; i < array.size(); ++i) { // O(1) для выделения памяти для i, сравнения и инкремента
        current.push_back(array[i]); // O(1)
        generate_combinations(array, i + 1, current, combinations); // рекурсивный вызов функции, с помощью него мы перебираем все возможные комбинации элементов array, каждый элемент либо входит либо не входит в конкретный набор, получаем сложность O(2^N)
        current.pop_back(); // O(1)
    }
}
// итог по функции generate_combinations: O(2^N)


std::vector<std::vector<int>> get_all_combinations(const std::vector<int>& array) {
    std::vector<std::vector<int>> combinations; // O(1) - инициализация вектора
    std::vector<int> current; // O(1)

    generate_combinations(array, 0, current, combinations); // вызов функции, сложность которой O(2^N), значит получаем O(2^N) и для get_all_combinations
    return combinations; // O(1)
}
// итог по функции get_all_combinations: O(2^N)


std::vector<std::vector<int>> backpack(std::vector<std::vector<int>>& data, int limit) {
    std::vector<int> weigths; // O(1)
    std::vector<int> costs; // O(1)

    // цикл: O(N), проход по всем элементам в data
    for (const auto& item : data) {
        weigths.push_back(item[0]); // O(1) N раз
        costs.push_back(item[1]); // O(1) N раз
    }

    // получаем O(2^N), тк get_all_combinations имеет эту сложность
    std::vector<std::vector<int>> all_var_weigth = get_all_combinations(weigths); // O(2^N)
    std::vector<std::vector<int>> all_var_cost = get_all_combinations(costs); // O(2^N)
    
    int res_cost = -1; // O(1)
    std::vector<int> res_pack; // O(1)
    
    for (int k = 0; k < size(all_var_cost); k++) {
        // проходимся по all_var_cost, поэтому цикл выполняется 2^N раз ==> получаем O(2^N)
        std::vector<int> curr_weight = all_var_weigth[k]; // O(1)
        std::vector<int> curr_cost = all_var_cost[k]; // O(1)

        int weigth_sum = 0; // O(1)
        // цикл: O(K), пробегаемся по текущей комбинации, где К элементов
        for (int sum_elem : curr_weight) {
            weigth_sum += sum_elem; // O(1)
        }
        
        if (weigth_sum <= limit) { // O(1), проверка условия
            int cost_sum = 0; // O(1)

            // цикл: O(К), пробегаемся по текущей комбинации. Если есть хотя бы один предмет с весом меньше чем limit, то получим вложенность циклов ==> O(2^N) * O(К). O(2^N) * O(N) получим не всегда, тк для набора из N элементов может не выполниться if, и общая сложность будет меньше
            for (int cost_elem : curr_cost) {
                cost_sum += cost_elem; // O(1)
            }

            if (cost_sum > res_cost) { // O(1), проверка условия
                res_cost = cost_sum; // O(1)
                res_pack = curr_weight; // O(1)
            }
        }
    }
    // итог по циклу for: O(K * 2^N), где K - от 1 до N

    return {{res_cost}, res_pack}; // O(1)
}
// итог по функции backpack: O(K * 2^N), где K - от 1 до N


void result_output(std::vector<std::vector<int>> res) {
    std::cout << "Items: [ "; // O(1)

    // цикл: O(N), пробегаем по всем значениям из res[1]
    for (int weight : res[1]) {
        std::cout << weight << " "; // O(1) N раз
    }
    std::cout << "]" << std::endl; // O(1)
    std::cout << "Max cost: " << res[0][0] << std::endl; // O(1)
}
// итог по result_output: O(N)


int main() {
    // Тестируем для различных случаев

    // Данные из условия
    std::cout << "Test 1" << std::endl;
    std::vector<std::vector<int>> items1 = {{2, 3}, {3, 4}, {4, 5}};
    int limit1 = 5;
    result_output(backpack(items1, limit1)); // [2 3], 7

    // Другой набор
    std::cout << "Test 2" << std::endl;
    std::vector<std::vector<int>> items2 = {{9, 14}, {1, 4}, {4, 5}};
    int limit2 = 10;
    result_output(backpack(items2, limit2)); // [9 1], 18

    // Набор с нулевыми значениями весов
    std::cout << "Test 3" << std::endl;
    std::vector<std::vector<int>> items3 = {{0, 5}, {0, 7}, {4, 5}, {6, 3}};
    int limit3 = 10;
    result_output(backpack(items3, limit3)); // [0 0 4 6], 20

    // Максимальный limit и максимальное колво предметов
    std::cout << "Test 4" << std::endl;
    std::vector<std::vector<int>> items4 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}};
    int limit4 = 100;
    result_output(backpack(items4, limit4)); // [ 1 2 3 4 5 6 7 8 9 10 11 12 22 ], 113

    // Пустой набор предметов
    std::cout << "Test 5" << std::endl;
    std::vector<std::vector<int>> items5 = {{}};
    int limit5 = 10;
    result_output(backpack(items5, limit5)); // программа ничего не выведет

    return 0;
}