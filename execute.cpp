#include "execute.h"
#include <fstream>
#include <iostream>


void execute_str_to_str_function(std::string &input_file_name, std::string &output_file_name,
                                 std::string (&exec_function)(const std::string &)) {
    std::ifstream input_file;
    input_file.open(input_file_name);
    std::string line;
    std::string tmp;
    while (input_file >> tmp) {
        line += tmp + ' ';
    }
    input_file.close();

    line = exec_function(line);

    std::ofstream output_file;
    output_file.open(output_file_name);
    output_file << line;
    output_file.close();
}


bool check_answer(std::string &answer_file_name, std::string &prog_result_file_name,
                  bool (&compare_function)(const std::string &, const std::string &)) {
    std::ifstream answer_file, prog_result_file;
    answer_file.open(answer_file_name);
    prog_result_file.open(prog_result_file_name);
    std::string answer, prog_result, tmp;
    while (answer_file >> tmp) {
        answer += tmp + ' ';
    }
    while (prog_result_file >> tmp) {
        prog_result += tmp + ' ';
    }
    answer_file.close();
    prog_result_file.close();

    if (compare_function(answer, prog_result)) {
        std::cout << "OK" << std::endl;
        return true;
    }
    std::cout << "WRONG ANSWER" << std::endl;
    return false;
}


void tester(const size_t file_count, std::string (&exec_function)(const std::string &), const std::string &test_path,
            bool (&compare_function)(const std::string &, const std::string &)) {
    size_t right_answers = 0;

    for (int i = 0; i < file_count; i++) {
        std::string input_file_name = test_path + "test" + std::to_string(i) + ".txt"; // O(1)
        std::string output_file_name = test_path + "output" + std::to_string(i) + ".txt"; // O(1)
        execute_str_to_str_function(input_file_name, output_file_name, exec_function);

        std::string answer_file_name = test_path + "answer" + std::to_string(i) + ".txt";
        std::string prog_result_file_name = test_path + "output" + std::to_string(i) + ".txt";

        std::cout << "TEST " << i << ": ";

        check_answer(answer_file_name, prog_result_file_name, compare_function) ? right_answers++ : 0;
    }

    std::cout << "Right answers: " << right_answers << "/" << file_count << std::endl;
}
