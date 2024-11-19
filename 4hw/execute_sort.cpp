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
    std::vector<double> times;

    for (int i = 0; i <= 1e6; i += 1000) {
        std::ofstream dataset_file( "test0.txt");
        for (const long long &j: generate_integer_dataset(i)) {
            dataset_file << j << " ";
        }
        dataset_file.close();


        std::cout << i << ' ' << test(0,
                execute_binary_insertion_sort,
                "",
                compare_function).second << std::endl;
    }

}
