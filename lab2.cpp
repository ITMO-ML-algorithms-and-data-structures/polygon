#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <gtest/gtest.h>

using namespace std;

vector<int> make_sample(vector<int>& in, int size) {
	vector<int> out;
	out.reserve(size); // Запрашивает, чтобы емкость была, по крайней мере, достаточной для содержания n элементов. Работает за O(n)

	// Избавлямся от дубликатов для работы sample за O(n)
	unordered_set<int> uniq;
    for (int elem : in)
        uniq.insert(elem);
    in.clear();
    in.reserve(uniq.size());
    for (int elem : uniq)
    	in.push_back(elem);

	sample(in.begin(), in.end(), back_inserter(out), size, mt19937(time(0))); // Сэмплирование за O(n) c // генератором случайных чисел с начальным значением, основанным на текущем времени
	return out;
}

bool check_sample(const vector<int>& vec, int size) {
	unordered_set<int> uniq;
    for (int elem : vec)
        uniq.insert(elem);
    return uniq.size() == vec.size(); // Если после добавление в set количество значений не изменилось, значит дубликатов не было
}

TEST(SampleTest, Test0) {
	int size = 2;
	vector<int> in({1, 2, 3, 4});

	vector<int> res = make_sample(in, size);
	for (auto x : res)
    	cout << x << ' ';
    EXPECT_TRUE(check_sample(res, size));
}

TEST(SampleTest, Test1) {
	int size = 3;
	vector<int> in({1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9});

    vector<int> res = make_sample(in, size);
    for (auto x : res)
    	cout << x << ' ';
    EXPECT_TRUE(check_sample(res, size));
}

TEST(SampleTest, Test2) {
	int size = 2;
	vector<int> in({1, 2, 2, 3});

    vector<int> res = make_sample(in, 2);
    for (auto x : res)
    	cout << x << ' ';
    EXPECT_TRUE(check_sample(res, size));
}

TEST(SampleTest, Test3) {
	int size = 3;
	vector<int> in({1, 1, 2, 2, 3, 3, 3});

    vector<int> res = make_sample(in, size);
    for (auto x : res)
    	cout << x << ' ';
    EXPECT_TRUE(check_sample(res, size));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}