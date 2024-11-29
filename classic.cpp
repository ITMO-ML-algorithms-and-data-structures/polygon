#include <iostream>
#include <vector>
#include <cmath>


// сначала реализовал через next_permutation, но так нельзя


// метрика sum(abs(cluster[i] - arr_mean_cluster))
//функция для нахождения метрики
int get_metric_value(const std::vector<double>& cluster) {
    if (cluster.empty()) {
        return 0; //проверка на пустоту
    }

    double average_value = 0; //Память O(1) - 8 байт, тк double

    for (int i=0; i < cluster.size(); i++) { //асимптотика O(n)
        average_value += cluster[i];
    } 
    average_value = average_value / cluster.size(); //находим среднее значение по кластеру

    double metric = 0; //Память O(1) - 8 байт, тк double

    for (int i=0; i < cluster.size(); i++) { //асимптотика O(n)
        metric += abs(cluster[i] - average_value);
    }

    return metric; //возвращаем значение метрики
} 
// итоговая асимптотика функции O(n)


//рекурсивная функция для разбиения на кластеры
void create_clusters(const std::vector<double>& input_array, int i, int clusters_quantity, std::vector<std::vector<double>>& list_of_clusters, double current_metric, double& best_metric, std::vector<std::vector<double> >& best_set) {
    // аргументы функции: input_array - массив, который подается на вход, i - индекс input_array, clusters_quantity - колво кластеров, на которые надо разбить, current_set - текущий вектор, в который добавляем элементы, current_metric - меетрика для этого вектора, min_metric - , best_set - вектор с лучшей метрикой

    // Выход из функции
    // 1. если создали нужное колво кластеров и использовали все элементы из input_array
    if (i == input_array.size() && list_of_clusters.size() == clusters_quantity) {
        if (current_metric < best_metric) { 
            best_metric = current_metric; 
            best_set = list_of_clusters; 
        }
        return; 
    }

    // 2. если колво кластеров больше чем надо или если счетчик элементов input_array вышел за границу
    if (list_of_clusters.size() > clusters_quantity || i >= input_array.size()) {
        return;
    }

    // добавляем элемент из изначального списка в данный кластер
    for (int j = 0; j < list_of_clusters.size(); j++) { 

        list_of_clusters[j].push_back(input_array[i]); // добавляем i элемент массива в кластер
        // Память: для каждого кластера 24+l*8 байт, где l - количество элем в кластере 
        double cluster_metric = get_metric_value(list_of_clusters[j]); // подсчитывем метрику этого кластера
        //Память 8 байт

        // рекурсия для добавления след элемента в кластер
        create_clusters(input_array, i + 1, clusters_quantity, list_of_clusters, current_metric + cluster_metric, best_metric, best_set); 
        list_of_clusters[j].pop_back(); // вернуться к предыдущему шагу, удалить последний элемент
    }

    // рекурсия для создания кластеров
    if (list_of_clusters.size() < clusters_quantity) {
        list_of_clusters.push_back({input_array[i]}); // в кластер добавляем i элемент массива
        create_clusters(input_array, i + 1, clusters_quantity, list_of_clusters, current_metric, best_metric, best_set);
        list_of_clusters.pop_back(); // вернуться к предыдущему шагу, удалить созданный кластер
    }
}


//  функция для принятия изменений
std::vector<std::vector<double> > cluster_array(const std::vector<double>& input_array, int clusters_quantity) {
    std::vector<std::vector<double> > best_set; // 
    std::vector<std::vector<double> > list_of_clusters; // Текущий набор кластеров
    double best_metric = 1000000000000000000; // поставим миниальную метрику большой чтобы потом сравнивать

    create_clusters(input_array, 0, clusters_quantity, list_of_clusters, 0, best_metric, best_set); // Запускаем рекурсивную функцию для разбиения
    return best_set; // Возвращаем лучший набор кластеров
}


void out_double_vector(const std::vector<std::vector<double>>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


