#include <iostream>
#include <string>
#include <cassert>
using namespace std;
string compress_str(const string& input) { 
	string result; //O(1) для выделения памяти
	int number = 1; //О(1)+О(1) для выделения памяти и присванивание 
	int len = input.length();//О(1)+О(1) для выделения памяти и присванивание

	for (int i = 0; i < len; i++) { //O(1)+О(1)+О(1)+О(1) - присваивание, сравнение, инкремент; в худшем случае - О(n)
		if (i + 1 < len && input[i] == input[i + 1]) { //О(1)+О(1)+О(1)+О(1)+O(1)+O(1)- вычисление i+1, сравнение,
													   //взятие элементов по индексу [i],[i+1], сравнение, операция "&&" 
			number++; // О(1) - инкремент
		}
		else {
			result += to_string(number) + input[i]; //O(1)+О(n)+O(1)+O(1) - в лучшем случае(выделение памяти, 
														 //функция перевода в строку, взятие по индексу,сложение строк),
														 // в худшем: О(1)+О(n)+O(1)+O(n)
			number = 1; //О(1) - присваивание
		}

	}
    // Сложность алгоритма составляет:
    //В худшем случае : О(n)
    //В лучшем случае: O(1)

	return result;
}
// функции для тестирования
void tests() {
	assert(compress_str("aaabb") == "3a2b");
	assert(compress_str("abc") == "1a1b1c");
	assert(compress_str("") == "");  // Пустая строка
	assert(compress_str("a") == "1a");  // Одна буква
	assert(compress_str("aaa") == "3a");  // Три одинаковых символа
	assert(compress_str("abababa") == "1a1b1a1b1a1b1a");  // Чередующиеся символы
	assert(compress_str("aabbbaaac") == "2a3b3a1c");  // Смешанные символы
	cout << "Tests ok" << endl;
}

int main() {
	tests();
	string input;
	cout<< "Input your text: ";
	getline(cin, input);

	string compressed = compress_str(input);
	cout << "Compressed: " << compressed;
	

	return 0;
}
