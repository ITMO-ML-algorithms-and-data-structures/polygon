#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <chrono>



void exchange_sort(std::vector <int>& digits, const int& size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (digits[i] > digits[j]) {
                std::swap(digits[i], digits[j]);
			}
		}
	}
}



void cocktail_shaker_sort(std::vector <int>& digits, const int& size) {
	bool swapped = true;
	int start = 0;
	int end = size - 1;
    while (swapped) { 
        swapped = false;

        for (int i = start; i < end; ++i) { // Первый проход: максимальный элемент помещается в конец
            if (digits[i] > digits[i + 1]) {
                std::swap(digits[i], digits[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;


        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) { // Второй проход: минимальный элемент помещается в начало
            if (digits[i] > digits[i + 1]) {
                std::swap(digits[i], digits[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}



void pigeonhole_sort(std::vector <int>& digits, const int& size) {
    if (size > 0) {
        int minimum = digits[0]; 
        int maximum = digits[0];
        for (int i = 0; i < size; i++) {
            if (digits[i] > maximum) {
                maximum = digits[i];
            }
            else if (digits[i] < minimum) {
                minimum = digits[i];
            }
        }
        int range = maximum - minimum + 1; // Количество чисел, которые могут встретиться
        std::vector <int> holes(range, 0);

        for (int i = 0; i < size; i++) { // Сколько раз встречается каждое число
            holes[digits[i] - minimum]++;
        }

        int index = 0;
        for (int i = 0; i < range; ++i) {
            while (holes[i] > 0) {
                digits[index++] = i + minimum;
                holes[i]--;
            }
        }
    }
}



bool is_sorted(const std::vector <int>& digits, const int& size) {
    bool flag = true;
    for (int i = 0; i < size - 1; i++) {
        if (digits[i] > digits[i + 1]) {
            flag = false;
        }
    }
    return flag;
}



std::vector <int> random_digits(const int& size) { // заполнение случайными числами
    std::vector<int> random_digits(size);
    srand(time(0));
    std::generate(random_digits.begin(), random_digits.end(), std::rand);
    return random_digits;
}



std::vector <int> all_sorted() { // отсортированные числа
    std::vector<int> vec;
    for (int i = 0; i < 1000; i++) {
        vec.push_back(i);
    }
    return vec;
}


std::vector <int> all_unsorted() { // неотсортированные числа
    std::vector<int> vec;
    for (int i = 1000; i > 0; i--) {
        vec.push_back(i);
    }
    return vec;
}


int test_passed = 0; // Пройденные тесты
int test_failed = 0; // Нейпройденные тесты


void assertEqual(const std::vector <int>& digits, const int& size, const std::string& testName) {
    if (is_sorted(digits, size) == true) {
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

void exchange_test() {
    // лучший случай (все элементы отсортированы)
    std::vector <int> best = all_sorted();
    exchange_sort(best, 1000);
    assertEqual(best, 1000, "Тест: exchange sort лучший случай");
    // обычный случай (все элементы отсортированы)
    std::vector <int> average = random_digits(1000);
    exchange_sort(average, 1000);
    assertEqual(average, 1000, "Тест: exchange sort средний случай");
    // худший случай (все элементы отсортированы)
    std::vector <int> worst = all_unsorted();
    exchange_sort(worst, 1000);
    assertEqual(worst, 1000, "Тест: exchange sort худший случай");
}

void cocktail_shaker_test() {
    // лучший случай (все элементы отсортированы)
    std::vector <int> best = all_sorted();
    cocktail_shaker_sort(best, 1000);
    assertEqual(best, 1000, "Тест: cocktail shaker sort лучший случай");
    // обычный случай (все элементы отсортированы)
    std::vector <int> average = random_digits(1000);
    cocktail_shaker_sort(average, 1000);
    assertEqual(average, 1000, "Тест: cocktail shaker sort средний случай");
    // худший случай (все элементы отсортированы)
    std::vector <int> worst = all_unsorted();
    cocktail_shaker_sort(worst, 1000);
    assertEqual(worst, 1000, "Тест: cocktail shaker sort худший случай");
}

void pigeonhole_test() {
    // лучший случай (все элементы одинаковые)
    std::vector <int> best;
    for (int i = 0; i < 1000; i++) {
        best.push_back(0);
    }
    pigeonhole_sort(best, 1000);
    assertEqual(best, 1000, "Тест: pigeonhole sort лучший случай");
    // обычный случай (часть элементов различна)
    std::vector <int> average = random_digits(1000);
    pigeonhole_sort(average, 1000);
    assertEqual(average, 1000, "Тест: pigeonhole sort средний случай");
    // худший случай (все элементы разные)
    std::vector <int> worst = all_unsorted();
    pigeonhole_sort(worst, 1000);
    assertEqual(worst, 1000, "Тест: pigeonhole sort худший случай");
}

void run_tests() { // Запуск тестов
    // exchange sort
    exchange_test();
    // cocktail shaker sort
    cocktail_shaker_test();
    // pigeonhole sort
    pigeonhole_test();
    report();
}




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    run_tests();
    return 0;
}
