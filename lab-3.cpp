//Подсчет значений в массиве. Hard. Кирпо Тимофей Сергеевич. ИСУ 466167

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

std::vector<int> mass_count(int size, std::vector<std::string> names) { //4 байта + 24 байта + Y байт * X байт(Y - количество элементов)
    std::unordered_map<std::string, int> counts; // 32 байта + Y байт * X байт

    //Считаем элементы с помощью хэш-таблицы
    for (int i = 0; i < size; i++) {
        counts[names[i]]++;
    }

    //Создаем result и добавляем туда подсчитанные элементы
    std::vector<int> result(size); //24 байта + Y байт * 4 байта(Y - количество элементов)
    for (int i = 0; i < size; i++) {
        result[i] = counts[names[i]];
    }
    return result;
}

void tests() {
    if (mass_count(5, {"1", "2", "3", "1", "2"}) == std::vector<int>{2, 2, 1, 2, 2}) {
        std::cout << "Test1 passed" << std::endl;
    }else {
        std::cout << "Test1 failed" << std::endl;
    }

    if (mass_count(2, {"1", "2"}) == std::vector<int>{1, 1}) {
        std::cout << "Test2 passed" << std::endl;
    }else {
        std::cout << "Test2 failed" << std::endl;
    }

    if (mass_count(2, {"1", "1"}) == std::vector<int>{2, 2}) {
        std::cout << "Test3 passed" << std::endl;
    }else {
        std::cout << "Test3 failed" << std::endl;
    }

    if (mass_count(5, {"1", "1", "1", "1", "1"}) == std::vector<int>{5, 5, 5, 5, 5}) {
        std::cout << "Test4 passed" << std::endl;
    }else {
        std::cout << "Test4 failed" << std::endl;
    }

    if (mass_count(5, {"1", "2", "3", "4", "5"}) == std::vector<int>{1, 1, 1, 1, 1}) {
        std::cout << "Test5 passed" << std::endl;
    }else {
        std::cout << "Test5 failed" << std::endl;
    }
    std::vector<int> vec = {};
    assert(mass_count(5, {}) == vec);
}

int main() {
    tests();
    return 0;
}


//Итого память: 4 байта + 24 байта + Y байт * X байт + 32 байта + Y байт * X байт + 24 байта + Y байт * 4 байта =
// = 28 + XY + 32 + XY + 24 + 4Y = 84 + 2XY + 4Y байт
//X - количество символов в строке
//Y - количество элементов