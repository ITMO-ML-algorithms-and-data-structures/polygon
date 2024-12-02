#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <random>

#ifndef LAB_TESTS_H
#define LAB_TESTS_H

std::random_device _tests_random_device;
std::default_random_engine _tests_random(_tests_random_device());
std::vector<int> _loaded_vector;

void check_results(std::vector<int> expected, std::vector<int> value, std::string test_name)
{
    if (value == expected) 
    {
        std::cout << "[" << test_name << "] PASSED" << std::endl;
    } 
    else 
    {
        std::cout << "[" << test_name <<"] FAILED" << std::endl;
    }
}

void load_vector_from_file()
{
    _loaded_vector.clear();
    std::ifstream fin;
    fin.open("numbers.tsv");
    if (!fin.is_open())
    {
        std::cout << "eror: file didn't opened";
    }
    std::string stri;
    while (!fin.eof())
    {
        std::getline(fin, stri);
    }
    fin.close();
    std::string current_string;
    int current_digit;
    for(int i=0; i < stri.size(); i++)
    {
        if(stri[i]!=';')
        {
            current_string += stri[i];
        }
        else
        {
            current_digit = std::stoi(current_string);
            current_string = "";
            _loaded_vector.push_back(current_digit);
        }
    }
}

std::vector<int> get_data_for_sort()
{
    if (size(_loaded_vector) == 0) {
        load_vector_from_file();
    }
    return _loaded_vector;
}

#endif