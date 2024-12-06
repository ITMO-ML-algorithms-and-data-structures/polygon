#include <iostream>
#include <cstdio>
#include <vector>
#include <chrono>

class ProductIterator {
public:
    ProductIterator(std::vector<int> elements, int repeat)
        : elements(elements), repeat(repeat), indices(repeat, 0) {}

    std::vector<int> next() {
        // Получить следующую комбинацию

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
    std::vector<int> elements;  // Элементы на вход, в нашем случае это [0, 1, 2]
    int repeat;  // Сколько повторений, в нашем случае это 3^(repeat)
    
    // текущее состояние для индексов, его на каждой итерации меняем и по нему
    // ориентируемся что вернуть пользователю
    std::vector<int> indices;
    
    bool done = false;  // флаг завершения генерации комбинаций

    void increment_indices() {
        // Изменить индексы, тут лучше на примере
        // По началу [0, 0, 0, 0, 0] - все нули
        // Потом инкрементируем первый элемент с конца, который меньше размера входного массива,
        // у нас на вход [0, 1, 2] - то есть 3, по этому сравниваем с ним
        // Если внутри индекса 1 - то мы его зануляем
        // Если внутри индекса 0 - то мы его инкрементируем и больше ничего не делаем
        // Вторая итерация - [0, 0, 0, 0, 1]
        // Третья итерация - [0, 0, 0, 1, 0]
        for (int i = repeat - 1; i >= 0; --i) {  // O(N / 2) = O(N)
            if (indices[i] + 1 < elements.size()) {
                indices[i]++;  // Тут инкрементируем и больше не идем
                return;
            }
            indices[i] = 0; // Вот здесь вот зануляем
        }

        // Если не нашлось того значения, которое надо инкрементировать, считаем
        // что все комбинации сгенерированны
        done = true;
    }
};


double mean_val(std::vector<int> arr) {
    // Подчет центра кластера (среднего значения)
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
    // Тут просто выводим скор и кластера
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
    int arr[] = {1, 10, 9, 2, 3, 8, 75};
    int N = sizeof(arr) / sizeof(arr[0]);

    auto start = std::chrono::high_resolution_clock::now();

    // Генерация масок размерностью (2^N, N), чтобы учесть вме комбинации элементов
    int rng[] = {0, 1, 2};
    ProductIterator masks_iter({0, 1, 2}, N);

// Создаем глобальные переменные для хранения лучшего скора и кластеров
    double best_score = std::numeric_limits<double>::infinity();
    std::vector<int> best_cluster1;
    std::vector<int> best_cluster2;
    std::vector<int> best_cluster3;

    // И теперь идем по всем комбинациям масок
    while (!masks_iter.is_done()) {  // O(2^N)
        // Получаем следующую маску
        std::vector<int> mask = masks_iter.next();  // O(2*N) = O(N)

        // Создаем локальные переменные для хранения кластеров
        std::vector<int> cluster1;
        std::vector<int> cluster2;
        std::vector<int> cluster3;

        // Делаем переспределение значений в кластера согласно новой маски
        for (int i = 0; i < N; i++) {  // O(N)
            if (mask[i] == 0) {
                cluster1.push_back(arr[i]); // O(N / 2) = O(N)
            } else if (mask[i] == 1) {
                cluster2.push_back(arr[i]); // O(N / 2) = O(N)
            }
            else if (mask[i] == 2) {
                cluster3.push_back(arr[i]);
            }
        }

        // Комбинации делаются "глупым" способом. Первая комбинация отнесла все числа
        // к первому кластеру, а последняя ко второму кластеру. Эти кейсы нужно исключить,
        // так как нам нужно 2 кластера
        if (cluster1.size() > 0 & cluster2.size() > 0 & cluster3.size() > 0) {
            // Считаем центры кластеров
            double cluster1_center = mean_val(cluster1);  // O(N)
            double cluster2_center = mean_val(cluster2);  // O(N)
            double cluster3_center = mean_val(cluster3);

            // Считаем скор для каждого кластера, как сумма разностей элементов и центра
            double score1 = score_cluster(cluster1, cluster1_center);  // O(N)
            double score2 = score_cluster(cluster2, cluster2_center);  // O(N)
            double score3 = score_cluster(cluster3, cluster3_center);

            double score = score1 + score2 + score3;

            // Чем меньше скор, тем лучше получились кластера (минимизируем)
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

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << std::endl;
    std::cout << "Running time: " << duration.count() << "milliseconds" << std::endl;

    print_clusters(best_cluster1, best_cluster2, best_cluster3, best_score);

    return 0;
} 