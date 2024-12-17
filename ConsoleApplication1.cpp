#include <iostream>
#include <cassert>
#include<iomanip>
#include <chrono>
#include <vector>

void Bubble_sort(std::vector<int>& vector)
{
	for (int i = 0; i < size(vector); i++) // O(n)
	{
		for (int j = 0; j < size(vector) - 1; j++) // O(n)
		{
			if (vector[j] > vector[j + 1]) // O(1)
			{
				int b = vector[j + 1]; // 4 байта
				vector[j + 1] = vector[j];
				vector[j] = b;
			}
		}
	}
}

void test()
{
	std::vector<int> vector1, vector_1, vector2, vector_2, vector3, vector_3;
	vector1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector3 = { 2, 3, 6, 1, 4, 7, 8, 9, 10, 5 };
	vector_3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Bubble_sort(vector1);
	Bubble_sort(vector2);
	Bubble_sort(vector3);
	for (int i = 0; i < 10; i++)
	{
		assert(vector1[i] == vector_1[i]);
		assert(vector2[i] == vector_2[i]);
		assert(vector3[i] == vector_3[i]);
	}
}

void test_for_time()
{
	time_t start, end;
	std::vector<int> vector; // 40 байт
	int k = 0;
	while (k < 50)
	{
		k += 1;
		// O(n)
		for (int i = 0; i < 1000; i++) {
			int l = rand();
			vector.push_back(l); // "читаем" элементы в массив
		}
		//std::cout << "asdad";
		auto start_time = std::chrono::steady_clock::now();
		Bubble_sort(vector);
		auto end_time = std::chrono::steady_clock::now();
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>((end_time - start_time));
		std::cout << elapsed_ns.count() << " \n";
	}
}
int main()
{
	//test_for_time();
	//time_t start, end;
	test();
	std::vector<int> vector; // 40 байт
	setlocale(LC_ALL, "Russian");
	std::cout << "Создаем пузырьковую сортировку";
	std::cout << "\n";
	// O(n)
	int l; // 4 байта
	for (int i = 0; i < 1000; i++) { // O(n)
		l = rand(); 
		vector.push_back(l); // "читаем" элементы в массив
	}
	Bubble_sort(vector);
	for (int i = 0; i < size(vector); i++) // O(n)
	{
		std::cout << vector[i] << "\n";
	}
	std::cout << "end";
	return 0;
}

