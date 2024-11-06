#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

/* Есть массив, нужно подсчитать кол-во уникальных значений и заменить каждое значение кол-вом */

std::vector<int> CountUniqueValues(int size, std::vector<std::string> arr) {

	std::unordered_map<std::string, int> input; // O(1)
	// Создаём хэш-таблицу для подсчёта кол-ва уникальных значений

	for (int i = 0; i < arr.size(); i++) {
		input[arr[i]]++;
		// Увеличиваем счётчик значений текущей строки, время: O(1) каждая
	}
	// Сложность цикла: O(arr.size())

	std::vector<int> output(size); // O(1)
	// Создаём вектор для вывода результата размера size
	
	for (int i = 0; i < size; i++) {
		output[i] = input[arr[i]];
		// Подготовка вектора для вывода результата (подсчёт кол-ва уникальных значений)
		// Время: O(1) каждая
	}
	// Сложность цикла: O(size)

	// Итоговая сложность функции = O(1 + arr.size() + 1 + size) = 
	// = O(arr.size() + size + 2) ~= O(n)
	return output;
}

void test() {
	short int k = 0;
	{
		const int size = 4;
		std::vector<std::string> arr = { "Orange", "Red", "Green", "Orange" };
		std::vector<int> expected = { 2, 1, 1, 2 };
		std::vector<int> result = CountUniqueValues(size, arr);
		k += result == expected;
	}
	{
		const int size = 3;
		std::vector<std::string> arr = { "Orange", "Red", "Green" };
		std::vector<int> expected = { 1, 1, 1 };
		std::vector<int> result = CountUniqueValues(size, arr);
		k += result == expected;
	}
	{
		const int size = 3;
		std::vector<std::string> arr = { "Orange", "Orange", "Orange" };
		std::vector<int> expected = { 3, 3, 3 };
		std::vector<int> result = CountUniqueValues(size, arr);
		k += result == expected;
	}
	{
		const int size = 0;
		std::vector<std::string> arr = {  };
		std::vector<int> expected = {  };
		std::vector<int> result = CountUniqueValues(size, arr);
		k += result == expected;
	}
	std::cout << k << " passed of " << 4 << " tests\n";
}

int main() {
	test();

	std::ifstream file("input.txt");
	// Открытие файла для ввода массива

	if (file.is_open()) {
		std::cout << "File was opened\n";
	}
	else {
		std::cout << "File was not opened\n";
		return 1;
	} // Проверка открытия файла

	std::string st0;
	file >> st0;
	// Вписывание первой строки в st0
	
	int size = std::stoi(st0); 
	// Преобразование первой строки в int
	
	std::vector<std::string> arr;

	do {
		std::string st;
		file >> st;
		arr.push_back(st);
	} while (!file.eof());
	// Добавление элементов построчно в arr

	for (int element : CountUniqueValues(size, arr)) {
		std::cout << element << " ";
	} // Вывод результата
}
