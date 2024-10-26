#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstddef>
#include <functional>
#include <string>

void tester(
        const size_t file_count, std::string (&exec_function)(const std::string &),
        const std::string &test_path,
        bool (&compare_function)(const std::string &, const std::string &)
        );

bool check_answer(
    std::string &answer_file_name,
    std::string &prog_result_file_name,
    bool (&compare_function)(const std::string &, const std::string &)
    );

void execute_str_to_str_function(
    std::string &input_file_name,
    std::string &output_file_name,
    std::string (&exec_function)(const std::string &)
    );

#endif
