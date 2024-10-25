#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstddef> // для size_t
#include <string> // для std::string

void tester(const size_t file_count, std::string (&exec_function)(const std::string &), const std::string &test_path);
bool check_answer(std::string &answer_file_name, std::string &prog_result_file_name);

void execute_str_to_str_function(std::string &input_file_name, std::string &output_file_name,
                                 std::string (&exec_function)(const std::string &));

#endif
