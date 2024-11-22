#ifndef SMOOTH_SORT_H
#define SMOOTH_SORT_H

#include <cstddef>
#include <sstream>
#include <vector>


std::vector<size_t> create_leonardo_numbers(const size_t n);


void balance_tree(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                  const std::vector<size_t> &leonardo_nums, const size_t position);


void sort_roots(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums, size_t position);


void build_heap(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                const std::vector<size_t> &leonardo_nums);


size_t find_max_root_pos(const std::vector<long long> &array, const std::vector<size_t> &subtree_size,
                         const std::vector<size_t> &leonardo_nums, size_t position);


void swap_with_max(std::vector<long long> &array, std::vector<size_t> &subtree_size,
                   const std::vector<size_t> &leonardo_nums, const size_t position);


void smooth_sort(const std::vector<long long> &input_vector);


std::pair<std::string, double> execute_smooth_sort(const std::string &input);

#endif // SMOOTH_SORT_H
