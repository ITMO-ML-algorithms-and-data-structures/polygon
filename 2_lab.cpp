#include <iostream>
#include <vector>
#include <map>


using namespace std;
int main() {
	int size;
	cin >> size;
	vector<string> mas(size); // 18 байт + 9 байт каждыый символ
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
	}


	map<string, int> data; // создание хэш таблицы // 48 байт
	vector<int> res = {}; // создание вектора // 24 байт + 4 байт за каждый символ
	for (string item : mas) { // цикл достает каждый элемент из mas
		if (data.find(item) == data.end()) { // ищет елемент, если его нету то возвращает data.end()
			data[item] = 1;
		}
		else {
			data[item]++;
		}
	}

	for (int i = 0; i < size; i++) { // добавляет в вывод числовое значение слова
		res.push_back(data[mas[i]]);
	}

	for (int i = 0; i < size; i++) { // вывод
		cout << res[i] << " ";
	}

	return 0;
}
