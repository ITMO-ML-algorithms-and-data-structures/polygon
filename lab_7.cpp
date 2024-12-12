#include <iostream>
#include <vector>

class Solution {
public:
    long long maxSpending(std::vector<std::vector<int>>& values) {
        long long res = 0; //результат
        int m = values.size(); //кол-во магазинов
        int n = values[0].size(); //кол-во товаров
        std::vector<int> right_ind(m, n - 1); //указатели на доступные товары
        for (int day = 1; day <= m * n; day++) {
            long long min_value = 1000001; //минимальный правый товар
            int min_i = 0;
            int min_j = 0;
            for (int i = 0; i < m; i++) { //поиск самого дешевого товара
                int j = right_ind[i];
                if (j >= 0) {
                    int value = values[i][j];
                    if (value < min_value) {
                        min_value = value;
                        min_i = i;
                        min_j = j;
                    }
                }
            }
            res += day * min_value;
            right_ind[min_i] -= 1; //меняем указатель, т.к. купили товар
        }
        return res;
    }
};
