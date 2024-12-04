#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

// Функция Counting Sort
void countingSort(const std::vector<int>& arr, std::vector<int>& sorted_arr);

// Функция QuickSort
void quicksort(std::vector<int>& arr, int low, int high);

// Функция Cocktail Sort
void CoctailSort(std::vector<int>& arr);

#endif // SORT_ALGORITHMS_H
