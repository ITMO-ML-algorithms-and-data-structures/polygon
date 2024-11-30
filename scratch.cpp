#include <vector>
#include <iostream>
#include <complex>
std::vector<std::vector<char>> generate_all_masks(const int arr1[], const char k = 2) {
    const int size = sizeof(arr1) / sizeof(arr1[0]);
    std::vector<std::vector<char>> all_masks(std::pow(k, size));
    std::vector<char> mask(size, 0);
    if (size > 20){
        throw "Size is above 20";
    }
    for (int i = 0; std::pow(k, size); i++){
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
float calculate_metric(cluster)
int main(){
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 2, 3,10, 9, 8};
    double arr3[] = {99.5, 101, -1.1};
    std::vector<std::vector<char>> masks = generate_all_masks(arr1);
    for (int i = 0; i < masks.size(); i++){
        std::vector<char> mask = masks[i];
        std::vector<int> cluster1;
        std::vector<int> cluster2;
        for (int j = 0; j < mask.size(); j++){
            if (mask[j] == 0) {
                cluster1.push_back(arr1[j]);
            } else {
                cluster2.push_back(arr1[j]);
            }
        }
    }
    return 0;
}