#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <unordered_map>

// Function to generate random strings
std::string generate_random_string(size_t length) {
    static const std::string characters = "abcdefghijklmnopqrstuvwxyz";
    static std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

    std::string result;
    for (size_t i = 0; i < length; ++i) {
        result += characters[distribution(generator)];
    }
    return result;
}

int main() {
    // Generate 100 random strings, each of 1000 characters
    std::vector<std::string> random_strings;
    for (int j = 0; j < 100; ++j) {
        random_strings.push_back(generate_random_string(1000));
    }

    // Open the files for saving the output
    std::ofstream strings_file("strings_output.txt");
    std::ofstream ids_file("ids_output.txt");

    if (!strings_file.is_open() || !ids_file.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string s;
    std::string ids;

    // Map to keep track of string to ID mapping
    std::unordered_map<std::string, int> string_to_id;
    int next_id = 1;

    // Append random strings and their ordered IDs for 1e9 iterations
    for (long long i = 0; i < static_cast<long long>(1e3); ++i) {
        // Print progress
        // std::cout << static_cast<double>(i) / 1e9 << std::endl;

        // Choose a random string from the list
        std::string random_string = random_strings[rand() % random_strings.size()];

        // Check if the string already has an ID
        if (string_to_id.find(random_string) == string_to_id.end()) {
            string_to_id[random_string] = next_id++;
        }

        // Append the string and its ID in the format: string string string ...
        s += random_string + ' ';
        ids += std::to_string(string_to_id[random_string]) + ' ';  // IDs are sequential

        // Periodically flush the content to the file to avoid memory issues
        if (i % 100000 == 0) {  // Every 100k iterations
            strings_file << s;
            ids_file << ids;
            s.clear();
            ids.clear();
            strings_file.flush();
            ids_file.flush();
        }
    }

    // Write any remaining content to the files
    strings_file << s;
    ids_file << ids;

    // Close the files
    strings_file.close();
    ids_file.close();

    return 0;
}
