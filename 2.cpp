
#include <iostream>
#include <vector>

using namespace std;

// Функция для поиска всех уникальных подмассивов с суммой S
void f(const vector<int>& mas, int S) {
    int n = mas.size();
    
    // Внешний цикл проходит по каждому стартовому индексу подмассива
    for (int i = 0; i < n; ++i) {
        int summ = 0;
        
        // Внутренний цикл расширяет подмассив, начиная с индекса start
        for (int j = i; j < n; ++j) {
            summ += mas[j];

            // Если сумма подмассива равна S, выводим индексы
            if (summ == S) {
                cout << "low mas: " << i << " to " << j << endl;
            }
        }
    }
}

int main() {
    vector<int> mas = {-12, 2, 1, -10, 7};
    int S = -10;

    f(mas, S);

    return 0;
}

