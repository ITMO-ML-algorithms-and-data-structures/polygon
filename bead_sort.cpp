#include <iostream> 
#include <algorithm>
#include <vector>
#include "bead_sort.h"

std::vector<int> bead_sort(std::vector<int> a, int len) { 
	// Максимальный элемент
	int max = a[0]; 
	for (int i = 1; i < len; i++) { 
		if (a[i] > max) { 
			max = a[i]; 
		} 
	} 

	// Выделение места для бусин
	std::vector<std::vector<int>> beads;
	beads.resize(len); 
	for (int i = 0; i < len; i++) {
		beads[i].resize(max);
		std::fill(beads[i].begin(), beads[i].end(), 0); // массив заполняется нулями
	}

	// Помечаем бусины
    // Мы "визуализируем" бусины для каждого элемента из массива
	for (int i = 0; i < len; i++) { 
		for (int j = 0; j < a[i]; j++) { 
			beads[i][j] = 1; 
		} 
	} 

	// Перемещаем бусины вниз
    // Мы снова "визуализируем", но уже падения бусин
	for (int j = 0; j < max; j++) { 
		int sum = 0; // Счет количества буссин в столбце j
		for (int i = 0; i < len; i++) { 
			sum += beads[i][j]; 
			beads[i][j] = 0; 
		} 
        // "Перемещаем" бусини вниз
		for (int i = len-1; i >= len-sum; i--) { 
			beads[i][j] = 1; 
		} 
	} 

	// Получение отсортированного массива
	std::vector<int> result;
	result.resize(len);
    // Счет количества бусин в каждом столбце (суммируем все элементы в строке)
	for (int i = 0; i < len; i++) { 
		int sum = 0; 
		for (int j = 0; j < max; j++) { 
			sum += beads[i][j]; 
		} 
		result[i] = sum; 
	} 
    // Получаем отсортированное значение 
	return result; 
} 
