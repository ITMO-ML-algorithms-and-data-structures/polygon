#pragma once

#include <vector>

class Sort {
public:
    Sort() = delete;

    static void CocktailShaker(std::vector<int>& data);
    static void Heap(std::vector<int>& data);
    static void Bucket(std::vector<int  >& data, int numBuckets);
    static void Insertion(std::vector<int>& data);

private:
    static void Heapify(std::vector<int>& data, int currentSize, int currentNode);

    static int GetMaxValue(const std::vector<int>& data);
    static int GetMinValue(const std::vector<int>& data);
};
