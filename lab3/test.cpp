#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>

#include <sstream>

#include <unordered_map>

#include <string>
#include <vector>

#include <cstdint>

#include <fstream>

#include <random>

using namespace std;

#define ASSERT_MSG(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << "." << std::endl; \
            std::cerr << "Error in test: " << message << std::endl; \
            std::abort(); \
        } \
    } while (false)

bool genBin(double chance) {

    if (chance == 1) {
        return true;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double randomValue = dis(gen);

    if (randomValue < chance) {
        return true;
    }
    else {
        return false;
    }
}

void solve(vector<string>& res, std::istream & in = std::cin, std::ostream & out = std::cout) {

    string input; //O(1)

    int size; //O(1)
    double k; //O(1)

    in >> size; //O(1)
    in >> k; //O(1)

    int cnt = 0; //O(1)
    int original_k = k; //O(1)

    while (in >> input) { //O(N), N = size

        double chance = k / size; //O(1)

        if (genBin(chance) && (cnt < original_k)) { //O(1)
            //cout << input << ' ';
            cnt += 1; //O(1)
            k -= 1; //O(1)

            res.push_back(input); //O(1)
        }
        size -= 1; //O(1)

        if (cnt == original_k) {
            break;
        }
    }

    // сложность алгоритма - O(N) в худшем случае
    // O(K) в среднем случае; K - распределено от 1 до N. (преждевременный break если уже взяли k элементов)

}

vector<string> run(const std::string & input) {

    stringstream in(input);
    stringstream out;

    vector <string> res;

    solve(res, in, out);

    return res;
}

void get_full(vector<string>& res, std::istream& in = std::cin) {

    string input;

    while (in >> input) {
        res.push_back(input);
    }

}

vector<string> run_full(const std::string& input) {

    stringstream in(input);

    vector <string> full;

    get_full(full, in);

    return full;
}

bool isSubvector(vector<string>& mainVec, vector<string>& subVec) {

    unordered_map<string, int> mainCount;
    unordered_map<string, int> subCount;

    for (string num : mainVec) {
        mainCount[num]++;
    }

    for (string num : subVec) {
        subCount[num]++;
    }

    // Сортировка подсчетом

    for (auto pair : subCount) {
        string el = pair.first;
        int cnt = pair.second;

        if (mainCount[el] < cnt) {
            return false;
        }
    }

    return true;
}

void test() {

    ifstream file3("ids_output.txt");
    ifstream file2("inp.txt");

    string small_test((istreambuf_iterator<char>(file3)),
        istreambuf_iterator<char>());
    string big_test((istreambuf_iterator<char>(file2)),
        istreambuf_iterator<char>());

    file3.close();
    file2.close();

    struct {
        string input;
    } tests[] = {
        {big_test},
        {small_test},
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        auto t = tests[i];

        vector<string> out = run(t.input);

        vector<string> full = run_full(t.input);

        ASSERT_MSG(isSubvector(full, out), i + 1);
    }

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}

//