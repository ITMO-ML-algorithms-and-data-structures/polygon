#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../execute.h"
#include "smooth_sort.h"
#include "../generate_dataset.cpp"

bool compare_function(const std::string &s1, const std::string &s2) {
    return s1 == s2;
}

int main() {
    std::vector<double> times;

    for (int i = 0; i <= 1e6; i += 1000) {
        std::ofstream dataset_file( "test0.txt");
        std::vector<long long> v = generate_integer_dataset(i);
        for (const long long &j : v) {
            dataset_file << j << " ";
        }
        dataset_file.close();

        std::ofstream answer_file("answer0.txt");
        std::sort(v.begin(), v.end());
        for (const long long &j : v) {
            answer_file << j << " ";
        }
        answer_file.close();

        std::cout << i << " " << test(0,execute_smooth_sort,"",compare_function).second << std::endl;

        // tester(1,execute_smooth_sort,
        //         "",
        //         compare_function);
    }

}
