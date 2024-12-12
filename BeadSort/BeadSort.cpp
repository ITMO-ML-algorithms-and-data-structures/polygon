#include <iostream> 
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

void beadSort(vector<int>& a) {
    int max = *max_element(a.begin(), a.end());
    vector<vector<int>> beads(a.size(), vector<int>(max, 0));

    for (size_t i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i]; j++) {
            beads[i][j] = 1;
        }
    }

	for (int j = 0; j < max; j++) {
        int sum = 0;
        for (size_t i = 0; i < a.size(); i++) {
            sum += beads[i][j];
            beads[i][j] = 0;
        }
        for (size_t i = a.size() - sum; i < a.size(); i++) {
            beads[i][j] = 1;
        }
    }

	for (size_t i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = 0; j < max; j++) {
            sum += beads[i][j];
        }
        a[i] = sum;
    }
}

// int main()
// {
// 	ifstream inputFile("E:/СLabs/lab1/polygon/generatea/f.txt");

//     if (!inputFile) {
//         cerr << "Ошибка: не удалось открыть файл!" << endl;
// 		return 1;
//     }
    
//     vector<int> a;
//     int value;
	
// 	// Считывание данных из файла
//     while (inputFile >> value) {
//         a.push_back(value);
//     }
    
//     inputFile.close();

// 	cout << "Размер массива: " << a.size() << endl;
	
// 	// Проверка, что вектор не пуст
//     if (a.empty()) {
//         cerr << "Ошибка: файл пуст!" << endl;
//         return 1;
//     }

// 	auto start = high_resolution_clock::now();
    
// 	vector<int> result = beadSort(a, a.size()); // Сортировка

// 	auto end = high_resolution_clock::now();

// 	duration<double> duration_sec = end - start;

// 	// Вывод времени выполнения
// 	cout << "\nВремя выполнения: " << duration_sec.count() << " секунд" << endl;

//     return 0;
// }