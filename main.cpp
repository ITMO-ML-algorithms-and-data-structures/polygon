#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <fstream>
using namespace std;

vector<int> solution(vector<int>& arr) {
    int size = arr.size(); // +4 байта
    // cout << size;

    vector<int> res = arr; // + 4*k байт (k максимум 4e9 байт)
    for (int i = 0; i < size; i++) { // +4 байт
        // генерируем случайное число `j` такое, что `i <= j < n` и
        // меняем местами элемент с индексом `j` и элемент с индексом `i`

        int j = i + (rand() % (size - i)); // +4 байт
        //cout << j << endl;
        swap(res[i], res[j]);
    }
    return res;
    // Затраты по дополнительной памяти: 4*k + 3*4 = 4*k + 12 байт <= 2*4*1e9 + 12 = 8000000012 байт
    // Алгоритмическая сложность по времени: O(size) - линейное время
}

void test() {
    vector<int> vec = {1, 100, 10, 2};
    vector<int> res = solution(vec);

    // Тест 1: Размер полученного массива сохраняется
    assert(res.size() == vec.size());

    // Тест 2: Проверка содержимого
    vector<int> originalVec = vec;
    vector<int> resVec = res;
    sort(originalVec.begin(), originalVec.end());
    sort(resVec.begin(), resVec.end());
    assert(originalVec == resVec); // Содержимое должно быть одинаковым

    // Тест 3: проверить, что результат перемешивания отличается от исходного вектора
    // (но не гарантирует, что это всегда будет так)
    int differentCount = 0;
    for (int i = 0; i < 100; ++i) {
        if (res != vec) {
            differentCount++;
        }
    }
    assert(differentCount > 0);

    // Тест 4: для пустого массива
    vector<int> empty_vec;
    vector<int> res_empty = solution(empty_vec); // Ваша функция перемешивания
    assert(res_empty.empty());

    // Тест 5: для массива с одним элементом
    vector<int> oneel_vec = {52};
    vector<int> res_oneel = solution(oneel_vec); // Ваша функция перемешивания
    assert(res_oneel.size() == 1 && res_oneel[0] == 52);
}


int main()
{
    srand(static_cast<unsigned>(time(0)));
    test();
    //Потоковый ввод
    string input;
    getline(cin, input);

    istringstream iss(input);
    vector<int> arr;
    int x;

    while (iss >> x) { // Извлекаем числа из строки
        arr.push_back(x);
    }

    vector<int> ans = solution(arr);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}