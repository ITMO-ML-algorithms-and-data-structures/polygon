#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool splitArraySameAverage(vector<int>& nums) {
    int total_sum = 0;
    int n = nums.size();

    // Вычисляем общую сумму всех элементов в массиве
    for (int num : nums) {
        total_sum += num;
    }

    // Перебираем все возможные размеры подмассивов от 1 до n // 2
    for (int size = 1; size <= n / 2; ++size) {
        // Целевая сумма для подмассива из size элементов
        int target_sum = total_sum * size;

        // Проверяем, делится ли target_sum на n
        if (target_sum % n != 0) {
            continue;  // Если target_sum не делится на n, пропускаем этот размер
        }

        target_sum /= n;  // Целевая сумма для подмассива из size элементов

        // Используем unordered_map для хранения возможных сумм
        unordered_map<int, bool> dp;
        dp[0] = true;  // Начальная сумма 0 всегда достижима
        // Перебираем все элементы массива
        for (int num : nums) {
                    // Перебираем уже найденные суммы в обратном порядке
                    // Для этого сначала создаем список всех ключей
            vector<int> current_sums;
            for (auto& entry : dp) {
                current_sums.push_back(entry.first);
            }

            for (int current_sum : current_sums) {
                int new_sum = current_sum + num;
                if (new_sum == target_sum) {
                    return true;  // Если нашли подмассив с нужной суммой, возвращаем true
                }
                dp[new_sum] = true;  // Добавляем новую сумму в dp
            }
        }
    }

    return false;  // Если не удалось найти подходящий подмассив
}
int main() {
    // Вы можете протестировать вашу функцию здесь
    vector<int> nums = {1, 2, 3, 4, 5}; // Пример массива
    bool result = splitArraySameAverage(nums);

    cout << (result ? "True" : "False") << endl;

    return 0;
}


//версия для Leetcode
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();

        // Вычисляем общую сумму всех элементов в массиве
        for (int num : nums) {
            total_sum += num;
        }

        // Перебираем все возможные размеры подмассивов от 1 до n // 2
        for (int size = 1; size <= n / 2; ++size) {
            // Целевая сумма для подмассива из size элементов
            int target_sum = total_sum * size;

            // Проверяем, делится ли target_sum на n
            if (target_sum % n != 0) {
                continue;  // Если target_sum не делится на n, пропускаем этот размер
            }

            target_sum /= n;  // Целевая сумма для подмассива из size элементов

            // Используем unordered_set для хранения возможных сумм
            unordered_set<int> dp;
            dp.insert(0);  // Начальная сумма 0 всегда достижима

            // Перебираем все элементы массива
            for (int num : nums) {
                vector<int> current_sums(dp.begin(), dp.end());
                for (int current_sum : current_sums) {
                    int new_sum = current_sum + num;
                    dp.insert(new_sum);  // Добавляем новую сумму в dp
                }
            }

            // Если среди возможных сумм есть target_sum, возвращаем true
            if (dp.count(target_sum)) {
                return true;
            }
        }

        return false;  // Если не удалось найти подходящий подмассив
    }
};
