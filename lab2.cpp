// Объявление необходимых заголовков
#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// читаем файл + добавляем чиселки в мн-во
void read_file(const char* filename, set<unsigned long long>& uniqueValues) {
    ifstream file(filename, ios_base::in); // открываем файл для чтения
    
    if (!file.is_open()) { // проверяем на успешное открытие файла
        cerr << "fail ne otkrilsya((" << endl;
        return;
    }

    string line; // переменная для хранения одной строки файла (ее вес неизвестен тк варьируется от входного файлика)
    
    while (getline(file, line)) { // читаем строки
        for (size_t i = 0; i < line.length(); ++i) { // удаляю все запятые за (O(n*k), k=колво линий, n = длина каждой строки)
            if (line[i] == ',') {
                line = line.replace(i, 1, ""); // убираем запятую за O(line.lenght())
            }
        }

        istringstream ss(line); 
        unsigned long long number; // 8bite

        while (ss >> number) { // 
            uniqueValues.insert(number); // O(1)
        }
    }

    file.close(); 
}

int main() {
    set<unsigned long long> uniqueValues; // мнво чиселок
    read_file("test.txt", uniqueValues); // чтение файла и заполнение множества

    vector<unsigned long long> result; // массив вывод

    for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) { // заполняем массив за O(n)
        result.push_back(*it); // O(1)
    }

    for (int i = 0; i<result.size();i++) { // O(n), где n = result.size()
        if (i < result.size()-1) {
            cout << result[i] << ", "; //O(1)
        } else {
            cout << result[i]; //O(1)
        }
    }
    return 0;
}
