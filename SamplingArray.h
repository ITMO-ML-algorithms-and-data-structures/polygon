#pragma once

#include <vector>
#include <string>

#define LOG(x) std::cout << x << std::endl

std::vector<int> SamplingArray(const std::string& path, const int newSize);
