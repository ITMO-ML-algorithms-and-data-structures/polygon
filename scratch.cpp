#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
std::vector<std::vector<char>> generate_all_masks(const int size, const char k) {
    std::vector<std::vector<char>> all_masks(std::pow(k, size));
    std::vector<char> mask(size, 0);
    if (size > 25){
        throw "Size is above 25";
    }
    for (int i = 0; i < std::pow(k, size); i++){
        std::vector<char> mask_to_add(mask);
        all_masks.push_back(mask_to_add);
        for (int j = size - 1; j > -1; j--) {
            if (mask[j] == 1) {
                mask[j] = 0;
            } else if (mask[j] == 0) {
                mask[j] = 1;
                break;
            }
        }
    }
    return all_masks;
}
float calculate_cluster_metric(std::vector<float> cluster) {
    float summa = 0;
    float mean = 0;
    float rate = 0;
    for(int i = 0; i < cluster.size(); i++) {
        summa += cluster[i];
    }
    mean = summa / cluster.size();
    for(int i = 0; i < cluster.size(); i++) {
            rate += std::abs(cluster[i] - mean);
    }
    return rate;
}
float calculate_metric(std::vector<float> cluster1, std::vector<float> cluster2) {
    float metric1 = calculate_cluster_metric(cluster1);
    float metric2 = calculate_cluster_metric(cluster2);
    float rate = 0;
    rate = std::abs(metric1 - metric2);
    return rate;
}
int main(){
    const char k = 2;
    float arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    float arr2[] = {1, 2, 3,10, 9, 8};
    float arr3[] = {99.5, 101, -1.1};
    const int size1 = sizeof(arr1) / sizeof(arr1[0]);
    const int size2 = sizeof(arr2) / sizeof(arr2[0]);
    const int size3 = sizeof(arr3) / sizeof(arr3[0]);
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<char>> masks = generate_all_masks(size1, k);
    float min_rate = 9999999;
    for (int i = 0; i < masks.size(); i++){
        std::vector<char> mask = masks[i];
        std::vector<float> cluster1 = {};
        std::vector<float> cluster2 = {};
        for (int j = 0; j < mask.size(); j++){
            if (mask[j] == 0) {
                cluster1.push_back(arr1[j]);
            } else {
                cluster2.push_back(arr1[j]);
            }
        }
        //std::cout << calculate_metric(cluster1, cluster2) << std::endl;
        if(min_rate > calculate_metric(cluster1, cluster2)) {
            min_rate = calculate_metric(cluster1, cluster2);
        }
    }
    std::cout << min_rate;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "Время выполнения: " << elapsed_time.count() << " секунд" << std::endl;
    return 0;
}