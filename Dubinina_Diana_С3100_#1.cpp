#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main()
{
	std::unordered_map<std::string, int> frequencyMap; // счетчик числа вхождений строки
	
	// принимаем размер массива и сам массив
	int size;
	std::cin >> size;
	std::vector<std::string> arr(size);
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];

	// считаем количество вхождений каждой строки
	for (int i = 0; i < size; i++)
		frequencyMap[arr[i]]++;

	// меняем значения в массиве на число вхождений согласно условию
	for (int i = 0; i < size; i++)
		arr[i] = std::to_string(frequencyMap[arr[i]]);

	/*
	функция std::to_string принимает число целочисленного или вещественного типа и преобразует его в std::string
	*/

	// выводим ответ
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';

	return 0;
}
