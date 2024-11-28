#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int tallestBillboard(const vector<int>& rods) {

    // Создаем хранилище для динамического программирования
    unordered_map<int, int> dp; // храним разницу и соответствующую максимальную высоту при этой разнице, Память O(S)
    dp[0] = 0; // Начальное состояние

    // Проходим по каждому стержню
    for (int rod : rods) { // O(n) - временная сложность
        // Обновляем dp в обратном порядке, чтобы не использовать один и тот же стержень дважды
        unordered_map<int, int> currentDp = dp; // память O(S)

        for (const auto& entry : dp) { // O(S) - зависит от количества ключей в стержне (от диапазона значений diff)
            int diff = entry.first;
            int height = entry.second;
            // Добавляем стержень к одной из опор
            currentDp[diff + rod] = max(currentDp[diff + rod], height + rod);
            // Добавляем стержень к другой опоре
            currentDp[diff - rod] = max(currentDp[diff - rod], height + rod);
        }

        dp = currentDp;
    }

    int maxHeight = 0;

    // Находим максимальную высоту, которая может быть достигнута
    for (const auto& entry : dp) { // O(S)
        int diff = entry.first;
        int height = entry.second;
        if (diff == 0) { // Только если опоры равны
            maxHeight = max(maxHeight, height);
        }
    }

    return maxHeight / 2; // Возвращаем половину, так как высота одной опоры
}

int main() {
    vector<int> test1 = { 1,2,3,4,5,6 };
    cout << tallestBillboard(test1);
}

// Таким образом, пространственная сложность алгоритма будет O(S)
// Временная - O(N*S), где S - сумма всех стержней
