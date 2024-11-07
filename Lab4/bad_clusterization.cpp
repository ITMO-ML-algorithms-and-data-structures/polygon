#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cmath>

// Задача: разбить массив на 6 кластеров

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Source/doctest.h"

// Функция для генерации всевозможных комбинаций начальных центроидов кластеров
// Сложность - о(n(n - 1)(n - 2)(n - 3)(n - 4)(n - 5)) = o(n^6), где n - количество элементов массива
// Память - 4 * (n! / ( (n - 6)! * 6!)) байт, где n - кол-во элементов массива
std::vector<std::vector<int>> centroids(int elements) {

    std::vector<std::vector<int>> centroids; // Создаем массив для хранения комбинаций центроидов
    centroids.reserve(elements * (elements - 1) * (elements - 2) * (elements - 3) * (elements - 4) * (elements - 5) / 720);
    // Резервируем место, чтобы не происходило реаллокаций, память - 4 * (n! / ( (n - 6)! * 6!)) байт, где n - кол-во элементов массива

    // Нахождение всевозможных комбинаций центроидов (сочетания без повторений, так как нам не важен порядок)
    for (int p1 = 0; p1 <= elements - 1; p1++)
        for (int p2 = p1 + 1; p2 <= elements - 1; p2++)
            for (int p3 = p2 + 1; p3 <= elements - 1; p3++)
                for (int p4 = p3 + 1; p4 <= elements - 1; p4++)
                    for (int p5 = p4 + 1; p5 <= elements - 1; p5++)
                        for (int p6 = p5 + 1; p6 <= elements - 1; p6++)
                            centroids.push_back({p1, p2, p3, p4, p5, p6});

    return centroids; // Возвращаем комбинации
    // Если начальный массив состоял менее чем из 6 элементов, то вернется пустой массив

}

// Функция для нахождения суммы элементов в данном класторе
// Сложность - о(k), где k - кол-во элементов данного кластера
// Память - 8 байт
double cluster_sum(const std::vector<double>& vector, const std::vector<int>& cluster_in_inds) {

    double sum = 0; // Перменная для хранения суммы, память - 8 байт

    for (int i = 0; i < cluster_in_inds.size(); i++) {
        sum += vector[cluster_in_inds[i]]; // Проходим по каждому элементу кластера и добавляем его к итоговой сумме
    }

    return sum; // Возвращаем сумму

}

// Функция для подсчета "очков" кластера
// Количество "очков" высчитывается как максимум из разностей каждого элемента кластера и среднего арифметического значений кластера
// Может вести предподсчет "очков" для кластера, в который мы хотим добавить новый элемент
// Сложность - o(k) + о(k) = o(k), где k - количество элементов кластера
// Память - 8 * 3 = 24 байт
double cluster_score(const std::vector<double>& vector, const std::vector<int>& cluster_in_inds, bool add_new_element = false, const double& new_element = 0) {

    double score = 0; // Переменная для хранения "очков", память - 8 байт
    double cur_sum = cluster_sum(vector, cluster_in_inds); // Сумма кластера, сложность - о(k), где K - кол-во элементов кластера, память - 8 байт

    if (add_new_element) { // Если хотим узнать, сколько будет "очков" у данного кластера при добавлении в него нового элемента
        score = std::abs( ( (cur_sum + new_element) / (cluster_in_inds.size() + 1) ) - new_element ); // Расчитываем "очки" для нового элемента
        for (int i = 0; i < cluster_in_inds.size(); i++) { // Идем по каждому элементу кластера, сложность - о(k), где K - кол-во элементов кластера, память - 8 байт
            double i_score = std::abs( ( (cur_sum + new_element) / (cluster_in_inds.size() + 1) ) - vector[cluster_in_inds[i]] ); // Рассчитываем количество "очков" для i-ого элемента
            score = std::max(score, i_score); // Итоговый "счет" - максимум из "очков" элементов
        }
    } else { // Иначе
        for (int i = 0; i < cluster_in_inds.size(); i++) { // Идем по каждому элементу кластера, сложность - о(k), где K - кол-во элементов кластера, память - 8 байт
            double i_score = std::abs( ( cur_sum / cluster_in_inds.size() ) - vector[cluster_in_inds[i]] ); // Рассчитываем количество "очков" для i-ого элемента
            score = std::max(score, i_score); // Итоговый "счет" - максимум из "очков" элементов
        }
    }

    return score; // Возвращаем полученные "очки" кластера

}

// Функция для подсчета "очков" разбиения на кластеры
// Количество "очков" высчитывается как максимум из "очков" каждого кластера
// Сложность - sum(о(k_i)) = o(k), где k - размер самого большого кластера, k_i - размер i-ого кластера 
// Память - 8 байт
double partition_score(const std::vector<double>& vector, const std::vector<std::vector<int>>& partition_in_inds) {

    double score = 0; // Перменная для хранения "очков" разбиения, память - 8 байт

    for (int i = 0; i < partition_in_inds.size(); i++) // Проходим по всем кластерам
        score = std::max(score, cluster_score(vector, partition_in_inds[i])); // Итоговое количество "очков" - максимум из "очков" каждого кластера
        // Сложность - o(k_i), где k_i - размер i-ого кластера

    return score; // Возвращаем количество "очков"

}

// Функция для подсчета "очков равномерности" разбиения
// Нужна для того, чтобы в разбиении получались кластеры похожего размера, однако качество разбиения приоритетнее
// Высчитывается как разность между размерами самого большого и самого маленького кластеров
// Сложность - о(1) * 6 = о(1)
// Память - 16 байт
int uniformity_score(const std::vector<std::vector<int>>& partition) {

    size_t min_len = std::numeric_limits<int>::max(), max_len = 0; // Переменный для хранения максимального и минимального размеров кластеров, память - 8 * 2 = 16 байт
    for (int i = 0; i < partition.size(); i++) { // Проходим по всем кластерам
        min_len = std::min(min_len, partition[i].size()); // Расчет минимального размера
        max_len = std::max(max_len, partition[i].size()); // Расчет максимального размера
    }

    return (max_len - min_len); // Возвращаем разность между макс и мин

}

// Функция для разбиения массива на 6 кластеров
// Сложность ~= o(n^6) + o(n^6 * n * 1) + o(nlogk) ~= o(n^7)
// Память (максимум) - 4 * (n! / ( (n - 6)! * 6!)) + 4n * 3 + 8n + 8(n - 5) байт, где n - кол-во элементов массива
std::vector<std::vector<double>> clusterization(const std::vector<double>& vector) {

    std::vector<std::vector<int>> centroids_combinations = centroids(vector.size()); // Получаем всевозможные комбинации центроидов
    // Сложность - о(n(n - 1)(n - 2)(n - 3)(n - 4)(n - 5)) = o(n^6), где n - количество элементов массива
    // Память - 4 * (n! / ( (n - 6)! * 6!)) байт, где n - кол-во элементов массива

    std::vector<std::vector<int>> best_partition_in_inds; // Переменная для хранения лучшего разбиения, память - 4 * n байт, где n - кол-во элементов массива
    double best_partition_score = std::numeric_limits<double>::max(); // Переменная для хранения наилучшего количества "очков" разбиения
    int best_uniformity_score = std::numeric_limits<int>::max(); // Переменная для хранения наилучшего количества "очков равномерности" разбиения

    for (auto centroids_combination : centroids_combinations) { // Проходим по всем комбинациям центроидов, сложность - о(n^6)

        std::vector<std::vector<int>> partition_in_inds; // Переменная для хранения текущего разбиения (разбиение хранится в виде индексов с целью сохранения порядка элементов)
        // Память - 4 * n байт, где n - кол-во элементов массива

        for (auto i : centroids_combination) // Добавляем центроиды в разбиение
            partition_in_inds.push_back({i});

        for (int i = 0; i < vector.size(); i++) { // Проходим по всем элементам массива, сложность о(n), где n - кол-во элементов массива

            if (std::find(centroids_combination.begin(), centroids_combination.end(), i) != centroids_combination.end()) // Если текущий элемент является центроидом, то пропускаем его
                continue;

            int best_cluster = -1; // Переменная для хранения индекса наилучшего кластера для данного элемента
            double best_cluster_score = std::numeric_limits<double>::max(); // Переменная для хранения наилучшего количества "очков" кластера при добавлении в него текущего элемента
            
            int best_intermediate_uniformity_score = std::numeric_limits<int>::max(); // Переменна для хранения количества "очков равномерности" неполного разбиения

            for (int j = 0; j < partition_in_inds.size(); j++) { // проходим по всем текущим кластерам, сложность - о(1) * 6 = о(1)

                double cur_cluster_score = cluster_score(vector, partition_in_inds[j], true, vector[i]); // Переменная для хранения количества очков текущего кластера при добавлении в него текущего элемента

                std::vector<std::vector<int>> intermediate_partition_to_check_uniformity = partition_in_inds; // Переменная для хранения неполного разбиения, где текущий элемент добавлен в текущий кластер
                // Необходима для подсчета количества "очков равномерности" неполного разбиения
                // Память - 4n, где n - кол-во элементов массива

                intermediate_partition_to_check_uniformity[j].push_back(vector[i]); // Добавляем текущий элемент в текущий кластер

                if (cur_cluster_score < best_cluster_score) { // Если количество "очков" текущего кластера лучше, чем количество "очков" наилучшего кластера
                    best_cluster_score = cur_cluster_score; // Обновляем количество "очков" наилучшего кластера для текущего элемента
                    best_cluster = j; // Обновляем наилучший кластер для текущего элемента
                    best_intermediate_uniformity_score = uniformity_score(intermediate_partition_to_check_uniformity); // Обновляем наилучшее количество "очков равномерности"
                }
                else if (cur_cluster_score == best_cluster_score) { // Если количество "очков" текущего кластера равно количеству "очков" наилучшего кластера
                    if (uniformity_score(intermediate_partition_to_check_uniformity) < best_intermediate_uniformity_score) { // И количество "очков равномерности" текущего кластера лучше наилучшего
                        best_intermediate_uniformity_score = uniformity_score(intermediate_partition_to_check_uniformity); // Обновляем наилучшее количество "очков равномерности"
                        best_cluster = j; // Обновляем наилучший кластер
                    }
                }

            }

            partition_in_inds[best_cluster].push_back(i); // Добаляем текущий элемент в наиболее подходящий для него кластер

        }

        double cur_partition_score = partition_score(vector, partition_in_inds); // Переменная для хранения "очков" текущего разбиения

        if (cur_partition_score < best_partition_score) { // Если количество "очков" текущего разбиения лучше наилучшего разбиения
            best_partition_score = cur_partition_score; // Обновляем количество "очков" наилучшего разбиения
            best_partition_in_inds = partition_in_inds; // Обновляем наилучшее разбиение
            best_uniformity_score = uniformity_score(partition_in_inds); // Обновляем наилучшее количество "очков равномерности"
        }
        else if (cur_partition_score == best_partition_score) { // Иначе если равны
            if (uniformity_score(partition_in_inds) < best_uniformity_score) { // Если количество "очков равномерности" текущего разбиения лучше наилучшего разбиения
                best_uniformity_score = uniformity_score(partition_in_inds); // Обновляем наилучшее количество "очков равномерности"
                best_partition_in_inds = partition_in_inds; // Обновляем наилучшее разбиение
            }
        }

    }

    for (int i = 0; i < best_partition_in_inds.size(); i++) { // Сортируем индексы в каждом кластере, сложность - sum(о(nlog(k_i))) ~= o(nlogk),
                                                              // где k - наибольший размер кластеров, k_i - размер i-ого кластера
        std::sort(best_partition_in_inds[i].begin(), best_partition_in_inds[i].end());
    }

    std::vector<std::vector<double>> best_partition = {}; // Итоговое разбиение, память - 8n байт, где n - кол-во элементов в массиве
    for (int i = 0; i < best_partition_in_inds.size(); i++) { // Перевод итогового разбиения из индексов в значения

        std::vector<double> cluster; // Память (максимум) - 8 * (n - 5)
        for (int j = 0; j < best_partition_in_inds[i].size(); j++) {
            cluster.push_back(vector[best_partition_in_inds[i][j]]);
        }

        best_partition.push_back(cluster);

    }

    return best_partition; // Возвращаем итоговое разбиение
    // Если в массиве меньше 6 элементов, то будет возвращено пустое разбиение (пустой массив)

}

// Тестирующая система
TEST_CASE("Testing clusterization") {

    std::vector<std::vector<double>> test_vectors;
    std::string fname_pattern = "../Tests/clusterization/test_clusterization_";
    for (int i = 0; i < 6; i++) {
        std::vector<double> vector;
        std::ifstream file(fname_pattern + std::to_string(i + 1) + ".csv");
        double input;
        while (file >> input)
            vector.push_back(input);
        test_vectors.push_back(vector);
    }

    std::vector<std::vector<std::vector<double>>> partition_vectors;
    partition_vectors.push_back({}); // Пустой массив
    partition_vectors.push_back({}); // Массив из 4 элементов
    partition_vectors.push_back({{1.1}, {2.112}, {3.98}, {4.17}, {192.168}, {904}}); // Массив из 6 элементов
    partition_vectors.push_back({{-100.01, -99.876}, {198.976}, {123.1}, {457}, {8}, {12}}); // Массив из 7 элементов
    partition_vectors.push_back({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1}, {1, 1}, {1, 1}}); // Массив из 15 одинаковых чисел
    partition_vectors.push_back({{3.4, 1, 2.9, 1.2}, {-11, -10.9, -10, -9.7}, {-22, -23.8, -24.1, -23}, {53.9, 58.1, 50, 57}, {32.5, 34, 32, 33.1, 33}, {11.4, 9.9, 10.3, 9}}); // Массив из 25 различных чисел

    for (int i = 0; i < 6; i++) {
        CHECK(clusterization(test_vectors[i]) == partition_vectors[i]);
    }

}
