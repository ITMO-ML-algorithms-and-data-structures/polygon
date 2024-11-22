#include <iostream>
#include <random>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> sample(int size, int new_size, vector<int> arr) {
	vector<int> new_arr(new_size); // O(1)
	
	for (int i = 0; i < new_size; i++) {
		int ind = (rand() % (size - i) + i) % size; // O(1) * 11  
		new_arr[i] = arr[ind]; // O(1) * 2
		swap(arr[ind], arr[i]); // O(3) + O(1) + O(1)
	}
	return new_arr;
	// Имеем ~O(18 * n) = O(n)

}

void test() {
	long int n = pow(10, 9);
	vector<int> arr(n);
	for (long int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	vector<vector<int>> tests = { { 1, 2, 10, 100, 11109 }, { 1, 2, 3 } };
	vector<vector<long int>> sizes = { {5, 3}, {3, 2}, {(long int) n, 5} };
	vector<vector<int>> right_answers = { {11109, 1, 100}, { 1, 3 }, {0, 0, 0, 0, 0} };
	tests.push_back(arr);
	for (int i = 0; i < size(tests); i++) {
		assert(sample(sizes[i][0], sizes[i][1], tests[i]) == right_answers[i]);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// Чтение названия файла, который нужно прочитать
	string line;
	string path{};
	cin >> path;
	ifstream in(path);

	srand(1234545);
	// test();

	srand((unsigned int)time(NULL));
	
	// Применяем алгоритм к заданному набору данных
	vector<int> sp{};
	int n{};
	if (in.is_open())
	{
		int c = 0;
		while (getline(in, line)) {
			vector<string> tokens;
			istringstream iss(line);
			string token;

			while (iss >> token) {
				tokens.push_back(token);
			}

			for (const auto& t : tokens) {
				if (c == 0) {
					sp.push_back(stoi(t));
				}
				else { n = stoi(t); }
			}
			c++;
		}
	}
	else cout << "Неверное наименование файла";
	in.close();
	vector<int> arr = sample(size(sp), n, sp);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}
}