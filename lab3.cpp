#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

std::vector <double> MinMaxScaler(const int& size, const std::vector<double>& digits) {
	std::vector <double> res; // O(1) - Выделение памяти
	if (size > 1) { // O(1) - Сравнение
		double minimum = digits[0]; // O(1) + O(1) - Взятие по индексу и присваивание
		double maximum = digits[0]; // O(1) + O(1) - Взятие по индексу и присваивание
		//Поиск минимального и максимального числа     во всех случаях O(N)
		for (double i : digits) {
			if (i > maximum) { // O(1) - Сравнение
				maximum = i; // O(1) - Присваивание
			}
			else if (i < minimum) { // O(1) - Сравнение
				minimum = i; // O(1) - Присваивание
			}
		}
		//Проверка, что не все элементы одинаковые
		if (maximum != minimum) { // O(1) - Сравнение
			//Во всех случаях O(N)
			for (const double& i : digits) {
				double new_digit = static_cast<double>(i - minimum) / (maximum - minimum); // O(1) + O(1) + O(1) + O(1) + O(1) - Арифм операции, смена типа данных и присваивание
				res.push_back(new_digit); // O(1) - Добавление в конец
			}
		}
		else {
			std::cout << "[ERROR] Все элементы одинаковые\n";
		}
	}
	else {
		std::cout << "[ERROR] Недостаточно элементов\n";
	}
	// Сложность алгоритма:
	// O(1) - если получаем пустой список
	// O(N) - во всех остальных случаях


	return res;
}

int test_passed = 0; // Количество пройденных тестов
int test_failed = 0; // Количество не пройденных тестов


// Тест
void assertEqual(const int& size, const std::vector<double>& digits, const std::vector<double>& res, const std::string& test_name) {
	if (MinMaxScaler(size, digits) == res) {
		std::cout << "[PASSED]" << test_name << "\n";
		test_passed++;
	}
	else {
		std::cout << "[FAILED]" << test_name << "\n";
		test_failed++;
	}
}


// Результаты тестирования
void report() {
	std::cout << "\nИтого пройдено: " << test_passed;
	std::cout << "\nИтого не пройдено: " << test_failed;
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <double> res = MinMaxScaler(4, { 1, 100,  1000001, 2 });
	for (double i : res) {
		std::cout << i << " ";
	}
	std::cout << "\n\n";

	assertEqual(4, {1, 100, 1000001, 2}, { 0.0e+00, 9.9e-05, 1.0e+00, 1.0e-06 }, "Тест: Пример из условия");
	assertEqual(0, {}, {}, "Тест: Пустой массив");
	assertEqual(4, { 2, 2, 2, 2 }, {}, "Тест: Все числа одинаковые");
	assertEqual(1, {100}, {}, "Тест: Массив из одного элемента");
	assertEqual(4, { -1, -4, 1, 0 }, { 0.6, 0, 1, 0.8 }, "Тест: Отрицательные элементы в массиве");
	assertEqual(4, { 0.1, 1, 10.1, 0.5 }, { 0, 0.09, 1, 0.04 }, "Тест: Дробные элементы в массиве");

	report();
	return 0;
}
