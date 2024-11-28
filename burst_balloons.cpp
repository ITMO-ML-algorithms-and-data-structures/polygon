#include <iostream>
#include <vector>
#include <algorithm>

// функция для вычисления максимального количества монет, которые можно получить
int max_coins(std::vector<int> &balloons)
{
    int num_balloons = (int)balloons.size();
    // добавляем шары с числами 1 в начало и конец списка
    std::vector<int> extended_balloons(num_balloons + 2);
    extended_balloons[0] = extended_balloons[num_balloons + 1] = 1; // чтобы не выйти за границы массива
    for (int i = 0; i < num_balloons; i++)
    {
        extended_balloons[i + 1] = balloons[i]; // копируем оригинальные шары в новый массив
    }
    // создаем таблицу maximum_of_coins для хранения промежуточных результатов
    std::vector<std::vector<int>> maximum_of_coins(num_balloons + 2, std::vector<int>(num_balloons + 2));
    // заполняем таблицу maximum_of_coins
    for (int length = 1; length <= num_balloons; length++)
    {
        for (int left = 1; left <= num_balloons - length + 1; left++)
        {
            int right = left + length - 1; // определяем правую границу текущего подмассива
            // пробуем лопать каждый шарик между left и right
            for (int k = left; k <= right; k++)
            {
                // количество монет, которое мы получим, если лопнем шарик k:
                int coins = extended_balloons[left - 1] * extended_balloons[k] * extended_balloons[right + 1];
                // максимальное количество монет, которое мы получим, если лопнем все шары слева и справа от k:
                coins += maximum_of_coins[left][k - 1] + maximum_of_coins[k + 1][right];
                // обновляем значение maximum_of_coins[left][right]
                maximum_of_coins[left][right] = std::max(maximum_of_coins[left][right], coins);
            }
        }
    }
    // возвращаем максимальное количество монет при лопании всех шаров
    return maximum_of_coins[1][num_balloons];
}

int main()
{
    std::vector<int> balloons = {1, 5};
    std::cout << max_coins(balloons) << std::endl;
    return 0;
}
