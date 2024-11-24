#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>


int maxCoins(std::vector<int>& input_array) {
    // Задаем массив с номерами шариков, вместе с nums[-1] и nums[n]
    int num_ballons = input_array.size() + 2; // 4 байта
    // Матрица, в которой будем хранить промежуточные суммы выигранных монет (ДП)
    std::vector<std::vector<int>> dp(num_ballons, std::vector<int>(num_ballons)); // 24 + (n + 2)^2 байта

    // Добавляем в начало и конец массива единицы (крайние шарики nums[-1] и nums[n])
    input_array.insert(input_array.begin(), 1);
    input_array.insert(input_array.end(), 1);
    
    for(int len = 2; len <= num_ballons; len++) { // O(n) - проходимся по всем шарикам со второго правой границей (длина выбранного подмассива)
        for(int i = 0; i <= num_ballons - len; i++) { // O(n) - проходимся по всем шарикам в подмассиве левой границей
            int j = i + len - 1; // 4 байта, фиксируем правую границу
            // Выбираем, какой шарик выгоднее всего лопнуть в выбранном подмассиве
            for(int k = i + 1; k < j; k++) { // O(n) - проходимся по подмассиву
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k][j] + input_array[i] * input_array[k] * input_array[j]); 
                // Запиываем в матрицу ДП максимальную награду, которую можно получить, лопнув шарик в этом подмассиве, считаем по формуле из условия задачи
            }
        }
    }
    return dp[0][num_ballons - 1]; // Выводим ответ
}
    

void time_tests() {
    std::vector<int> test_sizes = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
    
    for (const int sz : test_sizes) {
        std::vector<int> random_vec(sz, 0);
        srand(time(0));
        generate(random_vec.begin(), random_vec.end(), rand);
        
        clock_t start = clock();
        maxCoins(random_vec);
        
        std::cout << "На обработку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*1000 << " мс" << std::endl;
    }
}


int main()
{   
    time_tests();
    
    std::vector<int> inp_array = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << maxCoins(inp_array) << std::endl;

    return 0;
}