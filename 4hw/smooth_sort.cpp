#include "smooth_sort.h"


std::vector<size_t> create_leonardo_numbers(const size_t n) {
    std::vector<size_t> res;
    res.push_back(1);
    res.push_back(1);
    while (res.back() < n)
        res.push_back(res[res.size() - 1] + res[res.size() - 2] + 1);
    return res;
}


void sort_roots(std::vector<long long> &array,
                std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums,
                size_t position) {
    long long position_val = array[position];

    while (leonardo_nums[subtree_size[position]] <= position
        and array[position] < array[position - leonardo_nums[subtree_size[position]]])
    {
        array[position] = array[position - leonardo_nums[subtree_size[position]]];
        position -= leonardo_nums[subtree_size[position]];
    }

    array[position] = position_val;
}


void balance_tree(std::vector<long long> &array,
                  std::vector<size_t> &subtree_size,
                  const std::vector<size_t> &leonardo_nums,
                  size_t position) {
    if (subtree_size[position] == 0 or subtree_size[position] == 1) return;

    if (array[position]
        < array[position
             - leonardo_nums[subtree_size[position]]
             + leonardo_nums[subtree_size[position] - 1]) {

    }
}


void build_heap(std::vector<long long> &array,
                std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums) {
    subtree_size[0] = 1;
    subtree_size[1] = 0;
    balance_heap(array, subtree_size, leonardo_nums, 1);

    for (size_t i = 2; i < array.size(); ++i) {
        if (subtree_size[i - 2] == subtree_size[i - 1] + 1)
            subtree_size[i] = std::max(subtree_size[i - 2], subtree_size[i -1]) + 1;
        else if (subtree_size[i - 1] == 1)
            subtree_size[i] = 0;
        else
            subtree_size[i] = 1;

        balance_heap(array, subtree_size, leonardo_nums, i);
    }
}


std::vector<long long> smooth_sort(const std::vector<long long> &input_vector) {
    std::vector<size_t> leonardo_nums = create_leonardo_numbers(input_vector.size());
    std::vector<long long> array = input_vector;
    std::vector<size_t> subtree_size(input_vector.size());

    build_heap(array, subtree_size, leonardo_nums);
}
