#include <iostream> 
#include <vector> 
#include <cassert> 

void find_summ(const std::vector<int>& arr, std::vector<std::vector<int>>& all_positions) {
    if (arr.size() < 5) {
        all_positions.push_back({});
    }
    else
        for (int i = 0; i < arr.size() - 4; i++) {
            for (int k = i + 1; k < arr.size() - 3; k++) {
                for (int q = k + 1; q < arr.size() - 2; q++) {
                    for (int w = q + 1; w < arr.size() - 1; w++) {
                        for (int x = w + 1; x < arr.size(); x++) {
                            if (arr[i] + arr[k] + arr[q] + arr[w] + arr[x] == 0) {
                                std::vector<int> positions = { i, k, q, w, x };
                                all_positions.push_back(positions);
                            }
                        }
                    }
                }
            }
        }
    if (all_positions.empty()) {
        all_positions.push_back({});
    }
}

void test() {

    std::vector<int> test1 = { 1, 2, -1, 10 , 0, 0, 0, 10, 10, 10 };
    std::vector<std::vector<int>> result1;
    std::vector<std::vector<int>> result1_expected = { {0, 2, 4, 5, 6} };
    find_summ(test1, result1);
    assert(result1 == result1_expected);

    std::vector<int> test2 = { 1, 2, -1, 10 , 10, 10, 10, 10, 10, 10 };
    std::vector<std::vector<int>> result2;
    std::vector<std::vector<int>> result2_expected = { {} };
    find_summ(test2, result2);
    assert(result2 == result2_expected);

    std::vector<int> test3 = { 1, 2, -1 };
    std::vector<std::vector<int>> result3;
    std::vector<std::vector<int>> result3_expected = { {} };
    find_summ(test3, result3);
    assert(result3 == result3_expected);

}

int main() {
    test();
    std::cout << "test completed successfully";
}
