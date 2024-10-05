#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    cout << "hello, world" << endl;
    std::vector<int> mas;
    fstream fileInput;
    try
    {
        fileInput.open("/Users/mir/Documents/ITMO C++/Algos/lab test/lab test/dataset.txt");
        
        std::string row;
        while(!fileInput.eof())
        {
            getline(fileInput, row);
            mas.push_back(stoi(row));
        }
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }

    // Вывод исходного массива
    cout << "Исходный массив: ";
    for (int num: mas) {
        cout << num << " ";
    }
    cout << endl;

    // Массив для хранения уникальных значений
    vector<int> new_mas;

    // Проходим по исходному массиву
    for (int i = 0; i < mas.size(); i++) {
        bool is_duplicate = false;

        // Проверяем, есть ли уже такой элемент в уникальном массиве
        for (int n = 0; n < new_mas.size(); n++) {
            if (mas[i] == new_mas[n]) {
                is_duplicate = true;
                break;
            }
        }

        // Если элемент не был найден среди уникальных, добавляем его
        if (!is_duplicate) {
            new_mas.push_back(mas[i]);
        }
    }

    // Вывод массива после удаления дубликатов
    cout << "Массив без дубликатов: ";
    for (int num: new_mas) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
