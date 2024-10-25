// Проверить строки на изоморфность. Символы A-Za-zА-Яа-я0-9, до 10000 символов в каждой строке

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

bool are_isomorph(std::string& line_1, std::string& line_2, std::unordered_map<char, char>& letters_bijection) {

	short int length1 = line_1.length(); // 2 байта
	short int length2 = line_2.length(); // 2 байта
	if (length2 != length1) { return false; }

	// Сравниваем длину строк, иначе, если строки имеют разную длину, программа либо выдаёт ошибку (length1 > length2), 
	// либо не проходит вторую строку полностью (length1 < length2)

	for (int i = 0; i < length1; i++) { // 24 + 2 * K байт (max K = 94, где K - количество уникальных символов в строке) или 24 + 80 байт при K <= 40

		auto search = letters_bijection.find(line_1[i]); // 24 байта
		
		// unordered_map letters хранит пары вида key = line_1[i], value = line_2[i]
		// В каждой итерации цикла проверяем, есть ли элемент line_1[i] в качестве ключа
		// в letters или нет. Если нет - создаём ключ line_1[i] со значением line_2[i],
		// есть - сравниваем значение с line_2[i]. При несовпадении, возвращаем false, т.к. биекция будет нарушена
		if (search != letters_bijection.end()) {
			if (search->second != line_2[i]) {
				return false;
			}
		}
		else {
			letters_bijection.insert({ line_1[i], line_2[i] });
		}
	}

	return true;
}
// итоговые затраты памяти (самой функцией): 2 + 2 + max(2*K, 80) + 24 = max(2*K, 80) + 28 байт
// итоговые затраты памяти в целом: max(N,80) + max(M, 80) + 2 + 2 + max(2*K, 80) + 24 = max(N,80) + max(M, 80) + max(2*K, 80) + 28 байт (Где N и M - длины строк)

int main() {
	// Тест из примера
	std::string line_11{ "foo" }, line_21{ "dff" };
	std::unordered_map<char, char> letters_bijection1;
	assert(are_isomorph(line_11, line_21, letters_bijection1) == 1);

	// Тест с неизоморфными строками
	std::string line_12{ "foo" }, line_22{ "dfd" };
	std::unordered_map<char, char> letters_bijection2;
	assert(are_isomorph(line_12, line_22, letters_bijection2) == 0);

	// Тест со строками разной длины (a > b)
	std::string line_13{ "food" }, line_23{ "dff" };
	std::unordered_map<char, char> letters_bijection3;
	assert(are_isomorph(line_13, line_23, letters_bijection3) == 0);

	// Тест со строками разной длины (a < b)
	std::string line_14{ "foo" }, line_24{ "dfff" };
	std::unordered_map<char, char> letters_bijection4;
	assert(are_isomorph(line_14, line_24, letters_bijection4) == 0);

	// Тест с пустыми строками
	std::string line_15{ "" }, line_25{ "" };
	std::unordered_map<char, char> letters_bijection5;
	assert(are_isomorph(line_15, line_25, letters_bijection5) == 1);

	// Тест с изоморфными строками, содержащими все допустимые символы
	std::string line_16{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбю" };
	std::string line_26{ "юqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьб" };
	std::unordered_map<char, char> letters_bijection6;
	assert(are_isomorph(line_16, line_26, letters_bijection6) == 1);

	// Тест с неизоморфными строками, содержащими все допустимые символы
	std::string line_17{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбю" };
	std::string line_27{ "юqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjkldfcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьб" };
	std::unordered_map<char, char> letters_bijection7;
	assert(are_isomorph(line_17, line_27, letters_bijection7) == 0);

	std::cout << "All tests completed successfully" << std::endl;
}