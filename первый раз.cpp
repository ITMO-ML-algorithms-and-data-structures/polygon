#include <iostream>//подключаем библиотеки и так далее
#include <vector>
#include <Windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");//для того чтобы я мог вывести по русски

	cout << "Vvedite kol elementov massiva  ";
	int n;
	cin >> n;
	vector <int> a(n);// создаем массив и дальше через цикл вводим элементы
	cout << "Vvedite massiv  ";
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mn;
	mn = INT_MAX;//максимальное число в плюсах чтобы точно небыло ошибки
	for (int i = 0; i < n; i++) {
		if (a[i] < mn) {
			mn = a[i];//сравниваем все элементы и запоминаем в переменной наименьший
		}
	}
	cout << "Минимальный элемент = " << mn;//вывод
}