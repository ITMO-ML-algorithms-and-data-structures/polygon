#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H


#include <vector>
#include <sstream>


size_t binary_search(const std::vector<long long> &v, size_t left, size_t right, long long key);

void binary_insertion_sort(std::vector<long long> &v);

std::pair<std::string, double> execute_binary_insertion_sort(const std::string &input);

#endif
