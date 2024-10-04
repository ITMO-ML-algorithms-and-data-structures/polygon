#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <cassert>

using namespace std;


bool isomorph(string str, int len) {
	//создаём словари для выстраивания взамосвязи между буквами слов в обе стороны
	// (буквам первого слова - буквы второго, а буквам второго - буквы первого)
	unordered_map<char, char> hashTable_straight, hashTable_back; // + 80 * 2 байт
	string a{}, b{}; // + 40 * 2 байт
	bool flag = 0; // + 1 байт
	int len1{}, len2{}; // + 4 байта
	// делим строку на два слова и записываем их в a и b, также считаем их длины
	for (int i = 0; i < len; i++) { // O(n)
		// + 4 байта
		if (str[i] == ' ') flag = 1;
		if (flag == 0 and str[i] != ' ') {
			a += str[i];
			len1 += 1;
		}
		else if (str[i] != ' ') {
			b += str[i];
			len2 += 1;
		}
	}
	// проверка на непустоту и соответствие длин слов
	if ((len1 == len2) && (len1 != 0)) { 
		// O(n)
		// присваиваем каждой букве первого слова букву второго, а уже в другом словаре каждой букве второго слова букву первого
		string result_straight{}, result_back{}; // + 40 * 2 байт
		for (int k = 0; k < len1; k++) {
			// + 4 байта
			hashTable_straight[a[k]] = b[k];
			hashTable_back[b[k]] = a[k];
		}
		// пытаемся сконвертировать исходные слова друг в дуга
		for (int j = 0; j < len2; j++) {
			// + 4 байта
			result_straight += hashTable_straight[a[j]];
			result_back += hashTable_back[b[j]];
		}
		// если получилось, значит связь выстроена, слова изоморфны
		if (result_straight == b && result_back == a) return true;
		else return false;
	}
	else return false;
}


// Простые тесты на работоспособность программы + на взаимодействие с кириллицей
void test() {
	string tests[] = { "odd egg", "jar marck", "train lococ", "paper title", "foo bar", "bar foo", "??? !!!", "000 115", "-==+ door" };
	int right_answers[] = { 1, 0, 0, 1, 0, 0, 1, 0, 1 };
	for (int i = 0; i < size(tests); i++) {
		assert(isomorph(tests[i], size(tests[i])) == right_answers[i]);
	}
}


void main() {
	// Чтобы кириллица нормально выводилась
	setlocale(LC_ALL, "Russian");
	
	// Подготовка файла для вывода результата
	string line;
	ofstream out;
	out.open("result.txt");
	
	// Чтение названия файла, который нужно прочитать
	string path{};
	cin >> path;
	ifstream in(path);
	// Запускаем тесты, чтобы предупредить в случае чего крах программы
	test();

	cout.setf(std::ios_base::boolalpha);
	// Построчно применяем алгоритм к заданному набору данных
	if (in.is_open())
	{
		cout << "Результат записан в result.txt\n";
		while (getline(in, line))
		{
			// Выводим результат в консоль, записываем в файл
			out << boolalpha << (isomorph(line, size(line)) == true) << endl;
			cout << (isomorph(line, size(line)) == true) << "\n";
		}
	}
	else cout << "Неверное наименование файла";
	in.close();
	out.close();
}