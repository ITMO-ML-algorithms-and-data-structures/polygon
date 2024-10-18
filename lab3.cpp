#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> solution(int size, const vector<int>& arr, int k) {
    // O(1)
    if (k > size) {
        k = size;
    }
    // O(N) для выделения памяти
    vector<int> result(k); // + 4*k байт (максимум 4e9 байт)
    // O(N) для выделения памяти
    vector<int> shuffled = arr; // + 4*size (максимум 4e9 байт)
    // O(1)
    int j; // + 4 байт
    // Цикл O(N)
    for (int i = 0; i < size; i++) { // + 4 байт
        j = rand() % size; // O(1)
        swap(shuffled[i], shuffled[j]); // O(1)
    }
    // Цикл O(K)<=O(N)
    for (int i = 0; i < k; i++) { // + 4 байт
        result[i] = shuffled[i]; // O(1)
    }
    return result;
    // Алгоритмическая сложность по времени: O(size) + O(k <= size) <= O(2*size) = O(size) - линейное время
    // Затраты по дополнительной памяти: 4*size + 4*k + 3*4 = 4*size + 4*k + 12 байт <= 2*4*1e9 + 12 = 8000000012 байт
}


void test() {
    // Тест 1: Основная функциональность
    vector<int> input1 = { 1, 100, 10, 2 };
    int k1 = 3;
    vector<int> result1 = solution(input1.size(), input1, k1);
    assert(result1.size() == k1);

    // Тест 2: Когда k больше размера массива
    vector<int> input2 = { 1, 2, 3 };
    int k2 = 5;
    vector<int> result2 = solution(input2.size(), input2, k2);
    assert(result2.size() == input2.size());

    // Тест 3: Когда k равно нулю
    vector<int> input3 = { 1, 2, 3, 4, 5 };
    int k3 = 0;
    vector<int> result3 = solution(input3.size(), input3, k3);
    assert(result3.empty());

    // Тест 4: Проверка уникальности результатов
    vector<int> input4 = { 1, 2, 3, 4, 5 };
    int k4 = 3;
    vector<int> result4 = solution(input4.size(), input4, k4);
    bool unique = true;
    for (size_t i = 0; i < result4.size(); ++i) {
        for (size_t j = i + 1; j < result4.size(); ++j) {
            if (result4[i] == result4[j]) {
                unique = false;
                break;
            }
        }
        if (!unique) break;
    }
    assert(unique);

    // Тест 5: Пустой массив
    vector<int> input5 = {};
    int k5 = 1;
    vector<int> result5 = solution(input5.size(), input5, k5);
    assert(result5.empty());

    cout << "Tests passed" << endl;
}


int main() {
    // генератор
    srand(static_cast<unsigned>(time(0)));

    // Прогон тестов
    test();

    // Пример использования функции
    // Вход
    int size = 4;
    vector<int> arr = { 1, 100, 10, 2 };
    int k = 3;
    // Выход
    vector<int> answer = solution(arr.size(), arr, k);
    for (int i = 0; i < k; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    // Сгенерированный датасет
    // Вход
    vector<int> numbers;
    ifstream inputFile("C:/Users/b0605/CLionProjects/untitled/random_numbers.txt");
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }
    inputFile.close();
    int m = 4;
    // Выход
    vector<int> answer2 = solution(numbers.size(), numbers, m);
    for (int i = 0; i < m; i++) {
        cout << answer2[i] << " ";
    }
    return 0;
}
