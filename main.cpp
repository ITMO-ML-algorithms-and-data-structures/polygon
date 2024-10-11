#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<int> label_encoding(std::istream& input) {
    int size; // +4 байта
    input >> size;

    std::vector<std::string> arr(size); // +24
    for (int i = 0; i < size; i++) {
        //+4 байта только в рамках цикла
        input >> arr[i]; // +32
    }

    std::vector<int> T; // +24
    std::unordered_map<std::string, int> labelencoder; // +56

    int cur_ind = 0; // + 4 байта
    for (int i = 0; i < size; i++) {
        // +4 байта только в рамках цикла
        if (labelencoder[arr[i]] == 0) {
            labelencoder[arr[i]] = cur_ind + 1; //+5
            cur_ind += 1;
        }
        T.push_back(labelencoder[arr[i]]); //+4
    }

    return T;
}

void run_test(const std::string& test_name, const std::string& input_filename, const std::vector<int>& expected_output) {
    std::ifstream inputFile(input_filename);

    std::vector<int> actual_output = label_encoding(inputFile);

    inputFile.close();

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


void create_test_file(const std::string& filename, const std::string& content) {
    std::ofstream testFile(filename);
    testFile << content;
    testFile.close();
}

void test_label_encoding() {
    // Test 1: Simple case
    create_test_file("input1.txt", "5\norange\nlemon\nbanana\norange\nlemon");
    std::vector<int> expected_output1 = {1, 2, 3, 1, 2};
    run_test("Test 1", "input1.txt", expected_output1);

    // Test 2: All unique strings
    create_test_file("input2.txt", "4\ncat\ndog\nfish\nbird");
    std::vector<int> expected_output2 = {1, 2, 3, 4};
    run_test("Test 2", "input2.txt", expected_output2);

    // Test 3: Repeated strings
    create_test_file("input3.txt", "4\none\none\none\none");
    std::vector<int> expected_output3 = {1, 1, 1, 1};
    run_test("Test 3", "input3.txt", expected_output3);

    // Test 4: Mixed strings
    create_test_file("input4.txt", "6\ncar\nbike\ncar\nplane\nbike\ncar");
    std::vector<int> expected_output4 = {1, 2, 1, 3, 2, 1};
    run_test("Test 4", "input4.txt", expected_output4);

    // Test 5: Empty test
    create_test_file("input5.txt", "0");
    std::vector<int> expected_output5 = {};
    run_test("Test 5", "input5.txt", expected_output5);
}

int main() {
    test_label_encoding();

    //memory_size: 4+24+32*n + 24+56+4+5*кол-во уникальных значений + 4*n
    return 0;
}
