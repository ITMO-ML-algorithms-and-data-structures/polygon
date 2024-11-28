#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void brickSort(std::vector<int>& arr) {
    bool isSorted = false;
    int n = arr.size();

    while (!isSorted) {
        isSorted = true;

        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        for (int i = n - 2; i >= 0; i -= 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

void runTests() {
    // Тест 1: Пустой массив
    std::vector<int> test1;
    brickSort(test1);
    assert(test1.empty());

    // Тест 2: Массив из одного элемента
    std::vector<int> test2 = {5};
    brickSort(test2);
    assert(test2 == vector<int>({5}));

    // Тест 3: Массив из нескольких одинаковых элементов
    std::vector<int> test3 = {3, 3, 3, 3};
    brickSort(test3);
    assert(test3 == vector<int>({3, 3, 3, 3}));

    // Тест 4: Упорядоченный массив
    std::vector<int> test4 = {1, 2, 3, 4, 5};
    brickSort(test4);
    assert(test4 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 5: Обратный порядок
    std::vector<int> test5 = {5, 4, 3, 2, 1};
    brickSort(test5);
    assert(test5 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 6: Смешанный массив
    std::vector<int> test6 = {3, 1, 4, 2, 5};
    brickSort(test6);
    assert(test6 == vector<int>({1, 2, 3, 4, 5}));

    // Тест 7: Положительные и отрицательные числа 
    std::vector<int> test7 = {-1, 2, -3, 4, 0};
    brickSort(test7);
    assert(test7 == vector<int>({-3, -1, 0, 2, 4}));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}