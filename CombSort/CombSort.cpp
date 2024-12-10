#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void combSort(vector<int>& a)
{
    int n = a.size();
    int gap = n;

    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);

        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    ifstream inputFile("C:/Users/mosko/PycharmProjects/h/f.txt");

    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
        return 1;
    }
    
    vector<int> a;
    int value;

    // Считывание данных из файла
    while (inputFile >> value) {
        a.push_back(value);
    }
    
    inputFile.close();

    // Проверка, что вектор не пуст
    if (a.empty()) {
        cerr << "Ошибка: файл пуст!" << endl;
        return 1;
    }

    auto start = high_resolution_clock::now();  

    combSort(a); // Сортировка

    auto end = high_resolution_clock::now();

    duration<double> duration_sec = end - start;

    // Вывод времени выполнения
    cout << "Время выполнения: " << duration_sec.count() << " секунд" << endl;

    return 0;
}