#include<iostream>
#include<unordered_map>
#include<string>
#include<cassert>
using namespace std;

vector<int> f(vector<string>& arr) { //функция подсчёта f. ВЕС 24 байта
	
	unordered_map<string, int> frequencyMap; //Создать хеш-таблицу frequencyMap. ВЕС 32 байта
	size_t f_size = arr.size(); //Переменная с размером массива f_size. ВЕС 8 байт
	vector<int> arr_out; //Массив на выход. ВЕС 24 байта
	for (int i = 0; i < f_size; i++) //ВЕС 4 байта
	{
		frequencyMap[arr[i]]++; //Каждый раз когда слово встречается, прибавляем 1 в хеш-таблицу
	}

	for (int i = 0; i < f_size; i++) { //ВЕС 4 байта
		arr_out.push_back(frequencyMap[arr[i]]); //добавлять вместо слова, полученные значения из хеш-таблицы
	}
	return arr_out;
}


void test(vector<string>& a, vector<int>& b) //Тесты для функции f. ВЕС 48 байт
{
	if (f(a) == b)
	{
		cout << "NICE!" << "\n";
	}
	else
	{
		cout << "BAD! " << "\n";
	}
}

int main() {
	//МАССИВЫ ДЛЯ ТЕСТОВ
	vector<string> test1 = { "Apple","Apple","Pineapple","Orange" }; //входной массив для первого теста. ВЕС 24 байта
	vector<int> test1_out = { 2,2,1,1 }; //итоговый массив для первого теста. ВЕС 24 байта
	vector<string> test2 = { "Orange","Green","Red","Orange" }; //входной массив для второго теста. ВЕС 24 байта
	vector<int> test2_out = { 1,2,3,4 }; //итоговый массив для второй теста. ВЕС 24 байта

	//ТЕСТЫ
	cout << "test 1: ";
	test(test1, test1_out);
	cout << "test 2: ";
	test(test2, test2_out);
	assert(f(test1) == test1_out);


	//
	vector<string> arr = { "Orange","Green","Red","Orange" }; //входной массив arr. ВЕС 24 байта
	size_t arr_size = arr.size(); //размер массивов arr_size. ВЕС 8 байт
	vector<int> arr_1 = f(arr);//итоговый массив arr_1. ВЕС 24 байта
	for (int i = 0; i < arr_size; i++) //ВЕС 4 байта
	{
		cout << arr_1[i] << " ";
	}

	return 0;
}