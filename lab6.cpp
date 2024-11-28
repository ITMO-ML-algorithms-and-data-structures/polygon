#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public:
    
    // Объявляем массив mas для хранения минимальных разрезов
    int mas[2005];
    
    // Вектор для хранения информации о том, является ли подстрока палиндромом
    vector<vector<bool>> is_palin;
    
    // Функция для заполнения информации о палиндромах
    void fill_palin(string str)
    {
        int n = str.size();
        for (int dist = 0; dist < n; dist++)  // dist — это расстояние между i и j
        {
            for (int i = 0; i + dist < n; i++)
            {
                int j = i + dist;
                if (dist == 0)
                {
                    // Один символ всегда палиндром
                    is_palin[i][j] = true;
                }
                else if (dist == 1)
                {
                    // Два символа палиндром, если они одинаковые
                    is_palin[i][j] = (str[i] == str[j]);
                }
                else
                {
                    // Для большей длины проверяем, если внешние символы одинаковые и внутренний подстрока палиндром
                    if (str[i] == str[j])
                    {
                        is_palin[i][j] = is_palin[i + 1][j - 1];
                    }
                }
            }
        }
    }
    
    // Рекурсивная функция для нахождения минимальных разрезов
    int helper(string& str, int i, int n)
    {
        // Базовый случай: если дошли до конца строки, разрезов нет
        if (i == n)
            return 0;
        
        // Если результат для этого индекса уже вычислен, возвращаем его
        if (mas[i] != -1)
        {
            return mas[i];
        }
        
        int mini = INT_MAX; // Ищем минимальный разрез
        
        for (int j = i; j < n; j++)
        {
            // Если подстрока [i, j] является палиндромом, делаем разрез
            if (is_palin[i][j])
            {
                mini = min(mini, 1 + helper(str, j + 1, n));  // 1 — это текущий разрез
            }
        }
        
        return mas[i] = mini; // Сохраняем результат и возвращаем его
    }
    
    int minCut(string str) {
        int n = str.size();
        
        is_palin.resize(n, vector<bool>(n, false)); // Инициализируем двумерный вектор is_palin размером n x n
    
        fill_palin(str); // Заполняем информацию о палиндромах
        
        memset(mas, -1, sizeof(mas)); // Инициализируем массив mas значениями -1
        
        return helper(str, 0, n) - 1; // Возвращаем минимальное количество разрезов (минус 1, так как последний разрез не нужен)
    }
};
