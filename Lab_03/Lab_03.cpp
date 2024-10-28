#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string compress_str(const string& input) { // функция сжатия строки
	if (input.empty()) { //О(1) - проверка состояния
		return ""; 
	}

	string compressed; //O(1) для выделения памяти
	int count = 1; //О(1)+О(1) для выделения памяти и присванивание 
	int len = input.length(); //О(1)+О(1) для выделения памяти и присванивание
	for (size_t i = 0; i < len; i++) { //O(1)+О(1)+О(1)+О(1) - присваивание, сравнение, инкремент; в худшем случае - О(n)
		if (i + 1 < len && input[i] == input[i + 1]) { //О(1)+О(1)+О(1)+О(1)+O(1)+O(1)- вычисление i+1, сравнение,
			                                                    //взятие элементов по индексу [i],[i+1], сравнение, операция "&&" 	
			count++; // О(1) - инкремент
		}
		else {
			// Добавляем символ только если количество больше 1
			compressed += input[i];//O(1)+O(1) - выделение памяти, взятие по индексу

			if (count > 1) { // O(1) - операция сравнения
				compressed += to_string(count); //О(1)+О(n) - выделение памяти, функция перевода в строку
			}
			count = 1; // О(1) присваивание
		}
	}
	// Сложность алгоритма составляет:
    //В худшем случае : О(n)
    //В лучшем случае: O(1)

	return compressed;
}

void tests() {
	// Тест 1
	string input1 = "aaabbc";
	string expected1 = "a3b2c";
	assert(compress_str(input1) == expected1);

	// Тест 2
	string input2 = "abc";
	string expected2 = "abc"; // без изменений
	assert(compress_str(input2) == expected2);

	// Тест 3
	string input3 = "aaa";
	string expected3 = "a3";
	assert(compress_str(input3) == expected3);

	// Тест 4
	string input4 = "a";
	string expected4 = "a"; // без изменения
	assert(compress_str(input4) == expected4);

	// Тест 5
	string input5 = "";
	string expected5 = "";// без изменений
	assert(compress_str(input5) == expected5);

	// Тест 6
	string input6 = "aaabbaaa";
	string expected6 = "a3b2a3";
	assert(compress_str(input6) == expected6);

	cout << "OK" << endl;
}

int main() {
	tests();

	return 0;
}