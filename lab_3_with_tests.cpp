// решение задачи сложности медиум
// сжать строку, заменяя последовательности одинаковых символов их количеством символов

// в этот раз попробовал ссылки для экономии памяти (не судите строго, первый опыт, но вроде норм)

#include <iostream>
#include <string>
#include <cassert>
using namespace std;


void turbo_super_zip_3000(string& input_str, string& result_str) {
	unsigned short int input_string_length = input_str.length(); // длина строки, вес 2 байта, не может превысить 10000 по условию
	unsigned short int repeats_counter = 1; // 2 байта, считаем, сколько раз уже повторился текущий символ

	for (int i = 1; i < input_string_length; i++) { // O(n)
		if (input_str[i - 1] == input_str[i]) { // O(1)
			repeats_counter++;
		}
		else {
			result_str = result_str + input_str[i - 1] + to_string(repeats_counter); // O(1)
			repeats_counter = 1;
		}
	}
	result_str = result_str + input_str[input_string_length - 1] + to_string(repeats_counter); // O(1)
}


void tests() {
	string input_1 = "гоооооооооол";
	string output_1;
	string excepted_1 = "г1о10л1";
	turbo_super_zip_3000(input_1, output_1);
	assert(output_1 == excepted_1);
	cout << "Test 1 - success" << endl;

	string input_2 = "ii llloooovee c++";
	string output_2;
	string excepted_2 = "i2 1l3o4v1e2 1c1+2";
	turbo_super_zip_3000(input_2, output_2);
	assert(output_2 == excepted_2);
	cout << "Test 2 - success" << endl;

	string input_3 = "abcdcbaxyz"; // крайний случай, когда повторений подряд нет
	string output_3;
	string excepted_3 = "a1b1c1d1c1b1a1x1y1z1";
	turbo_super_zip_3000(input_3, output_3);
	assert(output_3 == excepted_3);
	cout << "Test 3 - success" << endl;

	string input_4 = "aaaaaaaaaaa"; // крайний случай, когда все символы равны
	string output_4;
	string excepted_4 = "a11";
	turbo_super_zip_3000(input_4, output_4);
	assert(output_4 == excepted_4);
	cout << "Test 4 - success" << endl;
}


int main() {
	tests();

	string input_string;
	string result_string; // тут будет результирующая строка собираться
	getline(cin, input_string); // вес n+1 байт, т.к. каждый символ весит 1 байт и еще 1 байт приходится на нулевой символ
	turbo_super_zip_3000(input_string, result_string);
	cout << result_string << endl;
	
	return 0;
}

