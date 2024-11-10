#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

vector<int> get_mask(int size, int number, int digits) {
    //Преобразрвание числа в необходимую систему счисления
    //и возврат результата в виде массива размера size
    vector<int> translated(size); //O(n)

    for (int i = size - 1; i >= 0; i--) { // O(N)
        // Сохраняем остаток от деления на digits        
        translated[i] = number % digits;
        // Делим число на digits
        number /= digits;
    }
    return translated;
}

double mean_val(vector<double> arr) {
    // Подчет центра кластера (среднего значения)
    int N = arr.size();
    
    double sum_ = 0;
    for (int i = 0; i < N; i++) {  // O(N)
        sum_ = sum_ + arr[i];
    }

    return sum_ / N;
}

double score_cluster(vector<double> arr, double cluster_center) {
    // Подчет скора - сумма разностей каждого элемента и центра кластера (среднего значения)
    int N = arr.size();

    double score = 0;
    for (int i = 0; i < N; i++) { // O(N)
        score += abs((arr[i] - cluster_center));
    }
    return score;
}

void print_clusters(vector<double> cluster1, vector<double> cluster2, double score) {
    // Тут просто выводим скор и кластера
    cout << "Score: " << score << ". Cluster 1:";

    for (int i = 0; i < cluster1.size(); i++) { // O(N/2)
        cout << " " << cluster1[i];
    }

    cout << ". Cluster 2:";
    for (int i = 0; i < cluster2.size(); i++) { // O(N/2)
        cout << " " << cluster2[i];
    }

    cout << endl;
}

int main() {
    //array of int. change to double
    // double arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 100, 101, 5};
    double arr[] = {0, 1, 2, 3, 4, 5, 6.9 }; //N * 8 bytes

    int N = sizeof(arr) / sizeof(arr[0]);
    int num_clusters = 2;
    auto start = chrono::high_resolution_clock::now(); 



    // Создаем глобальные переменные для хранения лучшего скора и кластеров
    double best_score = numeric_limits<double>::infinity();
    vector<double> best_cluster1; //24 bytes
    // printf("Size of vector: %ld bytes \n", sizeof(best_cluster1)); //24 bytes
    vector<double> best_cluster2; //24 bytes

    //Проходим все значения от 1 до 2^N - 1 - 1 преобразуем их в маску и работаем с ней
    for (int number = 1; number < pow(num_clusters, N) - 1; number++) { // int = 4bytes, O(2^N)

        vector<int> current_mask = get_mask(N, number, num_clusters); //24 bytes

        // for (int j = 0; j < current_mask.size(); j++) {
        //     cout << " " << current_mask[j];
        // }
        // cout << endl;

        std::vector<double> cluster1; //24 bytes
        std::vector<double> cluster2; //24 bytes

        // Делаем переспределение значений в кластера согласно новой маски
        for (int i = 0; i < N; i++) {  // int = 4bytes, O(N)
            if (current_mask[i] == 0) {
                cluster1.push_back(arr[i]); // O(N / 2) = O(N)
            } else {
                cluster2.push_back(arr[i]); // O(N / 2) = O(N)
            }
        }

        // Считаем центры кластеров
        double cluster1_center = mean_val(cluster1);  //O(N)
        double cluster2_center = mean_val(cluster2);  //O(N)

        // Считаем скор для каждого кластера, как сумма разностей элементов и центра
        double score1 = score_cluster(cluster1, cluster1_center);  // O(N)
        double score2 = score_cluster(cluster2, cluster2_center);  // O(N)

        double score = score1 + score2;

        // Чем меньше скор, тем лучше получились кластера (минимизируем)
        if (score < best_score) {
            // Сохраняем лучший скор
            best_score = score;

            // Сохраняем новые полученные кластера
            best_cluster1 = cluster1;
            best_cluster2 = cluster2;

            // Отладочная информация
            print_clusters(cluster1, cluster2, score);  // O(N)
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << endl;
    cout << "Время выполнения: " << duration.count() << " милисекунд" << endl;

    print_clusters(best_cluster1, best_cluster2, best_score);

    return 0;
}