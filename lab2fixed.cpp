#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

bool are_isomorph(std::string* line_1, std::string* line_2, std::unordered_map<char, char>* saved_letters) { // 8 + 4 * 2 = 12 байт (указатели) 
	int length1 = (*line_1).size(); // 4 байта
	int length2 = (*line_2).size(); // 4 байта
	if (length2 != length1) { return false; }
	for (int i = 0; i < length1; i++) { // 24 + 2 * K байт (max K = 94, где K - количество уникальных символов в строке) или 24 + 80 байт при K <= 40
		auto search = (*saved_letters).find((*line_1)[i]); // те самые 24 байта
		if (search != (*saved_letters).end()) {
			if (search->second != (*line_2)[i]) {
				return false;
			}
		}
		else {
			(*saved_letters).insert({ (*line_1)[i], (*line_2)[i] });
		}
	}
	return true;
}
//int main(){
//	std::string line_1,line_2; // 80 байт
//	std::cin >> line_1 >> line_2; // N + M байт (max N, M = 10000, где N, M - количество символов в строках) или 80 байт при N и M <= 40
//	std::unordered_map<char, char> saved_letters; // 80 байт
//  std::cout << are_isomorph(&line_1, &line_2, &saved_letters) << std::endl;
//}

// итоговые затраты памяти: max(M+N, 80) + 16 + 4 + 4 + max(2*K, 80) + 24 = max(M+N, 80) + max(2*K, 80) + 44 байт


// Тест из примера
void TEST_1() {
	std::string line_1{ "foo" }, line_2{ "dff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// Тест с неизоморфными строками
void TEST_2() {
	std::string line_1{ "foo" }, line_2{ "dfd" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// Тест со строками разной длины (a > b)
void TEST_3() {
	std::string line_1{ "food" }, line_2{ "dff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// Тест со строками разной длины (a < b)
void TEST_4() {
	std::string line_1{ "foo" }, line_2{ "dfff" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

// Тест с пустыми строками
void TEST_5() {
	std::string line_1{ "" }, line_2{ "" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// Тест с изоморфными строками, содержащими все допустимые символы

void TEST_6() {
	std::string line_1{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбю" };
	std::string line_2{ "юqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьб" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 1);

}

// Тест с неизоморфными строками, содержащими все допустимые символы
void TEST_7() {
	std::string line_1{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбю" };
	std::string line_2{ "юqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjkldfcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890йцукенгшщзхъфывапролджэячсмитьб" };
	std::unordered_map<char, char> saved_letters;
	assert(are_isomorph(&line_1, &line_2, &saved_letters) == 0);

}

int main() {
	TEST_1();
	TEST_2();
	TEST_3();
	TEST_4();
	TEST_5();
	TEST_6();
	TEST_7();
	std::cout << "All tests completed successfully" << std::endl;
}