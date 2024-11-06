#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>


//Создаём функцию которая находит нули в функции и заменяет их наиболее встречаемым элементом
void replaceNullElements(std::vector<int>& arr) {
	std::unordered_map<int, int> frequency;
	//Создаём переменные для подсчёта максимального количества вхождений элемента и сам элемент
	int mostFrequentElement = 0;
	int max_соunt = 0;

	//Проходимся циклом по массиву
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			frequency[arr[i]]++;
			// Проверяем, является ли текущий элемент наиболее частым
			if (frequency[arr[i]] > max_соunt) {
				max_соunt = frequency[arr[i]];
				mostFrequentElement = arr[i];
			}
		}
	}
	//Проходимся циклом по массиву и заменяем нули самым встречаемым элементом
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			arr[i] = mostFrequentElement;
		}
	}
}

// Напишем тесты для проверки нашей функции

void test() {

	//Стандартный ввод
	std::vector<int> test1 = { 4,4,5,0,0,1,3,0 }; //8 эл. по 4 байта, итого 8*4=32 байта
	std::vector<int> result1 = { 4,4,5,4,4,1,3,4 };//8 эл. по 4 байта, итого 8*4=32 байта
	replaceNullElements(test1);
	//Хэш таблица содержит 5 уникальных элементов по 8 байт каждый
	//5*8=40 байт
	assert(test1 == result1);

	//Проверка если все нули
	std::vector<int> test2 = {0,0,0,0};//4 эл. по 4 байта, итого 4*4=16 байт
	std::vector<int> result2 = {0,0,0,0};//4 эл. по 4 байта, итого 4*4=16 байт
	replaceNullElements(test2);
	//Хэш таблица пустая так там только 0
	assert(test2 == result2);

	//Проверка если нет нулей
	std::vector<int> test3 = {1,2,3,1,1,1};//6 эл. по 4 байта, итого 6*4=24 байта
	std::vector<int> result3 = {1,2,3,1,1,1};//6 эл. по 4 байта, итого 6*4=24 байта
	replaceNullElements(test3);
	//Хэш таблица содержит 3 уникальных элемента по 8 байт каждый
	//8*3=24 байт
	assert(test3 == result3);

	//Проверка если несколько наиболее встречаемых элементов
	std::vector<int> test4 = {1,1,1,2,2,2,0,0};//8 эл. по 4 байта, итого 8*4=32 байта
	std::vector<int> result4 = {1,1,1,2,2,2,1,1};//8 эл. по 4 байта, итого 8*4=32 байта
	replaceNullElements(test4);
	//Хэш таблица содержи 2 уникальных элемента по 8 байт каждый
	//2*8=16 байт
	assert(test4 == result4);

	//Проверка если пустой массив
	std::vector<int> test5 = {};//Пусто
	std::vector<int> result5 = {};//Пусто
	replaceNullElements(test5);
	//Пусто
	assert(test5 == result5);

	//Всего наше программа использует 32*4+16*3+24*3+40=280 байт



}
int main() {
	test();
	std::cout << "test completed successfully";
}
