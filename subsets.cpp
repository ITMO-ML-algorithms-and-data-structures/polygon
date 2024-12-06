#include <vector>  
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; // Вектор, который будет содержать все подмножества
        vector<int> subset; // Временное подмножество для формирования результатов

        // Сортируем массив, чтобы можно было легко игнорировать дубликаты
        sort(nums.begin(), nums.end());

        // Запускаем вспомогательную функцию backtrack
        backtrack(result, subset, nums, 0);
        return result; // Возвращаем все найденные подмножества
    }

    void backtrack(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int start) {
        result.push_back(subset); // Добавляем текущее подмножество в результат

        for (int i = start; i < nums.size(); i++) {
            // Проверяем, если текущий элемент такой же, как предыдущий (пропускаем дубликаты)
            if (i > start && nums[i] == nums[i - 1]) {
                continue; // Если это дубликат, пропускаем итерацию
            }
            subset.push_back(nums[i]); // Добавляем текущий элемент в подмножество
            // Рекурсивно вызываем backtrack для формирования следующего подмножества
            backtrack(result, subset, nums, i + 1); // i + 1, чтобы избежать выбора одного и того же элемента
            subset.pop_back(); // Удаляем последний добавленный элемент, чтобы вернуться назад для следующего вызова
        }
    }
};