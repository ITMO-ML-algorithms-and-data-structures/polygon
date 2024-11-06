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

// Ассимптотика O(2 ^ (N + 1))
int find_dec_mask(std::vector<std::vector<int>> &data, int weight_limit) {
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
    return max_price_dec;
}

void test() {
    std::vector<std::vector<int>> data = {{2, 3}, {3, 4}, {4, 5}};
    int wlimit = 5;
    int price = 0;
    int len = data.size();
    std::vector<int> mask = dec2bin(find_dec_mask(data, wlimit), len);
    for (int i = 0; i < len; i++) {
        price += data[i][1] * mask[i];
    }
    if (price == 7) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }


    data = {{1, 35}, {16, 22}, {10, 100}, {2, 77}, {4, 24}};
    wlimit = 23;
    price = 0;
    len = data.size();
    mask = dec2bin(find_dec_mask(data, wlimit), len);
    for (int i = 0; i < len; i++) {
        price += data[i][1] * mask[i];
    }
    if (price == 236) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }


    data = {{2, 10}, {3, 15}, {5, 40}, {7, 50}, {1, 3}, {4, 20}, {1, 5}};
    wlimit = 15;
    price = 0;
    len = data.size();
    mask = dec2bin(find_dec_mask(data, wlimit), len);
    for (int i = 0; i < len; i++) {
        price += data[i][1] * mask[i];
    }
    if (price == 105) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }

    data =  {{6, 30}, {3, 14}, {4, 16}, {2, 9}, {5, 20}, {1, 3}};    
    wlimit = 10;
    price = 0;
    len = data.size();
    mask = dec2bin(find_dec_mask(data, wlimit), len);
    for (int i = 0; i < len; i++) {
        price += data[i][1] * mask[i];
    }
    if (price == 47) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }


}


int main() {
    test();
    std::vector<std::vector<int>> data = {{2, 3}, {3, 4}, {4, 5}};
    int wlimit = 5;
    int price = 0;
    int len = data.size();
    std::vector<int> mask = dec2bin(find_dec_mask(data, wlimit), len);
    for (int i = 0; i < len; i++) {
        price += data[i][1] * mask[i];
        std::cout << mask[i] << " ";
    }
    std::cout << std::endl << price;
}



