#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>

std::string string_from_file(const std::string &input_file_name);

void string_to_file(const std::string &line, const std::string &output_file_name);


bool check_answer(const std::string &answer_file_name, const std::string &prog_result_file_name,
                  bool (&compare_function)(const std::string &, const std::string &));

std::pair<bool, double> test(const size_t i,
                             std::pair<std::string, double> (&exec_function)(const std::string &),
                             const std::string &test_path,
                             bool (&compare_function)(const std::string &, const std::string &));

void print_result(std::pair<bool, double> result, const size_t i);

void tester(const size_t file_count,
            std::pair<std::string, double> (&exec_function)(const std::string &),
            const std::string &test_path,
            bool (&compare_function)(const std::string &, const std::string &));

#endif
