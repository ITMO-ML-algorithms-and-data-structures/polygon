#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>

//Перемешивание элементов массива
std::vector<int> shuffle_array(std::vector<int> vec) {
	srand(time(NULL)); 
	for (int i = vec.size() - 1; i > 0; i--){	//O(n-1) перебор элементов с конца, кроме первого
		int j = rand() % i;						//О(1) генерация рандомного индекса для второго элемента
		std::swap(vec[i], vec[j]);		//О(1) поменять местами элементы массива
	}
	return vec;

	//Общая сложность алгоритма О(n-1)
}

std::vector<int> read_txt(std::string path) {
	std::vector<int> arr;
	std::string line;
	std::ifstream file(path);
	if (file.is_open())							//Проверка открыт ли файл
	{
												//Перебор строк в файле
		while (std::getline(file, line, '\n'))
		{
												//Добавление строк в вектор
			arr.push_back(std::stoi(line));
		}
	}
	file.close();
	return arr;
}
void test() {
	srand(time(NULL));
												//Массив с маленьким количеством элементов
	std::vector<int> test_kit_1 = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> test_kit_2 = {};			//Проверка на пустой массив
	std::vector<int> test_kit_3 = { 1 };		//Проверка, когда  в массиве 1 элемент
												//Массив с количеством элементов 10**6
	std::vector<int> test_kit_4 = read_txt("C:/Leonid/ITMO/АЛГиСД/home_dir_labs/lab3/test_mas.txt");
	assert(shuffle_array(test_kit_1) != test_kit_1);
	assert(shuffle_array(test_kit_2) == test_kit_2);
	assert(shuffle_array(test_kit_3) == test_kit_3);
	assert(shuffle_array(test_kit_4) != test_kit_4);
}

int main() {
	test();
	return 0;
}