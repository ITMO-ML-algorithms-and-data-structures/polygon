#include "smooth_sort.h"


std::vector<size_t> create_leonardo_numbers(const size_t n) {
    // время и память O(1)
    std::vector<size_t> res;
    res.push_back(1);
    res.push_back(1);
    while (res.back() < n)
        res.push_back(res[res.size() - 1] + res[res.size() - 2] + 1);
    return res;
}


void balance_tree(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                  const std::vector<size_t> &leonardo_nums, const size_t position) {
    // O(log n) - время, просеивание дерева
    if (subtree_size[position] == 0 or subtree_size[position] == 1)
        return;

    const size_t left_child_position =
            position - leonardo_nums[subtree_size[position]] + leonardo_nums[subtree_size[position] - 1];

    const size_t right_child_position = position - 1;

    if (array[left_child_position] > array[right_child_position]) {
        if (array[left_child_position] > array[position]) {
            std::swap(array[position], array[left_child_position]);
            balance_tree(array, subtree_size, leonardo_nums, left_child_position);
        }
    } else if (array[right_child_position] > array[position]) {
        std::swap(array[position], array[right_child_position]);
        balance_tree(array, subtree_size, leonardo_nums, right_child_position);
    }
}


void sort_roots(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums, size_t position) {
    size_t prev_root = position - leonardo_nums[subtree_size[position]];
    size_t left_child_position =
            position + leonardo_nums[subtree_size[position] - 1] - leonardo_nums[subtree_size[position]];
    size_t right_child_position = position - 1;

    while (leonardo_nums[subtree_size[position]] <= position and array[position] < array[prev_root] and
           (subtree_size[position] < 2 or
            array[left_child_position] < array[prev_root] and array[right_child_position] < array[prev_root])) {
        std::swap(array[position], array[prev_root]);
        position = prev_root;
        left_child_position =
                position + leonardo_nums[subtree_size[position] - 1] - leonardo_nums[subtree_size[position]];
        right_child_position = position - 1;
        prev_root = position - leonardo_nums[subtree_size[position]];
    }
    // O(log n) - время, количество корней

    balance_tree(array, subtree_size, leonardo_nums, position);
    // O(log n) - время, просеивание дерева

    // O(log n) - общее время
}


void build_heap(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums) {
    subtree_size[0] = 1;
    subtree_size[1] = 0;
    sort_roots(array, subtree_size, leonardo_nums, 1);

    for (size_t i = 2; i < array.size(); ++i) {
        std::pair<size_t, size_t> prev_roots = {i - 1, i - leonardo_nums[subtree_size[i - 1]] - 1};
        if (subtree_size[prev_roots.first] + 1 == subtree_size[prev_roots.second])
            subtree_size[i] = subtree_size[prev_roots.second] + 1;
        else if (subtree_size[i - 1] == 1)
            subtree_size[i] = 0;
        else
            subtree_size[i] = 1;

        sort_roots(array, subtree_size, leonardo_nums, i);
        // O(log n) - время
    }
    // O(n * log n) - общая сложность
}


size_t find_max_root_pos(const std::vector<long long> &array, const std::vector<size_t> &subtree_size,
                         const std::vector<size_t> &leonardo_nums, size_t position) {
    size_t max_root_pos = position;
    size_t prev_root = position - leonardo_nums[subtree_size[position]];

    while (leonardo_nums[subtree_size[position]] <= position) {
        if (array[max_root_pos] < array[prev_root])
            max_root_pos = prev_root;

        position = prev_root;
        prev_root = position - leonardo_nums[subtree_size[position]];
    }
    // O(log n) - время, количество корней

    return max_root_pos;
}


void swap_with_max(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                   const std::vector<size_t> &leonardo_nums, const size_t position) {
    const size_t max_root_pos = find_max_root_pos(array, subtree_size, leonardo_nums, position);
    // O(log n) - время, количество корней

    std::swap(array[position], array[max_root_pos]);
    balance_tree(array, subtree_size, leonardo_nums, position);
    // O(log n) - время, просеивание дерева
    balance_tree(array, subtree_size, leonardo_nums, max_root_pos);
    // O(log n) - время, просеивание дерева
}


void smooth_sort(std::vector<long long> &array) {
    if (array.size() <= 1)
        return;

    const size_t array_length = array.size();
    std::vector<size_t> leonardo_nums = create_leonardo_numbers(array_length);
    // время и память O(n)
    std::vector<size_t> subtree_size(array_length);
    // время и память O(n)

    build_heap(array, subtree_size, leonardo_nums);
    // O(n * log n) - время

    for (size_t i = array_length - 2; i >= 0; --i) {
        swap_with_max(array, subtree_size, leonardo_nums, i);
        if (i == 0)
            break;
    }
    // O(n * log n) - время

    // O(n * log n) - худшее время
    // O(n) - среднее и лучшее время
    // O(n) - память
}


std::pair<std::string, double> execute_smooth_sort(const std::string &input) {
    std::vector<long long> v;

    std::istringstream input_ss(input);
    long long tmp;
    while (input_ss >> tmp)
        v.push_back(tmp);

    const size_t start = clock();
    smooth_sort(v);
    const size_t end = clock();

    std::ostringstream output_ss;
    for (const long long &e: v)
        output_ss << e << ' ';

    return {output_ss.str(), (double) (end - start) / CLOCKS_PER_SEC};
}
