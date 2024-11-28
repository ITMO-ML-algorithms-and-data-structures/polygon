# https://leetcode.com/problems/beautiful-arrangement/?envType=problem-list-v2&envId=dynamic-programming&

class Solution {
public:
    int count; // Счетчик красивых перестановок

    // Основная функция
    int countArrangement(int n) {
        count = 0;
        // Массив, в котором будут использованные значения в перестановке
        std::vector<bool> use (n + 1, false); 

        // Перебираем все возможные красивые переставки
        backtrack(n, 1, use);
        return count;
    }

    // Функция для перебора всех возможных перестановок методом backtrack
    void backtrack(int n, int pos, std::vector<bool>& use) {
        
        // Если вышли за рамки, то перестановка удачная!
        if (pos > n) {
            count++;
            return;
        }

        // Строим перестановки
        for (int num = 1; num <= n; num++) {
            // Проверяем условие для красивой перестановки
            if (!use[num] && (num % pos == 0 || pos % num == 0)) {
                // Отмечаем, что число использовалось
                use[num] = true;
                // Делаем рекурсию для продолжения построения
                backtrack(n, pos + 1, use);
                // Откатываем выбор
                use[num] = false;
            }
        }
    }
};
