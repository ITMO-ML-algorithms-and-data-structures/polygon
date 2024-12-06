#include <vector>     
#include <algorithm> 

class Solution {
public:
    // Основная функция, которая будет вызываться для генерации всех подмножеств
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result; // Вектор для хранения результата (всех подмножеств)
        std::vector<int> subset; // Временный вектор для хранения текущего подмножества

        // Сортируем массив, чтобы легче было игнорировать дубликаты во время обхода
        std::sort(nums.begin(), nums.end());

        // Запускаем рекурсивную функцию backtrack с начальным индексом 0
        backtrack(result, subset, nums, 0);
        return result; // Возвращаем все найденные подмножества
    }

    // Рекурсивная вспомогательная функция для генерации подмножеств
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& subset, std::vector<int>& nums, int start) {
        // Включаем текущее подмножество в результат
        result.push_back(subset);

        // Проходим по элементам nums начиная с индекса start
        for (int i = start; i < nums.size(); i++) {
            // Пропускаем дубликаты
            // Если текущий элемент равен предыдущему, и это не первый элемент (i > start), 
            // то мы пропускаем текущий элемент, чтобы избежать добавления одинаковых подмножеств
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]); // Добавляем текущий элемент в подмножество
            // Рекурсивный вызов backtrack для включения следующего элемента
            backtrack(result, subset, nums, i + 1); // i + 1, чтобы избежать выбора одного и того же элемента
            // Убираем последний добавленный элемент, чтобы пройти к следующему варианту подмножества
            subset.pop_back();
        }
    }
};