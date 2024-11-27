#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <cmath>

#define DOCTEST_IMPLEMENT_WITH_MAIN
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

    std::vector<int> best_case, worst_case, middle_case;

}
