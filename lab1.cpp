#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <gtest/gtest.h>

using namespace std;

// Задача:
// Удалить дублирующиеся значения из входного массива

// Асимптотическая сложность этого алгоритма O(N*logN), где N - размер массива
// Алгоритм вводит массив и сортирует его для использования функции unique, которая делает отсортированный массив уникальным за O(n), возвращая указатель на end измененного уникального массива

// По памяти 8*N байт, где N - размер входного массива а 8 - размер элемента long long

vector<long long> solve(const string &filename) {  
    ifstream file(filename);  // Открываем файл

    int size;
    file >> size;  // Ввод размера массива

    vector<long long> res;

    for (int i = 0; i < size; i++) {
        long long elem;
        file >> elem;  // Ввод очередного элемента массива
        res.push_back(elem);
    }
    
    sort(res.begin(), res.end()); // Сортируем вектор за O(N*logN)
    res.resize(unique(res.begin(), res.end()) - res.begin()); // С помощью разности указателей получаем размер изменененного вектора и убираем дубликаты с конца массива

    file.close();  // Закрываем файл
    return res;
}

// Unit tests
const string filename = "test.txt";

void write_file(const vector<long long> &arr) {
    ofstream out(filename);
    out << arr.size() << '\n';
    for (long long elem : arr) {
        out << elem << ' ';
    }
    out.close();
}

TEST(DublicateTest, Test0) {
    write_file({});
    EXPECT_EQ(solve(filename), vector<long long>({}));
}

TEST(DublicateTest, Test1) {
    write_file({1, 2, 3, 4, 5});
    EXPECT_EQ(solve(filename), vector<long long>({1, 2, 3, 4, 5}));
}

TEST(DublicateTest, Test2) {
    write_file({1, 1, 1, 2, 3, 3, 4, 4, 4, 5});
    EXPECT_EQ(solve(filename), vector<long long>({1, 2, 3, 4, 5}));
}

TEST(DublicateTest, Test3) {
    write_file({3, 1, 2, 3, 2, 3});
    EXPECT_EQ(solve(filename), vector<long long>({1, 2, 3}));
}

int main(int argc, char* argv[]) { // В функцию main передается количество аргументов и сами аргументы командной строки в виде массива указателей
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
