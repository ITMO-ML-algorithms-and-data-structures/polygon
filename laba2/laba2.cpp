#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> Kodirovshik(const vector<string>& clova) {
    unordered_map<string, int> Cash; // создаем хэш-таблицу
    vector<int> finish; // создаем переменную для закодированных значений (индексов)
    int ynikal = 0;
    //Память на строки: 50 * (24 байта + 10 байт) = 1700 байт.
    //Память на int: 50 * 4 байта = 200 байт.
      //  Память на хеш - таблицу : около 2000 байт.
      //  Итого : 3900 байт.
    
    // Кодирование строк
    for (const auto& index : clova) {
        if (Cash.find(index) == Cash.end()) {
            Cash[index] = ynikal++;
        }
        finish.push_back(Cash[index]); // добавляем закодированное значение
    }
    return finish;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_Elements = 10000; //4 байт
    const int MAX_Length = 100; //4 байт
    const int MAX_Uniqie = 255; //4 байт
    int i;
    //Память под переменные:
    // MAX_Elements, MAX_Length, MAX_Uniqie: 12 байт.
    // i : 4 байта.
    //Всего : 16 байт.
    cout << "Введите размер массива: ";
    cin >> i;

    if (i > MAX_Elements) {
        cout << "Некорректная длина массива" << endl;
        return 1;  // Завершаем программу, если размер больше допустимого
    }

    vector<string> arr(i);  // Используем строки, так как требуется проверка длины
    //Служебная информация на 100 строк: 100 * 24 байта = 2400 байт.
   //Память на 100 строк по 10 символов: 100 * 10 байт = 1000 байт.
        //Итого : 3400 байт.

    unordered_set<string> Uniqie; // Для проверки уникальных значений
    //Память на строки (аналогично вектору): 50 * 24 байта = 1200 байт (служебная информация).
    //Память на сами строки : 50 * 10 байт = 500 байт.
      //  Память на хеш - таблицу(в среднем 1.5x от размера) : около 1500 байт.
       // Итого : 3200 байт.
    // Ввод значений массива
    for (int n = 0; n < i; n++) {
        cout << "Введите значение массива: ";
        cin >> arr[n];

        // Проверяем длину строки
        if (arr[n].size() > MAX_Length) {
            cout << "Вы ввели слишком длинную строку, Сударь. Повторите ввод." << endl;
            n--;  // Уменьшаем счетчик для повторного ввода
            continue;
        }

        // Добавляем уникальное значение в unordered_set
        Uniqie.insert(arr[n]);
    }

    // Проверяем количество уникальных значений
    if (Uniqie.size() > MAX_Uniqie) {
        throw runtime_error("Ошибка: Уникальных значений больше 255");
    }
 
    // Кодирование массива
    vector<int> encoded_labels = Kodirovshik(arr);

    // Вывод закодированных значений
    cout << "Закодированные значения: ";
    for (int label : encoded_labels) {
        cout << label << " ";
    }
    cout << endl;

    return 0;
}
//Итого: 10516 байт (примерно 10.5 КБ).