#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <cmath>
#include <random>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "..\Source\doctest.h"


namespace selection_sort {

    int find_local_min(const std::vector<int>& vec, int cur_ind) {

        int min_index = cur_ind;
        int min_element = vec[cur_ind];
        for (int i = cur_ind + 1; i < vec.size(); i++) {
            if (vec[i] < min_element) {
                min_index = i;
                min_element = vec[i];
            }
        }

        return min_index;

    }

    void sort(std::vector<int>& vec) {

        for (int i = 0; i < vec.size(); i++) {

            int local_min_ind = find_local_min(vec, i);
            std::swap(vec[i], vec[local_min_ind]);

        }

    }

};

namespace comb_sort {

    const double SF = 1.3;

    void sort(std::vector<int>& vec) {

        int gap = vec.size();
        bool swapped = true;

        while(gap != 1 || swapped) {

            gap /= SF;
            gap = (gap < 1 ? 1 : gap);

            swapped = false;

            for (int i = 0; i + gap < vec.size(); i++) {

                if (vec[i] > vec[i + gap]) {
                    std::swap(vec[i], vec[i + gap]);
                    swapped = true;
                }

            }

        }

    }

};

namespace bucket_sort {

    std::pair<int, int> min_max(const std::vector<int>& vec) {
        
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();

        for (auto i : vec) {
            min = std::min(min, i);
            max = std::max(max, i);
        }

        return std::make_pair(min, max);

    }

    void insertion_sort(std::vector<int>& vec) {

        for (int i = 1; i < vec.size(); i++) {

            int key = vec[i];
            int j = i - 1;

            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }

            vec[j + 1] = key;

        }

    }

    void sort(std::vector<int>& vec) {

        std::pair<int, int> mini_maxi = min_max(vec);

        std::vector<std::vector<int>> buckets(vec.size());

        for (int value : vec) {

            double normalized_value = (double)(value - mini_maxi.first) / (double)(mini_maxi.second - mini_maxi.first);
            int bucket_index = (value == mini_maxi.second ? buckets.size() - 1 : normalized_value * buckets.size());

            buckets[bucket_index].push_back(value);

        }

        for (int i = 0; i < buckets.size(); i++)
            insertion_sort(buckets[i]);

        vec.clear();
        for (auto bucket : buckets)
            for (auto element : bucket)
                vec.push_back(element);

    }

};

TEST_CASE("Testing selection sort") {

    const int LEN = 1e4;

    std::vector<int> best_case(LEN), worst_case(LEN), middle_case(LEN);

    for (int i = 0; i < LEN; i++) {
        best_case[i] = i;
        middle_case[i] = i;
        worst_case[i] = LEN - 1 - i;
    }

    std::srand(time(NULL));
    std::random_shuffle(middle_case.begin(), middle_case.end());

    selection_sort::sort(best_case);
    selection_sort::sort(middle_case);
    selection_sort::sort(worst_case);

    CHECK(std::is_sorted(best_case.begin(), best_case.end()) == true);
    CHECK(std::is_sorted(middle_case.begin(), middle_case.end()) == true);
    CHECK(std::is_sorted(worst_case.begin(), worst_case.end()) == true);

}

TEST_CASE("Testing comb sort") {

    const int LEN = 1e6;

    std::vector<int> best_case(LEN), worst_case(LEN), middle_case(LEN);

    for (int i = 0; i < LEN; i++) {
        best_case[i] = i;
        middle_case[i] = i;
        worst_case[i] = LEN - 1 - i;
    }

    std::srand(time(NULL));
    std::random_shuffle(middle_case.begin(), middle_case.end());

    comb_sort::sort(best_case);
    comb_sort::sort(middle_case);
    comb_sort::sort(worst_case);

    CHECK(std::is_sorted(best_case.begin(), best_case.end()) == true);
    CHECK(std::is_sorted(middle_case.begin(), middle_case.end()) == true);
    CHECK(std::is_sorted(worst_case.begin(), worst_case.end()) == true);

}

TEST_CASE("Testing bucket sort") {

    std::vector<int> best_case(1e6), worst_case(1e4), middle_case(1e6);

    for (int i = 0; i < best_case.size(); i++)
        best_case[i] = i;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-1e6, 1e6);

    for (int i = 0; i < middle_case.size(); i++)
        middle_case[i] = dist(gen);

    for (int i = 0; i < worst_case.size() - 1; i++)
        worst_case[i] = worst_case.size() - 1 - i;
    worst_case[worst_case.size() - 1] = std::numeric_limits<int>::max();

    bucket_sort::sort(best_case);
    bucket_sort::sort(middle_case);
    bucket_sort::sort(worst_case);

    CHECK(std::is_sorted(best_case.begin(), best_case.end()) == true);
    CHECK(std::is_sorted(middle_case.begin(), middle_case.end()) == true);
    CHECK(std::is_sorted(worst_case.begin(), worst_case.end()) == true);

}
