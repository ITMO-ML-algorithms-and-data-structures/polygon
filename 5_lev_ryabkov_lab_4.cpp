#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел. O(1)

    int K = 25;                                // O(1) — инициализация размера массива
    vector<int> arr(K);                        // O(N) — создание вектора размера K для хранения случайных чисел

    for (int i = 0; i < K; ++i) {              // O(N) — цикл для инициализации элементов массива
        arr[i] = rand() % 41 - 20;             // O(1) — генерация случайного числа от -20 до 20 и присвоение элементу массива
    }

    vector<vector<int>> result;                // O(1) — инициализация вектора для хранения подмассивов, сумма которых равна 0
    int sum = 0;                               // O(1) — инициализация переменной для хранения суммы элементов подмассива

    // Шесть вложенных циклов для поиска комбинаций из 6 элементов массива, сумма которых равна 0
    for (int elem_1 = 0; elem_1 < K; ++elem_1)               // O(N)
    {
        for (int elem_2 = elem_1 + 1; elem_2 < K; ++elem_2)  // O(N)
        {
            for (int elem_3 = elem_2 + 1; elem_3 < K; ++elem_3) // O(N)
            {
                for (int elem_4 = elem_3 + 1; elem_4 < K; ++elem_4) // O(N)
                {
                    for (int elem_5 = elem_4 + 1; elem_5 < K; ++elem_5) // O(N)
                    {
                        for (int elem_6 = elem_5 + 1; elem_6 < K; ++elem_6) // O(N)
                        {
                            // Суммирование шести выбранных элементов
                            sum = arr[elem_1] + arr[elem_2] + arr[elem_3] + arr[elem_4] + arr[elem_5] + arr[elem_6]; // O(1)

                            if (sum == 0)                                      // O(1) — проверка на равенство 0
                            {
                                result.push_back({elem_1, elem_2, elem_3, elem_4, elem_5, elem_6}); // O(1) — добавление индексов в result
                            }
                        }
                    }
                }
            }
        }
    }

    // Вывод всех найденных комбинаций индексов
    for (int i = 0; i < result.size(); ++i) {          // O(N), где N — количество подходящих комбинаций
        for (int j = 0; j < result[i].size(); ++j) {   // O(1) — вывод индексов одной комбинации (всегда 6 элементов)
            cout << result[i][j] << " ";               // O(1) — вывод элемента
        }
        cout << "\n";                                  // O(1) — завершение строки вывода
    }

    cout << '\n';                                      // O(1) — новая строка для завершения вывода
    return 0;                                          // O(1) — завершение программы
}

/*
    Подсчет общей сложности:
    Итоговая пространственная сложность: O(N^6)
*/
