#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

#include "ArrayProcessor.cpp"

void test_fillna_mean() {
    ArrayProcessor processor;
    {
        std::vector<int> array = {};
        processor.fillna_mean(array);
        assert(array.empty());
    }

    {
        std::vector<int> array = {1, 2, 3, 4};
        processor.fillna_mean(array);
        assert(array == std::vector<int>({1, 2, 3, 4}));
    }

    {
        std::vector<int> array = {-1, -1, -1, -1};
        processor.fillna_mean(array);
        assert(array == std::vector<int>({0, 0, 0, 0}));
    }

    {
        std::vector<int> array = {1, -1, 3, -1, 5};
        processor.fillna_mean(array);
        assert(array == std::vector<int>({1, 1, 3, 1, 5}));
    }

    {
        std::vector<int> array = {1, -1, 10, 4};
        processor.fillna_mean(array);
        assert(array == std::vector<int>({1, 3, 10, 4}));
    }
}

void test_read_array() {
    ArrayProcessor processor;
    {
        std::istringstream input("1, 2, null, 4");
        std::cin.rdbuf(input.rdbuf());
        std::vector<int> array = processor.read_array();
        assert(array == std::vector<int>({1, 2, -1, 4}));
    }

    {
        std::istringstream input("1, nan, 3, none");
        std::cin.rdbuf(input.rdbuf());
        std::vector<int> array = processor.read_array();
        assert(array == std::vector<int>({1, -1, 3, -1}));
    }

    {
        std::istringstream input("1, null, 10, 4");
        std::cin.rdbuf(input.rdbuf());
        std::vector<int> array = processor.read_array();
        assert(array == std::vector<int>({1, -1, 10, 4}));
    }
}

int main() {
    test_fillna_mean();
    test_read_array();
    std::cout << "Все тесты пройдены успешно!" << std::endl;
}