#include<iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <limits>
#include <Windows.h>
#include <cassert>

using namespace std;

vector <vector <int>> CountVectorizer(int count_strings, vector<string> strings_enter) {

	int count_unique_words = 0;
	unordered_map <string, int> unique_words;

	//cout << "Size of count_unique_words: " << sizeof(count_unique_words) << endl; // 4 bytes
	//cout << "Size of unique_words: " << sizeof(unique_words) << endl; // 80 bytes + count_unique_words * (4 + 40)

	//Заполняем наш словарь уникальными словами
	for (int i = 0; i < count_strings; i++) {
		stringstream ss(strings_enter[i]);
		string word; 
		//cout << "Size of word: " << sizeof(word) << endl; // 40 bytes

		while (ss >> word) {
			if (unique_words.find(word) == unique_words.end()) {
				unique_words[word] = count_unique_words;
				count_unique_words++;
			}
		}
	}

	vector <vector<int>> result(count_strings, vector<int>(count_unique_words, 0));

	//cout << "Size of result: " << sizeof(result) << endl; // 32 bytes + count_unique_words * count_strings * 4

	//Считывание всех слов из строк заново и заполнение дв.массива
	for (int i = 0; i < count_strings; i++) {
		stringstream ss(strings_enter[i]);
		string word;

		while (ss >> word) {
			result[i][unique_words[word]] += 1;
		}
	}

	return result;
}

//Проводим тесты
void test_CountVectorizer() {

    vector<string> input1 = {"hello hello mama", "mama hello dad"};
    vector<vector<int>> expected_output1 = {{2, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result1 = CountVectorizer(2, input1);
    assert(result1 == expected_output1); 

    vector<string> input2 = {"I love u", "u love", "love I u ?"};
    vector<vector<int>> expected_output2 = {{1, 1, 1, 0}, {0, 1, 1, 0},{1, 1, 1, 1}};
    vector<vector<int>> result2 = CountVectorizer(3, input2);
    assert(result2 == expected_output2);

	vector<string> input3 = {"I love itmo"};
    vector<vector<int>> expected_output3 = {{1, 1, 1}};
    vector<vector<int>> result3 = CountVectorizer(1, input3);
    assert(result3 == expected_output3);

}


int main() {
	int count_strings;
	cin >> count_strings;
	cin.ignore(1000, '\n');
	vector <string> strings_enter(count_strings);

	//cout << "Size of count_strings: " << sizeof(count_strings) << endl; // 4 bytes
	//cout << "Size of string: " << sizeof(string) << endl; // 40 bytes
	//cout << "Size of strings_enter: " << sizeof(strings_enter) << endl; // 32 bytes + count_strings * 40

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Считывание строк в strings_enter
	for (int i = 0; i < count_strings; i++) {
		string input;
		getline(cin, input);
		if (input == "" | input==" ") {
			return 0;
		}
		strings_enter[i] = input;

	}

	vector<vector<int>> result = CountVectorizer(count_strings, strings_enter);

	//Вывод нашего двумерного массива result
	for (int i = 0; i < count_strings; i++) {
		for (int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	test_CountVectorizer();
	return 0;
	// Итого: наша программа расходует 4 + 4 + 32 + count_strings * 40 + 80 + count_unique_words * (4 + 40) + 40 + 32 + count_unique_words * count_strings * 4
	// = 192 + count_strings * 40 + count_unique_words * 44 + count_unique_words * count_strings * 4 bytes
}