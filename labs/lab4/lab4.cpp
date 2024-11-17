#include <iostream>
#include <vector>

/*** Функция, генерирующая все возможные комбинации элементов массива ***/
void generate_combinations(const std::vector<int>& array, int start, std::vector<int>& current, std::vector<std::vector<int>>& combinations) { // +24 + 24 + 24 байт на векторы, +4 байт для int
    // добавляем текущую комбинацию в набор
    combinations.push_back(current); // O(1). +24 + 4*m байт, m - колво элементов в текущей комбинации

    // Проходимся по элементам массива, начиная с индекса start, добавляем текущий элемент в текущую комбинацию
    for (int i = start; i < array.size(); ++i) { // O(1) для выделения памяти для i, сравнения и инкремента. +4 байт
        current.push_back(array[i]); // O(1). +4 байт за добавление int
        // Рекурсивно вызываем функцию для генерации комбинаций, начиная с следующего элемента
        generate_combinations(array, i + 1, current, combinations); // перебираем все возможные комбинации элементов array, каждый элемент либо входит либо не входит в конкретный набор, получаем сложность O(2^N)
        // Удаляем последний добавленный элемент, чтобы вернуться к предыдущему положению
        current.pop_back(); // O(1)
    }
}
// итог по функции generate_combinations: O(2^N)


/*** Функция для получения всех комбинаций элементов заданного массива ***/
std::vector<std::vector<int>> get_all_combinations(const std::vector<int>& array) { // +24 байт на вектор
    // Создаём вектор, где будут все комбинации, и вектор для хранения текущей комбинации
    std::vector<std::vector<int>> combinations; // O(1) - инициализация вектора. +24 байт
    std::vector<int> current; // O(1). +24 байт

    // Вызываем функцию для генерации комбинаций, начиная с индекса 0, и потом возвращаем вектор со всеми комбинациями
    generate_combinations(array, 0, current, combinations); // вызов функции, сложность которой O(2^N), значит получаем O(2^N) и для get_all_combinations
    return combinations; // O(1)
}
// итог по функции get_all_combinations: O(2^N)


/*** Функция, принимающая вектор со всеми комбинациями, проходящаяся по ним и возвращающая ответ на задачу о рюкзаке ***/
std::vector<std::vector<int>> backpack(std::vector<std::vector<int>>& data, int limit) { // +24 байт на вектор, +4 байт на int
    // Создаём векторы, хранящие вес и стоимость каждого предмета
    std::vector<int> weigths; // O(1). +24 байт
    std::vector<int> costs; // O(1). +24 байт

    // проходимся по data и заполняем векторы с весом и стоимостью. Цикл: O(N)
    for (const auto& item : data) {
        weigths.push_back(item[0]); // O(1) N раз. +4 байт за каждый раз
        costs.push_back(item[1]); // O(1) N раз. +4 байт за каждый раз
    }

    // получаем все возможные комбинации весов и стоимостей, каждой i-ой комбинации весов будет соответствовать i-ая комбинация стоимостей
    std::vector<std::vector<int>> all_var_weigth = get_all_combinations(weigths); // O(2^N)
    std::vector<std::vector<int>> all_var_cost = get_all_combinations(costs); // O(2^N)
    // получаем O(2^N), тк get_all_combinations имеет эту сложность
    
    // задаём переменную для хранения макс стоимости и вектор для хранения результата
    int res_cost = -1; // O(1). +4 байт
    std::vector<int> res_pack; // O(1). +24 байт
    
    // проходимся циклом по всем 2^N комбинациям, получаем O(2^N)
    for (int k = 0; k < size(all_var_cost); k++) { // +4 байт на int
        // получаем текущие наборы веса и стоимости
        std::vector<int> curr_weight = all_var_weigth[k]; // O(1). +24 + k байт
        std::vector<int> curr_cost = all_var_cost[k]; // O(1). +24 + k байт, k - размер памяти на векторы all_var_weight и all_var_cost (сформированные через get_all_combinations)

        // суммируем вес для текущей комбинации
        int weigth_sum = 0; // O(1)
        // цикл: O(K), пробегаемся по текущей комбинации, где К элементов, К от 0 до N
        for (int sum_elem : curr_weight) {
            weigth_sum += sum_elem; // O(1)
        }
        
        // а теперь суммируем стоимость текущей комбинации
        int cost_sum = 0; // O(1). +4 байт
        // цикл: O(K), пробегаемся по текущей комбинации, где К элементов, К от 0 до N
        for (int cost_elem : curr_cost) {
            cost_sum += cost_elem; // O(1)
        }

        // проверяем условия: перезаписываем результат, если не вышли за лимит веса и если стоимость больше текущей
        if ((cost_sum > res_cost) and (weigth_sum <= limit)) { // O(1)
            res_cost = cost_sum; // O(1). +4 байт на int
            res_pack = curr_weight; // O(1). +24 байта на вектор
        }
    }
    // итог по циклу for: O(N * 2^N), сначала пробегаемся по 2^N значениям, также имеем вложенный цикл, который каждый раз перебирает до N значений
    // результат: первый элемент это вектор с итоговой стоимостью, а второй - это вектор с итоговой комбинацией весов
    return {{res_cost}, res_pack}; // O(1)
}
// итог по функции backpack: O(N * 2^N)


/*** Функция, выводящая ответ к задаче ***/
void result_output(std::vector<std::vector<int>> res) {
    std::cout << "Items: [ "; // O(1)
    // цикл: O(N), пробегаем по всем значениям из res[1]
    for (int weight : res[1]) { // +4 байт на int
        std::cout << weight << " "; // O(1) N раз
    }
    std::cout << "]" << std::endl; // O(1)
    std::cout << "Max cost: " << res[0][0] << std::endl; // O(1)
}
// итог по result_output: O(N)


int main() {
    // Результаты для различных случаев

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