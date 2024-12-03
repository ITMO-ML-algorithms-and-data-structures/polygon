#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int total_sum = 0, n = nums.size();

        // Вычисляем общую сумму всех элементов массива
        for (int num : nums) {
            total_sum += num;
        }

        // Перебираем все возможные размеры подмассивов от 1 до n / 2
        // Поскольку массив должен быть разделен на два непустых подмассива
        for (int size = 1; size <= n / 2; ++size) {

            // Проверяем, делится ли произведение total_sum * size на n
            // Если не делится, то не можем найти подмассив с нужной суммой для данного размера
            if ((total_sum * size) % n == 0) {

                // Вычисляем целевую сумму для подмассива размера size
                int target = (total_sum * size) / n;

                // Проверяем, можем ли найти подмассив с нужной целевой суммой
                if (canFindSubset(nums, size, target)) {
                    return true;  // Если нашли подмассив с нужной суммой, возвращаем true
                }
            }
        }

        return false;  // Если не нашли ни одного подмассива с нужной суммой, возвращаем false
    }

private:
    bool canFindSubset(const vector<int>& nums, int size, int target) {
        // Создаем вектор dp, где dp[i] хранит множество всех возможных сумм, которые можно
        // составить из i элементов массива
        vector<unordered_set<int>> dp(size + 1);

        // Инициализируем dp[0] с суммой 0, так как для подмассива из 0 элементов сумма равна 0
        dp[0].insert(0);

        // Перебираем все элементы массива
        for (int num : nums) {
            // Для каждого возможного размера подмассива от size до 1 (в обратном порядке)
            // Чтобы не использовать один элемент дважды в одном подмассиве
            for (int i = size; i > 0; --i) {
                // Для каждого возможного предыдущего значения суммы, которое можно получить
                // из подмассива размера i-1
                for (int prev_sum : dp[i - 1]) {
                    // Добавляем текущий элемент к этим суммам и сохраняем новые суммы
                    dp[i].insert(prev_sum + num);
                }
            }
        }

        // Если в множестве dp[size] есть сумма, равная target, значит, мы нашли подмассив
        // из size элементов, сумма которых равна target, возвращаем true
        return dp[size].count(target) > 0;
    }
};
