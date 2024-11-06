#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> dec2bin(int decimal, int len) {
    std::vector<int> binary(len, 0);
    for (int i = 0; i < len; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    return binary;
}

int main() {
    std::vector<std::vector<int>> data = {{2, 3}, {3, 4}, {4, 5}};
    int weight_limit = 5;

    int len = data.size();
    int max_dec = pow(2, len);

    int max_price = 0;
    int max_price_dec = 0;
    for (int i = 0; i < max_dec; i++) {
        int local_price = 0;
        int local_weight = weight_limit;
        int last_j = 0;
        std::vector<int> mask = dec2bin(i, len);
        for (int j = 0; (j < len) && (local_weight >= 0); j++) {
            local_price += data[j][1] * mask[j];
            local_weight -= data[j][0] * mask[j];
            last_j = j;
        }
        if ((local_price > max_price) && (local_weight >= 0) && (last_j == (len - 1))) {
            max_price = local_price;
            max_price_dec = i;
        }
    }
    std::cout << max_price << endl;
    std::vector<int> mask = dec2bin(max_price_dec, len);
    for (int i = 0; i < len; i++) {
        std::cout << mask[i] << " ";
    }
    return 0;
}

// Ассимптотика O(2 ^ (N + 1))

