#include "execute.h"

std::string string_from_file(const std::string &input_file_name) {
    std::ifstream input_file;
    input_file.open(input_file_name);
    std::string line;
    std::string tmp;
    while (input_file >> tmp) {
        line += tmp + ' ';
    }
    input_file.close();
    return line;
}

void string_to_file(const std::string &line, const std::string &output_file_name) {
    std::ofstream output_file;
    output_file.open(output_file_name);
    output_file << line;
    output_file.close();
}


bool check_answer(const std::string &answer_file_name, const std::string &prog_result_file_name,
                  bool (&compare_function)(const std::string &, const std::string &)) {
    const std::string answer = string_from_file(answer_file_name);
    const std::string prog_result = string_from_file(prog_result_file_name);
    return compare_function(answer, prog_result);
}


std::pair<bool, double> test(const size_t i,
                             std::pair<std::string, double> (&exec_function)(const std::string &),
                             const std::string &test_path,
                             bool (&compare_function)(const std::string &, const std::string &)) {
    const std::string input_file_name = test_path + "test" + std::to_string(i) + ".txt";
    const std::string output_file_name = test_path + "output" + std::to_string(i) + ".txt";

    const std::string input = string_from_file(input_file_name);

    const std::pair<std::string, double> result = exec_function(input);

    string_to_file(result.first, output_file_name);

    const std::string answer_file_name = test_path + "answer" + std::to_string(i) + ".txt";
    const std::string prog_result_file_name = test_path + "output" + std::to_string(i) + ".txt";

    return {check_answer(answer_file_name, prog_result_file_name, compare_function), result.second};
}

void print_result(const std::pair<bool, double> result, const size_t i) {
    std::cout << "TEST " << i << ": " << (result.first ? "OK" : "WRONG ANSWER") << std::endl;
    std::cout << "TIME: " << result.second << " SECONDS" << std::endl << std::endl;
}

void tester(const size_t file_count,
            std::pair<std::string, double> (&exec_function)(const std::string &),
            const std::string &test_path,
            bool (&compare_function)(const std::string &, const std::string &)) {
    size_t right_answers = 0;

    for (size_t i = 0; i < file_count; i++) {
        std::pair<bool, double> result = test(i, exec_function, test_path, compare_function);
        print_result(result, i);
        right_answers += result.first;
    }
    std::cout << "Right answers: " << right_answers << "/" << file_count << std::endl;
}
