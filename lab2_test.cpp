#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


void read_file(const char* filename, std::set<unsigned long long>& uniqueValues) {
    ifstream file(filename, ios_base::in);

    if (!file.is_open()) {
        std::cerr << "fail ne otkrilsya((" << std::endl;
        return;
    }
    std::string line;

    while (getline(file, line)) {
        for (size_t i = 0; i < line.length(); ++i) {
            if (line[i] == ',') {
             line = line.replace(i, 1, "");
            }
        }
        std::istringstream ss(line);
        unsigned long long number;
        while (ss >> number) {
            uniqueValues.insert(number);
        }
    }

    file.close();
}




int main() {

    std::set<unsigned long long> uniqueValues;
    unsigned long long value;
    read_file("test2.txt", uniqueValues);


    vector<unsigned long long> result;

    for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) {
        result.push_back(*it);
    }

    for (int i = 0; i<result.size();i++){
        if (i < result.size()-1){
            cout << result[i] << ", ";
        }
        else{
            cout << result[i];
        }
    }
    return 0;
}
