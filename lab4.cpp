#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cassert>

double sum_deviations(const std::vector<double> &cluster) // вычисление суммы модулей отклонений 
{
    double average = 0.0;
    for (double value : cluster) // O(N)
    {
        average += value;
    }
    average /= cluster.size(); // вычисление среднего арифметического
    double deviations = 0.0;
    for (double value : cluster) // O(N)
    {
        deviations += std::abs(value - average);
    }
    return deviations;
}

std::vector<std::vector<double>> do_clusters(const std::vector<double> &array, int k) // разбиение кластера на K массивов
{
    int size = array.size(); 
    double min_deviations = std::numeric_limits<double>::max(); // инициализация минимальных отклонений самым большим значением, которое может принимать double 
    std::vector<std::vector<double>> best_clusters;
    for (int mask = 0; mask < (1 << (size - 1)); mask++) // перебор всех возможных разбиений с помощью битовой маски - O(2^(N-1)) (в худшем случае — это значение соответствует количеству возможных битовых масок для разбиений)
    {
        std::vector<std::vector<double>> clusters(1); // инициализация первого кластера
        for (int i = 0; i < size; i++) // проходим по всем элементам массива array - O(N)
        {
            clusters.back().push_back(array[i]); // добавляем i-й элемент в последний кластер
            if (i < (size - 1) && (mask & (1 << i))) // если i-й элемент -- не последний и битовая маска указывает на разбиение, создаем новый кластер
            {
                clusters.push_back({});
            }
        }

        if (clusters.size() == k) // если достигли необходимого числа кластеров, проверяем сумму отклонений 
        {
            double deviation = 0.0; //создаем переменную для хранения "стоимости" всех кластеров
            for (const std::vector<double> &cluster : clusters) // проходим по всем k кластерам, суммируем значения - O(k*N)
            {
                deviation += sum_deviations(cluster); 
            }
            if (deviation < min_deviations) // сохраняем минимальную сумму и кластеры с минимальной суммой отклонений
            {
                min_deviations = deviation;
                best_clusters = clusters;
            }
        }
    }
    return best_clusters;
}

void test_do_clusters()
{
    // простой случай
    std::vector<double> array1 = {1.0, 2.0, 3.0, 7.0, 3.2};
    std::vector<std::vector<double>> result1 = do_clusters(array1, 5);
    // проверяем, что результат содержит 5 кластеров
    assert(result1.size() == 5);
    // проверяем, что каждый кластер содержит ровно один элемент
    for (int i = 0; i < 5; ++i)
    {
        assert(result1[i].size() == 1);
    }

    // случай с равномерно распределенными значениями
    std::vector<double> array2 = {10.0, 20.0, 30.0, 40.0, 50.0};
    std::vector<std::vector<double>> result2 = do_clusters(array2, 5);
    // проверяем, что результат содержит 5 кластеров
    assert(result2.size() == 5);
    // проверяем, что каждый кластер содержит ровно один элемент
    for (int i = 0; i < 5; ++i)
    {
        assert(result2[i].size() == 1);
    }

    // неравномерное распределение
    std::vector<double> array3 = {1.0, 2.5, 3.5, 8.0, 20.0, 25.0, 30.0};
    std::vector<std::vector<double>> result3 = do_clusters(array3, 5);
    // проверяем, что результат содержит 5 кластеров
    assert(result3.size() == 5);
    // проверяем, что в каждом кластере хотя бы один элемент
    for (const auto &cluster : result3)
    {
        assert(!cluster.empty());
    }

    // случай с одинаковыми значениями
    std::vector<double> array4 = {100.0, 100.0, 100.0, 100.0, 100.0};
    std::vector<std::vector<double>> result4 = do_clusters(array4, 5);
    // проверяем, что результат содержит 5 кластеров
    assert(result4.size() == 5);
    // проверяем, что каждый кластер содержит ровно один элемент
    for (int i = 0; i < 5; ++i)
    {
        assert(result4[i].size() == 1);
    }
}

int main()
{
    test_do_clusters();
    std::cout << "Все тесты пройдены" << std::endl;
    return 0;
}
