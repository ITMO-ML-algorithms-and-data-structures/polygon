#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "../execute.h"
#include "../generate_dataset.cpp"
#include "binary_insertion_sort.h"
#include "smooth_sort.h"
#include "counting_sort.h"


bool compare_function(const std::string &s1, const std::string &s2) { return s1 == s2; }


void create_answer(const std::string &test_name, const std::string &anwer_name) {
    std::vector<long long> v;

    std::istringstream input_ss(string_from_file(test_name));
    long long tmp;
    while (input_ss >> tmp)
        v.push_back(tmp);

    std::sort(v.begin(), v.end());

    std::ostringstream output_ss;
    for (const long long &e: v)
        output_ss << e << ' ';
    string_to_file(output_ss.str(), anwer_name);
}


void check_correctness(std::pair<std::string, double> (&exec_funcion)(const std::string &), const size_t start_length,
                       const size_t step, const size_t count) {
    size_t lenght = start_length;
    for (int i = 0; i < count; ++i) {
        generate_integer_dataset_to_file(lenght, "test" + std::to_string(i) + ".txt");
        create_answer("test" + std::to_string(i) + ".txt", "answer" + std::to_string(i) + ".txt");
        lenght += step;
    }
    tester(count, exec_funcion, "", compare_function);
}


void check_speed(std::pair<std::string, double> (&exec_funcion)(const std::string &), const size_t start_length,
                 size_t step, const size_t count) {
    size_t lenght = start_length;
    for (int i = 0; i < count; ++i) {
        generate_integer_dataset_to_file(lenght, "test0.txt");
        std::cout << lenght
                << ' ' << test(0, exec_funcion, "", compare_function).second
                << std::endl;
        lenght += step;
    }
}


int main() {
    // check_correctness(execute_counting_sort, 1e5, 1e5, 10);
    check_speed(execute_counting_sort, 1e5, 0, 50);
}
