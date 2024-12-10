#include <iostream> 
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

vector<int> beadSort(vector<int> a, int len) 
{
	int max = a[0]; 
	for (int i = 1; i < len; i++) { 
		if (a[i] > max) { 
			max = a[i]; 
		} 
	} 

	vector<vector<int>> beads;
	beads.resize(len);
	for (int i = 0; i < len; i++) {
		beads[i].resize(max);
		fill(beads[i].begin(), beads[i].end(), 0);
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < a[i]; j++) {
			beads[i][j] = 1;
		}
	}

	for (int j = 0; j < max; j++) {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += beads[i][j];
			beads[i][j] = 0;
		} 
		for (int i = len-1; i >= len - sum; i--) { 
			beads[i][j] = 1;
		} 
	} 

	vector<int> result;
	result.resize(len);
	for (int i = 0; i < len; i++) {
		int sum = 0;
		for (int j = 0; j < max; j++) {
			sum += beads[i][j];
		}
		result[i] = sum;
	}
	return result;
}

int main()
{
	ifstream inputFile("C:/Users/mosko/PycharmProjects/h/f.txt");

    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
		return 1;
    }
    
    vector<int> a;
    int value;
	
	// Считывание данных из файла
    while (inputFile >> value) {
        a.push_back(value);
    }
    
    inputFile.close();
	
	// Проверка, что вектор не пуст
    if (a.empty()) {
        cerr << "Ошибка: файл пуст!" << endl;
        return 1;
    }

	auto start = high_resolution_clock::now();
    
	vector<int> result = beadSort(a, a.size()); // Сортировка

	auto end = high_resolution_clock::now();

	duration<double> duration_sec = end - start;

	// Вывод времени выполнения
	cout << "\nВремя выполнения: " << duration_sec.count() << " секунд" << endl;

    return 0;
}