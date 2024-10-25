#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> CountUniqueValues(int size, std::vector<std::string> arr) {
	// Подсчитать кол-во уникальных значений и заменить каждое значение кол-вом
	
	std::unordered_map<std::string, int> input;
	// Создаём хэш-таблицу для подсчёта кол-ва уникальных значений

	for (int i = 0; i < arr.size(); i++) {
		input[arr[i]]++;
		// Увеличиваем счётчик значений текущей строки, время: O(1) каждая
	}
	// Сложность цикла: O(arr.size())

	std::vector<int> output(size);
	// Создаём вектор для вывода результата размера size
	
	for (int i = 0; i < size; i++) {
		output[i] = input[arr[i]];
		// Подготовка вектора для вывода результата (подсчёт кол-ва уникальных значений)
		// Время: O(1) каждая
	}
	// Сложность цикла: O(size)

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

	int size; // O(1) - выделение памяти
	std::cout << "Enter size: ";
	std::cin >> size; // O(1) - присваивание

	if (size < 0) {
		std::cout << "The size cannot be negative.";
		return 1;
	}

	std::vector<std::string> arr(size); // O(1) - выделение памяти)

	for (int i = 0; i < size; i++) {
		std::cout << "Enter element " << (i + 1) << ": ";
		std::cin >> arr[i];
	}
	// Сложность цикла: O(size)

	std::vector<int> result = CountUniqueValues(size, arr);

	std::cout << "Result: { ";
	for (int i = 0; i < size; i++) {
		std::cout << result[i] << " ";
	}
	// Сложность цикла: O(size)
	std::cout << " }";

	// Сложность алгоритма:
	// O(N) - в худшем случае если все элементы одинаковы
	// O(K) - средний случай, где 1 < K < N если есть повторяющиеся элементы
	// O(N) - лучший случай при условии что все элементы уникальны

	return 0;
}
