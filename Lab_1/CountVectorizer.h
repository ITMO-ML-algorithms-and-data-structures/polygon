#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <unordered_map>

std::set<std::string> BuildUnique(const std::vector<std::vector<std::string>>& text);
std::vector<std::string> SplittingWords(const std::string& text);
std::vector<std::vector<int>> BuildCountMatrix(const std::vector<std::vector<std::string>>& text, const std::set<std::string>& unique);
std::vector<std::vector<int>> CountVectorizer(const std::string& path);