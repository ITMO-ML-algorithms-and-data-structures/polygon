#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../execute.h"
#include "binary_insertion_sort.h"
#include "../generate_dataset.cpp"

bool compare_function(const std::string &s1, const std::string &s2) {
    return s1 == s2;
}

int main() {
    for (int i = 1000; i <= 1000; i += 100000) {
        std::vector<long long> dataset = generate_integer_dataset(i);

        std::ofstream dataset_file( "test0.txt");
        for (const long long &j: dataset) {
            dataset_file << j << " ";
        }
        dataset_file.close();
        sort(dataset.begin(), dataset.end());

        std::ofstream answer_file("answer0.txt");
        for (const long long &j: dataset) {
            answer_file << j << " ";
        }
        answer_file.close();

        tester(1, execute_binary_insertion_sort, "", compare_function);
    }
}
