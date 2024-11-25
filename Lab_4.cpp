#include <iostream>
#include <cstdio>
#include <vector>
#include <chrono>

// Класс, который будет использоваться для генерации всех возможных комбинаций элементов из массива
class ProductIterator {
public:
    ProductIterator(std::vector<int> elements, int repeat)
        : elements(elements), repeat(repeat), indices(repeat, 0) {}

    std::vector<int> next() {
        // Метод, который возвращает следующую комбинацию индексов

        if (is_done()) {
            // Кинуть ошибку, если пользователь попытается вызвать next в случае,
            // когда все комбинации сгенерированны
            throw std::out_of_range("No more combinations");
        }

        // Сгенерировать текущую комбинацию индексов
        std::vector<int> current_combination(repeat);  // O(N)
        for (int i = 0; i < repeat; ++i) {  // O(N)
            current_combination[i] = elements[indices[i]];
        }

        // Инкрементировать следующий индекс, внутри функции описание
        increment_indices();  // O(N)
        return current_combination;
    }

    bool is_done() const {
        return done;
    }

private:
    // Элементы на вход, [0, 1, 2]
    std::vector<int> elements;
    // Количество повторений, 3^(repeat)  
    int repeat;  
    
    // Текущее состояние для индексов, его на каждой итерации меняем и по нему ориентируемся, что вернуть пользователю
    std::vector<int> indices;
    
    bool done = false;  // флаг завершения генерации комбинаций

    // Метод, который увеличивает индексы для генерации след. комбинации
    void increment_indices() {
        for (int i = repeat - 1; i >= 0; --i) {  // O(N / 2) = O(N)
            if (indices[i] + 1 < elements.size()) {
                indices[i]++;  // Тут инкрементируем и больше не идем
                return;
            }
            indices[i] = 0; // Вот здесь вот зануляем
        }

        // Если не нашлось того значения, которое надо инкрементировать, считаем, что все комбинации сгенерированны
        done = true;
    }
};


double mean_val(std::vector<int> arr) {
    // Подсчет центра кластера (среднего значения)
    int N = arr.size();
    
    int sum_ = 0;
    for (int i = 0; i < N; i++) {  // O(N)
        sum_ = sum_ + arr[i];
    }

    return ((double) sum_) / N;
}


double score_cluster(std::vector<int> arr, double cluster_center) {
    // Подчет скора - сумма разностей каждого элемента и центра кластера (среднего значения)
    int N = arr.size();

    double score = 0;
    for (int i = 0; i < N; i++) { // O(N)
        score += std::abs(((double)arr[i] - cluster_center));
    }
    return score;
}


void print_clusters(std::vector<int> cluster1, std::vector<int> cluster2, std::vector<int> cluster3, double score) {
    // Вывод скора и соответствующего кластера
    std::cout << "Score: " << score << ". Cluster 1:";

    for (int i = 0; i < cluster1.size(); i++) {
        std::cout << " " << cluster1[i];
    }

    std::cout << ". Cluster 2:";
    for (int i = 0; i < cluster2.size(); i++) {
        std::cout << " " << cluster2[i];
    }

    std::cout << ". Cluster 3:";
    for (int i = 0; i < cluster3.size(); i++) {
        std::cout << " " << cluster3[i];
    }

    std::cout << std::endl;
}


int main()
{
    // Данные на вход - массив, который нужно разбить на кластера
    int arr[] = {0, 1, 3, 6, 7, 11, 40, 60, 3, 54, 100, 89, 34, 30, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    //Записываем текущее время работы
    auto start = std::chrono::high_resolution_clock::now();

    // Генерация масок размерностью (3^N, N), чтобы учесть вме комбинации элементов
    ProductIterator masks_iter({0, 1, 2}, N);

    // Создание глобальных переменных для хранения лучшего скора и кластеров, изначальный "лучший скор" - очень большое число
    double best_score = std::numeric_limits<double>::infinity();
    std::vector<int> best_cluster1;
    std::vector<int> best_cluster2;
    std::vector<int> best_cluster3;

    // И теперь идем по всем комбинациям масок
    while (!masks_iter.is_done()) {  // O(3^N)
        // Получаем следующую маску
        std::vector<int> mask = masks_iter.next();  // O(3*N) = O(N)

        // Создание локальных переменных для хранения кластеров
        std::vector<int> cluster1;
        std::vector<int> cluster2;
        std::vector<int> cluster3;

        // Переспределение значений в кластера согласно новой маски
        for (int i = 0; i < N; i++) {  // O(N)
            if (mask[i] == 0) {
                cluster1.push_back(arr[i]); // O(N / 3) = O(N)
            } else if (mask[i] == 1) {
                cluster2.push_back(arr[i]); // O(N / 3) = O(N)
            }
            else if (mask[i] == 2) {
                cluster3.push_back(arr[i]);
            }
        }

        
        if (cluster1.size() > 0 && cluster2.size() > 0 && cluster3.size() > 0) {
            // Подсчёт центров кластеров
            double cluster1_center = mean_val(cluster1);  // O(N)
            double cluster2_center = mean_val(cluster2);  // O(N)
            double cluster3_center = mean_val(cluster3);

            // Подсчёт скора для каждого кластера, как сумма разностей элементов и центра
            double score1 = score_cluster(cluster1, cluster1_center);  // O(N)
            double score2 = score_cluster(cluster2, cluster2_center);  // O(N)
            double score3 = score_cluster(cluster3, cluster3_center);

            double score = score1 + score2 + score3;

            // Чем меньше скор, тем лучше получились кластера 
            if (score < best_score) {
                // Сохраняем лучший скор
                best_score = score;

                // Сохраняем новые полученные кластера
                best_cluster1 = cluster1;
                best_cluster2 = cluster2;
                best_cluster3 = cluster3;


                // Отладочная информация
                print_clusters(cluster1, cluster2, cluster3, score);  // O(N)
            }
        }
    }

    // Текущее время окончания выполнения работы
    auto end = std::chrono::high_resolution_clock::now();
    // Продолжительность выполнения работы
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << std::endl;
    std::cout << "Running time: " << duration.count() << "milliseconds" << std::endl;

    print_clusters(best_cluster1, best_cluster2, best_cluster3, best_score);
    
    return 0;
} 