#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

#define null NAN // Определяем null как NAN (Not A Number)

double mean(const std::vector<double>& vec) {
    double sum = 0;
    int count = 0;
    for (double num : vec) {   // O(N)
        if (not std::isnan(num)) { // O(1), проверка на NAN
            sum += num; // O(1)
            count++;    // O(1) подсчёт количества значений в массиве !NAN
        }
    }
    if (count == 0) { // O(1), проверка деления на 0
        return null;  // O(1), возвращаем NAN
    }
    return sum / count; // O(1) Среднее арифметическое
}

void f(std::vector<double>& vec) {
    double mean_ = mean(vec); // O(N), вычисление среднего арифметического
    for (double& num : vec) { // O(N)
        if (std::isnan(num)) { // O(1), проверка на NAN
            num = mean_; // O(1), замена значения средним Арифметическим
        }
    }
}

void test_mean() {
    // Тесты на находение среднего арифметического
    std::vector<double> in = {1, null, 2, 3, null, 4, null, 5};
    std::vector<double> in2 = {1.16, null, 2.16, 3.717, null, 4.713, null, 50};
    std::vector<double> in3 = {1, 2, 3, 4, 5};
    std::vector<double> in4 = {null, null, null, null};
    std::vector<double> in5 = {-10, 0, 3, 1, null};

    double res1 = 3;       // Ожидаемое среднее
    double res2 = 12.35;
    double res3 = 3;
    double res5 = -1.5;

    // Проверяем, что результат функции mean совпадает с ожидаемым
    assert(std::abs(res1 - mean(in)) < 10e-6);
    assert(std::abs(res2 - mean(in2)) < 10e-6);
    assert(std::abs(res3 - mean(in3)) < 10e-6);
    assert(std::isnan(mean(in4)));
    assert(std::abs(res5 - mean(in5)) < 10e-6);

    std::cout << "mean_test OK\n"; // Вывод результатов теста
}

void test_f() {
    // Тесты на замену null средним
    std::vector<double> in = {1, null, 2, 3, null, 4, null, 5};
    std::vector<double> in2 = {1.16, null, 2.16, 3.717, null, 4.713, null, 50};
    std::vector<double> in3 = {1, 2, 3, 4, 5};
    std::vector<double> in4 = {null, null, null, null};
    std::vector<double> in5 = {-10, 0, 3, 1, null};

    // Ожидаемые результаты после вызова f
    double mean_ = mean(in);
    std::vector<double> out = {1, mean_, 2, 3, mean_, 4, mean_, 5};
    mean_ = mean(in2);
    std::vector<double> out2 = {1.16, mean_, 2.16, 3.717, mean_, 4.713, mean_, 50};
    std::vector<double> out3 = {1, 2, 3, 4, 5};
    std::vector<double> out4 = {null, null, null, null};
    mean_ = mean(in5);
    std::vector<double> out5 = {-10, 0, 3, 1, mean_};

    // Вызываем функцию f и проверяем результаты
    f(in);
    f(in2);
    f(in3);
    f(in4);
    f(in5);

    assert(in == out);
    assert(in2 == out2);
    assert(in3 == out3);
    for (double& num : in4) { //проверка элементов на NAN
        assert(std::isnan(num));
    }
    assert(in5 == out5);

    std::cout << "f_test OK\n"; // Вывод результатов теста
}

int main() {
    test_mean();
    test_f();
return 0;

}
