#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>


std::vector<int> label_encoding(const std::string& filename) {
    std::ifstream InputFile(filename);
    int size; // +4
    InputFile >> size;

    std::vector<std::string> arr(size);
    for (int i = 0; i < size; i++) {
        // +4 только внутри цикла
        InputFile >> arr[i];
    }
    // для arr: 4 + n*len(str)
    std::vector<int> T; // n*4
    std::unordered_map<std::string, int> labelencoder; ////кол-во уникальных строк *(len(string)+4)
    int cur_ind = 0;// +4

    for (int i = 0; i < size; i++) {
        // +4 только внутри цикла
        if (labelencoder[arr[i]] == 0) {
            labelencoder[arr[i]] = cur_ind + 1;
            cur_ind += 1;
        }
        T.push_back(labelencoder[arr[i]]);
    }

    return T;
}


void run_test(const std::string& test_name, const std::string& input_data, const std::vector<int>& expected_output) {
    std::ofstream outputFile("utpput1.txt");

    outputFile << input_data;
    outputFile.close();

    std::vector<int> actual_output = label_encoding("input1.txt");

    if (actual_output == expected_output) {
        std::cout << test_name << " passed!" << std::endl;
    } else {
        std::cout << "Failed " << test_name << "!" << std::endl;
        std::cout << "Expected: ";
        for (int val : expected_output) std::cout << val << " ";
        std::cout << std::endl;

        std::cout << "Output: ";
        for (int val : actual_output) std::cout << val << " ";
        std::cout << std::endl;
    }
}

void test_label_encoding() {
    // Тест 1: Простой случай (каждая строка с новой строки)
    std::string input_data1 = "5\norange\nlemon\nbanana\norange\nlemon";
    std::vector<int> expected_output1 = {1, 2, 3, 1, 2};
    run_test("Test 1", input_data1, expected_output1);

    // Тест 2: Все уникальные строки (все строки через пробелы)
    std::string input_data2 = "4\ncat dog fish bird";
    std::vector<int> expected_output2 = {1, 2, 3, 4};
    run_test("Test 2", input_data2, expected_output2);

    // Тест 3: Повторяющиеся строки (с новой строки)
    std::string input_data3 = "4\none\none\none\none";
    std::vector<int> expected_output3 = {1, 1, 1, 1};
    run_test("Test 3", input_data3, expected_output3);

    // Тест 4: Смешанные строки (с новой строки)
    std::string input_data4 = "6\ncar\nbike\ncar\nplane\nbike\ncar";
    std::vector<int> expected_output4 = {1, 2, 1, 3, 2, 1};
    run_test("Test 4", input_data4, expected_output4);

    // Тест 5: Пустой тест
    std::string input_data5 = "0";
    std::vector<int> expected_output5 = {};
    run_test("Test 5", input_data5, expected_output5);
}

int main() {
    test_label_encoding();
    // label_encoding memory: 12 + n*len(str) + n*4
    // + кол-во уникальных строк *(len(string)+4)
    return 0;
    //
}
