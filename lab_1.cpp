// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int i, c = 0, l = 0;
	string max = "2147483647";
	string d = "";
	cout << "Введиде колличество элементов в массиве (до 1000)";
	cin >> i;
	if (i <= 0)
	{
		cout << "Ты дурак или да. Введи число больше 0";
		cin >> i;
	}
	cout << "Отлично, теперь введите данные в масcив (числа должны быть меньше 2147483647)";
	int* arr = new int[1000];
	for (c; c < i; c++)
	{
		cin >> d;
		while ((d.size() > max.size()) or ((d > max) & (d.size() == max.size())))
		{
			cout << "Введи нормальное число";
			cin >> d;
		}
		int k{ std::stoi(d) };
		arr[c] = k;
	}

	for (int m = 0; m < i; m++)
	{
		if (arr[m] % 3 == 0 and arr[m] != 0)
		{
			l++;
		}
	}
	cout << l;
}


