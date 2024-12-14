#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

#define N 10000          // максимальный размер вектора
#define ABSLIMIT 100000  // предел значений элементов массива

#define SORT__ODD_EVEN 1
#define SORT__MERGING  2
#define SORT__COUNTING 3

std::vector<std::string> sort_names = { "", "Odd_Even_Sort", "Merge_Sort", "Counting_Sort" };

void print_vector(const std::vector<int>& mas, const std::string msg) {
	int n = 0;

	std::cout << msg << "\nSize: " << mas.size() << "\n";

	for (int num : mas) {
		std::cout << num << " ";
		n++;
		if (n > 20) {
			std::cout << "...";
			break;
		}
	}
}


std::vector<int> Odd_Even_Sort( std::vector<int>& mas, int& coun ) {
	int n = mas.size();
	int isSorted = 0;
	coun += sizeof(n) + sizeof(isSorted);

	while (isSorted == 0) {
		isSorted = 1;
		for (int i = 1; i < n - 1; i += 2) {
			if (mas[i] > mas[i + 1]) {
				std::swap(mas[i], mas[i + 1]);
				isSorted = 0;
			}
		}
		for (int i = 0; i < n - 1; i += 2) {
			if (mas[i] > mas[i + 1]) {
				std::swap(mas[i], mas[i + 1]);
				isSorted = 0;
			}
		}
	}
	
	// coun = sizeof(n) + sizeof(isSorted);
	// std::cout << coun << "\n";

	return mas;
}


std::vector<int> Merge_Sort(std::vector<int>& mas, int& coun) {
	if (mas.size() <= 1) {
		return mas;
	}

	std::vector<int> lmas(mas.begin(), mas.begin() + mas.size() / 2);
	std::vector<int> rmas(mas.begin() + mas.size() / 2, mas.end());
	coun += sizeof(lmas) + sizeof(rmas);

	lmas = Merge_Sort(lmas, coun);
	rmas = Merge_Sort(rmas, coun);

	int n = 0, m = 0, k = 0;
	coun += sizeof(n) + sizeof(m) + sizeof(k);
	std::vector<int> pob_mas(mas.size());
	coun += sizeof(pob_mas);

	while (n < lmas.size() && m < rmas.size()) {
		if (lmas[n] <= rmas[m]) {
			pob_mas[k] = lmas[n];
			n++;
		}
		else {
			pob_mas[k] = rmas[m];
			m++;
		}
		k++;
	}

	while (n < lmas.size()) {
		pob_mas[k] = lmas[n];
		n++;
		k++;
	}

	while (m < rmas.size()) {
		pob_mas[k] = rmas[m];
		m++;
		k++;
	}

	for (size_t i = 0; i < mas.size(); i++) {
		mas[i] = pob_mas[i];
	}

	return mas;
}


std::vector<int> Counting_Sort( const std::vector<int>& mas3, int& coun ) {
	int maxElement = *std::max_element(mas3.begin(), mas3.end());
	int countArrayLength = maxElement + 1;
	coun += sizeof(maxElement) + sizeof(countArrayLength);
	
	std::vector<int> countArray(countArrayLength, 0);
	coun += sizeof(countArray);
	
	for (int el : mas3) {
		countArray[el]++;
	}
	
	for (int i = 1; i < countArrayLength; i++) {
		countArray[i] += countArray[i - 1];
	}
	
	std::vector<int> outputArray(mas3.size());
	int i = mas3.size() - 1;
	coun += sizeof(outputArray) + sizeof(i);
	while (i >= 0) {
		int currentEl = mas3[i];
		countArray[currentEl]--;
		int newPosition = countArray[currentEl];
		outputArray[newPosition] = currentEl;
		i--;
	}

	return outputArray;
}


// функция генерации случайного числа из диапазона от range_min до range_max включительно
int rrand(int range_min, int range_max) {
	return rand() % (range_max - range_min + 1) + range_min;
}


std::vector<int> Create_Massiv(int size, int limit_1, int limit_2) {
	std::vector<int> mas;
	int min_value, max_value;

	srand(static_cast<unsigned int>(time(NULL)));

	if (limit_1 < limit_2) {
		min_value = limit_1;
		max_value = limit_2;
	}
	else {
		min_value = limit_2;
		max_value = limit_1;
	}
	// инициализация массива случайными значениями из диапазона -ABSLIMIT..ABSLIMIT
	for (unsigned int i = 0; i < size; i++)
		mas.push_back(rrand(min_value, max_value));

	return mas;
}


std::vector<int> Test_Sort(int size, int sort_code) {
	std::vector<int> res = {0, 0, 0, 0, 0, 0};  // 0 - размер памяти, времена: 1 - начало теста, 2 - создание, 3 - печать1, 4 - сортировка, 5 - печать2/завершение
	std::vector<int> sorted_mas;
	int mem_sz;

	res[0] = sizeof(res);
	res[1] = clock();
	std::vector<int> mas = Create_Massiv(size, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	res[2] = clock();
	print_vector(mas, "\n" + sort_names[sort_code] + ":");
	res[3] = clock();
	switch(sort_code) {
	    case SORT__ODD_EVEN:
			sorted_mas = Odd_Even_Sort(mas, mem_sz);
			break;
		case SORT__MERGING:
			sorted_mas = Merge_Sort(mas, mem_sz);
			break;
		case SORT__COUNTING:
			sorted_mas = Counting_Sort(mas, mem_sz);
			break;
		default:
			break;
	}
	res[0] += mem_sz;
	res[4] = clock();
	print_vector(sorted_mas, "");
	res[5] = clock();
	std::cout << (res[4] - res[3]) << "\n";

	return res;
}


void update_stat(std::vector<int>& stat, std::vector<int>& stat1, int sort_index) {
	stat[0] += stat1[0];
	stat[1] += (stat1[5] - stat1[1]);
	stat[2] += (stat1[2] - stat1[1]);
	stat[3] += (stat1[3] - stat1[2] + stat1[5] - stat1[4]);
	stat[4] += (stat1[4] - stat1[3]);
	stat[sort_index] += (stat1[4] - stat1[3]);
}


int main() {
//	int coun = 0;
	std::vector<int> stat = { 0, 0, 0, 0, 0, 0, 0, 0 };  // 0 - размер памяти, времена: 1 - общее время, 2 - создание, 3 - печать, 4 - сортировка, 5 - ODD_EVEN, 6 - MERGE, 7 - COUNTING
	std::vector<int> stat_test;  // 0 - размер памяти, времена: 1 - начало теста, 2 - создание, 3 - печать1, 4 - сортировка, 5 - печать2/завершение
	std::vector<int> stat_1;
	std::vector<int> stat_2;
	std::vector<int> stat_3;

	for (int size = 1000; size <= 10000; size += 1000) {
		stat_test = Test_Sort(size, SORT__ODD_EVEN);
		update_stat(stat, stat_test, 5);
		stat_1.push_back(stat_test[4] - stat_test[3]);

		stat_test = Test_Sort(size, SORT__MERGING);
		update_stat(stat, stat_test, 6);
		stat_2.push_back(stat_test[4] - stat_test[3]);

		stat_test = Test_Sort(size, SORT__COUNTING);
		update_stat(stat, stat_test, 7);
		stat_3.push_back(stat_test[4] - stat_test[3]);
	}

/*
	std::vector<int> mas_1 = Create_Massiv(1000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_1, "\nOdd_Even_Sort:");
	int t_1 = clock();
	std::vector<int> sortedmas_1 = Odd_Even_Sort(mas_1, coun);
	print_vector(sortedmas_1, "");
	std::cout << t_1 << "\n";
	
	std::vector<int> mas_2 = Create_Massiv(2000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_2, "\nOdd_Even_Sort:");
	int t_2 = clock();
	std::vector<int> sortedmas_2 = Odd_Even_Sort(mas_2, coun);
	print_vector(sortedmas_2, "");
	std::cout << t_2 << "\n";

	std::vector<int> mas_3 = Create_Massiv(3000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_3, "\nOdd_Even_Sort:");
	int t_3 = clock();
	std::vector<int> sortedmas_3 = Odd_Even_Sort(mas_3, coun);
	print_vector(sortedmas_3, "");
	std::cout << t_3 << "\n";

	std::vector<int> mas_4 = Create_Massiv(4000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_4, "\nOdd_Even_Sort:");
	int t_4 = clock();
	std::vector<int> sortedmas_4 = Odd_Even_Sort(mas_4, coun);
	print_vector(sortedmas_4, "");
	std::cout << t_4 << "\n";

	std::vector<int> mas_5 = Create_Massiv(5000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_5, "\nOdd_Even_Sort:");
	int t_5 = clock();
	std::vector<int> sortedmas_5 = Odd_Even_Sort(mas_5, coun);
	print_vector(sortedmas_5, "");
	std::cout << t_5 << "\n";

	std::vector<int> mas_6 = Create_Massiv(6000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_6, "\nOdd_Even_Sort:");
	int t_6 = clock();
	std::vector<int> sortedmas_6 = Odd_Even_Sort(mas_6, coun);
	print_vector(sortedmas_6, "");
	std::cout << t_6 << "\n";

	std::vector<int> mas_7 = Create_Massiv(7000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_7, "\nOdd_Even_Sort:");
	int t_7 = clock();
	std::vector<int> sortedmas_7 = Odd_Even_Sort(mas_7, coun);
	print_vector(sortedmas_7, "");
	std::cout << t_7 << "\n";

	std::vector<int> mas_8 = Create_Massiv(8000, rrand(0, ABSLIMIT), rrand(0, ABSLIMIT));
	print_vector(mas_8, "\nOdd_Even_Sort:");
	int t_8 = clock();
	std::vector<int> sortedmas_8 = Odd_Even_Sort(mas_8, coun);
	print_vector(sortedmas_8, "");
	std::cout << t_8 << "\n";

	coun += sizeof(mas_1) + sizeof(mas_2) + sizeof(mas_3) + sizeof(mas_4) + sizeof(mas_5) + sizeof(mas_6) + sizeof(mas_7) + sizeof(mas_8);
	coun += sizeof(sortedmas_1) + sizeof(sortedmas_2) + sizeof(sortedmas_3) + sizeof(sortedmas_4) + sizeof(sortedmas_5) + sizeof(sortedmas_6) + sizeof(sortedmas_7) + sizeof(sortedmas_8);
*/
	std::cout << "\nUsing memory: " << (stat[0] + sizeof(stat) + sizeof(stat_test) + sizeof(stat_1) + sizeof(stat_2) + sizeof(stat_3)) << " bt";
	for (int i = 0; i < 10; i++) {
		std::cout << "\n" << (i + 1) * 1000
			<< "\t" << stat_1[i] << "\t" << stat_2[i] << "\t" << stat_3[i]
		    << "\t" << ((float)stat_1[i]) / CLOCKS_PER_SEC << "\t" << ((float)stat_2[i]) / CLOCKS_PER_SEC << "\t" << ((float)stat_3[i]) / CLOCKS_PER_SEC;
	}
	return 0;
}