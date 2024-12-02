#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Заданные предметы (вес, стоимость)
    vector<int> weights = {2, 3, 4};
    vector<int> values = {3, 4, 5};
    int n = weights.size();
    int weight_limit = 5;

    int max_value = 0;
    vector<int> best_combination;

    // Перебор всех возможных комбинаций
    for (int mask = 0; mask < (1 << n); ++mask) {
        int total_weight = 0;
        int total_value = 0;
        vector<int> current_combination;

        for (int i = 0; i < n; ++i) {
            // Проверяем, включен ли i-й предмет в текущую комбинацию
            if (mask & (1 << i)) {
                total_weight += weights[i];
                total_value += values[i];
                current_combination.push_back(weights[i]); // Сохраняем вес предмета
            }
        }

        // Обновляем лучшую комбинацию, если она удовлетворяет условиям
        if (total_weight <= weight_limit && total_value > max_value) {
            max_value = total_value;
            best_combination = current_combination;
        }
    }

    // Вывод результата
    cout << "Best combination of item weights: ";
    for (int w : best_combination)
        cout << w << " ";
    cout << "\nMaximum value: " << max_value << endl;

    return 0;
}
