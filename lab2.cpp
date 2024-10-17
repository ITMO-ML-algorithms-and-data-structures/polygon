#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

vector<int> make_sample(vector<int>& in, int size) {
    if (size > in.size()) // Не можем сделать семплирование нужного размера
        throw runtime_error("Size must be bigger than vector size");;

    vector<int> out;
    out.reserve(size); // Метод reserve резервирует память без инициализации элементов, имеет амортизированную временную сложность О(1)

    // Избавлямся от дубликатов для работы sample за O(n)
    unordered_set<int> uniq;
    for (int elem : in) // Заполнение за O(n)
        uniq.insert(elem);
    in.clear(); // Временная сложность O(1)
    in.reserve(uniq.size());
    for (int elem : uniq)
        in.push_back(elem);

    mt19937 rnd(time(0)); // Генератор случайных чисел с начальным значением, основанным на текущем времени
    sample(in.begin(), in.end(), back_inserter(out), size, rnd); // Сэмплирование за O(n)
    return out;
}

bool check_sample(const vector<int>& vec) {
    unordered_set<int> uniq;
    for (int elem : vec)
        uniq.insert(elem);
    return uniq.size() == vec.size(); // Если после добавление в set количество значений не изменилось, значит дубликатов не было
}

TEST(SampleTest, Test0) {
    int size = 2;
    vector<int> in({1, 2, 3, 4});

    vector<int> res = make_sample(in, size);
    EXPECT_TRUE(check_sample(res));
}

TEST(SampleTest, Test1) {
    int size = 3;
    vector<int> in({1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9});

    vector<int> res = make_sample(in, size);
    EXPECT_TRUE(check_sample(res));
}

TEST(SampleTest, Test2) {
    int size = 2;
    vector<int> in({1, 2, 2, 3});

    vector<int> res = make_sample(in, 2);
    EXPECT_TRUE(check_sample(res));
}

TEST(SampleTest, Test3) {
    int size = 3;
    vector<int> in({1, 1, 2, 2, 3, 3, 3});

    vector<int> res = make_sample(in, size);
    EXPECT_TRUE(check_sample(res));
}

TEST(SampleTest, Test4) {
    int size = 0;
    vector<int> in({});

    vector<int> res = make_sample(in, size);
    EXPECT_TRUE(check_sample(res));
}

TEST(SampleTest, Test5) {
    int size = 3;
    vector<int> in({1, 2});

    EXPECT_THROW(make_sample(in, size), runtime_error);
}

TEST(SampleTest, Test6) {
    int size = 3;
    vector<int> in({1, 2, 3});

    vector<int> res = make_sample(in, size);
    EXPECT_TRUE(check_sample(res));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}