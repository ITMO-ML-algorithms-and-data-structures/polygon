#include "pch.h"

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

// Функция для объединения элементов подмножества множеств | O(N*K), N = subset.size(), K = unionSet.size()
std::set<int> unionOfSets(const std::vector<std::set<int>>& sets, const std::vector<int>& subset) {
    std::set<int> unionSet; // 24 + ((24+4*k)*n) байт
    for (int index : subset) { //4 байт
        unionSet.insert(sets[index].begin(), sets[index].end());
    }
    return unionSet;
}

// проверка на покрытие мн-ва | O(U+logU), U = universe.size()
bool setInSet(const std::set<int>& unionSet, const std::set<int>& universe) {
    for (int num : universe) {//4 байта
        if (unionSet.count(num) == 0) { // O(logU)
            return false;
        }
    }
    return true;
}

// Функция для поиска минимального покрытия | O(2^n * (n+(N*K+U+logU)))  , n  sets.size()
std::vector<int> findMinCover(const std::vector<std::set<int>>& sets, const std::set<int>& universe) {
    int n = sets.size(); //4 байта 
    std::vector<int> bestCover;//24 байта
    int minSize = 25; //4 байта

    // Перебираем все подмножества с битовой маской
    for (int mask = 1; mask < (1 << n); ++mask) { //4 байта
        std::vector<int> subset;// каждый из 2**n массивов по 24байта

        // Формируем подмножество для текущей маски
        for (int i = 0; i < n; ++i) { //4 байта
            if (mask & (1 << i)) {
                subset.push_back(i); // 4 байта каждый эл-нт
            }
        }

        // Находим объединение подмножества
        std::set<int> unionSet = unionOfSets(sets, subset); // 24 + (4*k) байт

        // Проверяем, покрывает ли подмножество универcум
        if (setInSet(unionSet, universe)) {
            if (subset.size() < minSize) {
                minSize = subset.size();
                bestCover = subset;
            }
        }
    }

    return bestCover;
}

int NotMain() {
    std::vector<std::set<int>> sets; //24+(n*(24+k*4 байт))байт
    std::set<int> universe; // 24+4*k байт
    std::vector<int> uniset; // 24 + 4*k байт 
    if (universe.size() > 0) {
        uniset = findMinCover(sets, universe); //24+4*k байт
    }
    else {
        uniset = { 0 };
    }


    ///вывод | O(n*k)
    std::cout << "[";
    for (size_t i = 0; i < uniset.size(); i++) { //8байт
        std::cout << "{";
        for (auto it = sets[i].begin(); it != sets[i].end(); ++it) { //4байта
            std::cout << *it;
            if (std::next(it) != sets[i].end()) {
                std::cout << ",";
            }
        }
        std::cout << "}";
        if ((i + 1) != uniset.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}




class Pupipam : public testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};


// Тест на базовый случай
TEST(MinCoverTests, BasicCase) {
    std::vector<std::set<int>> sets = { {1, 2}, {11, 3}, {3, 4}, {14, 2}, {2, 18}, {3, 9}, {1, 2}, {21, 33}, {3, 4}, {15, 2}, {2, 3}, {3, 9} };
    std::set<int> universe = { 1, 2, 3, 9, 21, 15, 11, 18, 33, 14 };
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = { 0, 1, 3, 4, 5, 7, 9 }; // Ожидаем, что будут выбраны множества {1, 2} и {3, 9}
    EXPECT_EQ(result, expected);
}

// Тест на случай с пустым универcумом
TEST(MinCoverTests, EmptyUniverse) {
    std::vector<std::set<int>> sets = { {1, 2}, {2, 3}, {3, 4} };
    std::set<int> universe = {};
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = { 0 }; // Пустой универcум требует пустого покрытия
    EXPECT_EQ(result, expected);
}

// Тест на случай с пустыми множествами
TEST(MinCoverTests, EmptySets) {
    std::vector<std::set<int>> sets = { {}, {}, {} }; // Три пустых множества
    std::set<int> universe = { 1, 2, 3 };
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = {}; // Невозможно покрыть универcум
    EXPECT_EQ(result, expected);
}

// Тест на случай, когда есть только одно множество
TEST(MinCoverTests, SingleSet) {
    std::vector<std::set<int>> sets = { {1, 2} };
    std::set<int> universe = { 1, 2 };
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = { 0 }; // Одно множество покрывает универcум
    EXPECT_EQ(result, expected);
}

// Тест на случай, когда покрытие невозможно
TEST(MinCoverTests, NoCoverPossible) {
    std::vector<std::set<int>> sets = { {1}, {2}, {3} };
    std::set<int> universe = { 4 }; // Универcум, который не может быть покрыт
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = {}; // Невозможно покрыть
    EXPECT_EQ(result, expected);
}

// Тест на случай с дублирующимися элементами
TEST(MinCoverTests, DuplicateElements) {
    std::vector<std::set<int>> sets = { {1, 2}, {2, 3}, {3, 1} };
    std::set<int> universe = { 1, 2, 3 };
    std::vector<int> result = findMinCover(sets, universe);
    std::vector<int> expected = { 0, 1 }; // Можно выбрать любые два из трех
    EXPECT_TRUE((result == std::vector<int>{0, 1}) || (result == std::vector<int>{0, 2}) || (result == std::vector<int>{1, 2}));
}



std::vector<std::set<int>> readSets(const std::string& filename) {
    std::vector<std::set<int>> sets;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::set<int> currentSet;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            currentSet.insert(num);
        }
        sets.push_back(currentSet);
    }

    return sets;
}

std::set<int> readUniverse(const std::string& filename) {
    std::set<int> universe;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            universe.insert(num);
        }
    }

    return universe;
}

// Тест на случай с большим числом множеств и элементов универсума
TEST(MinCoverTests, LargeComplexCase) {
    std::vector<std::set<int>> sets = readSets("C:/Users/agafo/Desktop/lab42/sets.txt");
    std::set<int> universe = readUniverse("C:/Users/agafo/Desktop/lab42/universum.txt");
    // Ожидаемое покрытие

    std::vector<int> expected = { 0, 1, 4, 17 }; // Ожидаем, что будут выбраны множества {1, 2, 3, 4, 5}, {3, 4, 5, 6, 7}, {10, 11, 12, 13, 14}, и {1, 20, 30, 40, 50}

    // Выполнение поиска минимального покрытия
    std::vector<int> result = findMinCover(sets, universe);

    // Проверка результата
    EXPECT_EQ(result, expected);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

