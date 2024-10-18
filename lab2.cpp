#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

std::vector <double> MinMaxScaler(int size, const std::vector<int>& digits) {
	std::vector <double> res; // O(1) - Выделение памяти
	if (size != 0) { // O(1) - Сравнение
		int minimum = digits[0]; // O(1) + O(1) - Взятие по индексу и присваивание
		int maximum = digits[0]; // O(1) + O(1) - Взятие по индексу и присваивание
		//Поиск минимального и максимального числа     во всех случаях O(N)
		for (int i : digits) {
			if (i > maximum) { // O(1) - Сравнение
				maximum = i; // O(1) - Присваивание
			}
			else if (i < minimum) { // O(1) - Сравнение
				minimum = i; // O(1) - Присваивание
			}
		}
		//Проверка, чтобы не делить на 0
		if (maximum == minimum) { // O(1) - Сравнение
			maximum = 1; // O(1) - Присваивание
			minimum = 0; // O(1) - Присваивание
		}
		//Во всех случаях O(N)
		for (int i : digits) {
			double new_digit = static_cast<double>(i - minimum) / (maximum - minimum); // O(1) + O(1) + O(1) + O(1) + O(1) - Арифм операции, смена типа данных и присваивание
			res.push_back(new_digit); // O(1) - Добавление в конец
		}	
	}
	// Сложность алгоритма:
	// O(1) - если получаем пустой список
	// O(N) - во всех остальных случаях


	return res;
}

void test() {  //тесты
    {
        // Пример из условия
        std::vector<int> digits = {1, 100, 1000001, 2};
        std::vector<double> res = MinMaxScaler(4, digits);
        std::vector<double> expected = { 0.0e+00, 9.9e-05, 1.0e+00, 1.0e-06 };
        assert(res == expected);
    }
	{
		// Пустой массив
		std::vector<int> digits = {};
		std::vector<double> res = MinMaxScaler(0, digits);
		std::vector<double> expected = {};
		assert(res == expected);
	}
	{
		// Все элементы одинаковые
		std::vector<int> digits = {2, 2, 2, 2};
		std::vector<double> res = MinMaxScaler(4, digits);
		std::vector<double> expected = {2, 2, 2, 2};
		assert(res == expected);
	}
	{
		// 1 элемент в массиве
		std::vector<int> digits = {100};
		std::vector<double> res = MinMaxScaler(1, digits);
		std::vector<double> expected = {100};
		assert(res == expected);
	}
	{
		// Отрицательные числа в массиве
		std::vector<int> digits = {-1, -4, 1, 0};
		std::vector<double> res = MinMaxScaler(4, digits);
		std::vector<double> expected = { 0.6, 0, 1, 0.8 };
		assert(res == expected);
	}

    std::cout << "All tests passed!" << "\n";
}


int main() {
	std::vector <double> res = MinMaxScaler(4, { 1, 100, 1000001, 2 });
	for (double i : res) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	test();
	return 0;
}
