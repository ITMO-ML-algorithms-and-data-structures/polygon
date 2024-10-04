/*Реализовать функцию, выполняющую логику count_vectorizer
* 
На вход функция принимает набор строк с текстом произвольного размер.
На выход формирует двумерный массив, где столбцам соотвествуют уникальные слова, строкам индексов входных строк.
В пересечении строки и столбца находится кол-во встреченного слова в строке
Разделителем слов является проблел.
Слова ненужно лемматизировать
Знаки пунктуации не нужно чистить"
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <fstream>




std::vector<std::vector<short>> count_vectorizer(std::vector<std::string> arr, short size_arr) {
	/*
	arr - 32
	size_arr - 2
	matrix_count - size_arr * k + 32, где к - уникальные слова
	word - 40 (из-за windows debugger)
	row - 2
	words - 40 (из-за windows debugger)
	*/
	std::vector<std::vector<short>> matrix_count(size_arr, std::vector<short> (0)); 
	std::string words = "";
	for (short row = 0; row < size_arr; row++) { //Объединение массива строк в одну строчку с добавлением разделителя
		words += arr[row] + " || ";
	}

	std::vector<std::pair<std::string, short>> dict_words;
	std::stringstream stream_words(words);
	std::string word;
	short row = 0;
	while (stream_words >> word) {				 //Поток слов из строки
		if (word != "||")						 //Проверка на разделитель строчек
		{
												 //Проверка на нахождение нового слова в строке				 
			if (std::find_if(dict_words.begin(), dict_words.end(), 
				[&](const auto& el) {return el.first == word;}) == dict_words.end())
			{
				dict_words.push_back({word, 1});
												 //Обработка случая, когда новое слово появилось не в первой строке
				if (row > 0) {
					for (short i = 0; i < row; i++)
					{
						matrix_count[i].push_back(0);
					}
				}
			}
			else {
												 //Случай, когда найдено повторение слова
				for (short i = 0; i < dict_words.size(); i++) {
					if (dict_words[i].first == word) {
						dict_words[i].second++;
						break;
					}
				}
			}
		}
		else {									 //Обработка перехода на новую строчку 
			for (short i = 0; i < dict_words.size(); i++){
				matrix_count[row].push_back(dict_words[i].second);
				dict_words[i].second = 0;
			}
			row++;
		}
	}
	return matrix_count;
}

void test_utl()
{
	std::vector<std::string> test_kit_1 = { "Hello world ! Z Hello Y", "Hello Z", "world j", "! j" };
	short size1 = 4;
	std::vector<std::string> test_kit_2 = {};
	short size2 = 0;
	std::vector<std::string> test_kit_3 = { "???", "?" };
	short size3 = 2;
	std::vector<std::vector<short>> ret_test_kit_1 = { {2, 1, 1, 1, 1, 0},
														{1, 0, 0, 1, 0, 0},
														{0, 1, 0, 0, 0, 1},
														{0, 0, 1, 0, 0, 1} };
	std::vector<std::vector<short>> ret_test_kit_2 = {};
	std::vector<std::vector<short>> ret_test_kit_3 = { {1, 0}, {0, 1} };
	assert(count_vectorizer(test_kit_1, size1) == ret_test_kit_1);
	assert(count_vectorizer(test_kit_2, size2) == ret_test_kit_2);
	assert(count_vectorizer(test_kit_3, size3) == ret_test_kit_3);
}

std::pair<std::vector<std::string>, short> proc_txt(std::string path) {
	std::vector<std::string> arr;
	std::string line;
	std::ifstream file(path);
	short num_line = 0;
	if (file.is_open())
	{
		while (std::getline(file, line, '\n'))
		{
			arr.push_back(line);
			num_line++;
		}
	}
	file.close();
	std::pair <std::vector<std::string>, short> res (arr, num_line);
	return res;
}

int main(){
	std::pair <std::vector<std::string>, short> inp;
	inp = proc_txt("C:\\Leonid\\ITMO\\АЛГиСД\\home_dir_labs\\lab2\\test1.txt");
	std::vector<std::vector<short>> res;
	res = count_vectorizer(inp.first, inp.second);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			std::cout << res[i][j] << '\t';
		std::cout << '\n';
	}

	test_utl();
	return 0;
}	


