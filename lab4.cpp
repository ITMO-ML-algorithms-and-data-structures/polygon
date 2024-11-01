#include <iostream>
#include <vector>
#include <unordered_set>
#include <Windows.h>
#include <ctime>

// Перевод числа в двоичную систему с сохранением лидирующих нулей
std::vector <short int> dec_to_bin(int digit, const int& size_of_res) {
	std::vector <short int> res;
	int count_digits = 0; // Сколько цифр в двоичной записи числа
	while (digit > 0) {
		res.insert(res.begin(), digit % 2);
		count_digits++;
		digit = digit / 2;
	}
	for (int i = 0; i < size_of_res - count_digits; i++) {  // Добавление лидирующих нулей
		res.insert(res.begin(), 0);
	}
	return res;
}

// Получение всех бинарных масок
std::vector <std::vector <short int>> binary_masks(const int& total_variants) {
	std::vector <std::vector <short int>> res;
	int size_of_res = ceil(log2(total_variants));
	for (int i = 0; i < total_variants; i++) {
		res.push_back(dec_to_bin(i, size_of_res));
	}
	return res;
}


std::vector <std::unordered_set <int>> find_sets(const std::vector <std::unordered_set <int>>& sets, const std::unordered_set <int>& universe) {
	std::vector <std::unordered_set <int>> best; // Наименьшее количество множеств
	int best_variant = 0;
	int min_sets_count = 26;
	int total_sets = sets.size();
	int total_variants = std::pow(2, total_sets);
	std::vector <std::vector <short int>> masks = binary_masks(total_variants); // Бинарные маски


	for (int i = 0; i < total_variants; i++) {
		int count_sets = 0;   // Сколько единиц (используется множеств)
		std::unordered_set <int> new_set{};
		for (int j = 0; j < total_sets; j++) { // masks[i] - маска
			if (masks[i][j] == 1) {
				count_sets++;
				new_set.insert(sets[j].begin(), sets[j].end());
			}
		}

		bool flag = true;
		for (auto m : universe) { // Проверка на покрытие множества
			if (new_set.find(m) == new_set.end()) {
				flag = false;
			}
		}

		if (flag) { 
			if (count_sets < min_sets_count) { // Сравнение с минимальным набором множеств
				best_variant = i;
				min_sets_count = count_sets;
			}
		}
	}
	for (int i = 0; i < total_sets; i++) { // Заполнение результата
		if (masks[best_variant][i] == 1) {
			best.push_back(sets[i]);
		}
	}
	if (min_sets_count == 26) {
		std::cout << "[ERROR] Невозможно покрыть другими множествами";
	}
	return best;
}
int test_passed = 0; // Пройденные тесты
int test_failed = 0; // Нейпройденные тесты

void assertEqual(const std::vector <std::unordered_set <int>>& sets, const std::unordered_set <int>& universe, 
	std::vector <std::unordered_set <int>> res, const std::string& testName) {
	if (find_sets(sets, universe) == res) {
		std::cout << "[PASSED]" << testName << "\n";
		test_passed++;
	}
	else {
		std::cout << "[NOT PASSED]" << testName << "\n";
		test_failed++;
	}
}

void report() { // Отчёт по тестам
	std::cout << "\nИтого тестов пройдено: " << test_passed << "\n";
	std::cout << "\nИтого тестов не пройдено: " << test_failed << "\n";
}

void run_tests() { // Запуск тестов
	assertEqual({ {1, 2}, {2, 3}, {3, 4} }, { 1, 2, 3 }, { {1, 2}, {3, 4} }, "Тест: Пример из условия");
	assertEqual({}, { 1, 2, 3 }, {}, "Тест: Пустой набор множеств");
	assertEqual({ {1, 2}, {2, 3}, {3, 4} }, {}, {}, "Тест: Пустое множество");
	assertEqual({ {1, 2}, {1, 2, 3}, {3, 4} }, { 1, 2, 3 }, { {1, 2, 3} }, "Тест: Оптимальный набор состоит из 1 элемента");
	assertEqual({ {1}, {2}, {3}, }, { 1, 2, 3 }, { {1}, {2}, {3} }, "Тест: Оптимальный набор состоит из всех элемента");
	report();
}

int main() {
	std::clock_t start = std::clock();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (auto i : find_sets({ {1, 2}, {2, 3}, {3, 4} }, { 1, 2, 3 })) {
		for (auto j : i) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
	run_tests();
	std::clock_t end = std::clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Время выполнения: " << duration << " секунд" << std::endl;
	return 0;
}
