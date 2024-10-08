#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <cassert>
#include <unordered_set>



std::vector<int> make_sample(const std::vector<int>& vec, size_t sample_size) {
    std::vector<int> sample; // O(1)
    sample.reserve(sample_size); // O(sample_size)
    std::sample(vec.begin(), vec.end(), std::back_inserter(sample), sample_size, std::mt19937{ std::random_device{}() }); // сложность - линейная в std::distance(first, last)

    return sample; // O(1)
}


// Simple unit test framework
class TestFramework {
public:
    static void registerTest(const std::string& name, std::function<void()> test) {
        tests.push_back({ name, test });
    }

    static void runTests() {
        for (const auto& t : tests) {
            try {
                t.test();
                std::cout << "Test passed: " << t.name << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Test failed: " << t.name << " - " << e.what() << std::endl;
            }
        }
    }

private:
    struct Test {
        std::string name;
        std::function<void()> test;
    };

    static std::vector<Test> tests;
};

std::vector<TestFramework::Test> TestFramework::tests;

bool is_unique(const std::vector<int>& vec) {
    std::unordered_set<int> seen;
    for (int num : vec) {
        if (seen.find(num) != seen.end()) {
            return false;
        }
        seen.insert(num);
    }
    return true;
}

void test_make_sample() {
    std::vector<int> vec = { 1, 100, 10, 2, 1000000000, 19092312};
    size_t sample_size = 3;

    std::vector<int> sample = make_sample(vec, sample_size);
    assert(sample.size() == sample_size);
    assert(is_unique(sample));
}

void test_make_sample_size_one() {
    std::vector<int> vec = { 1, 2, 3 };
    size_t sample_size = 1;

    std::vector<int> sample = make_sample(vec, sample_size);
    assert(sample.size() == sample_size);
    assert(is_unique(sample));
    assert(std::find(vec.begin(), vec.end(), sample[0]) != vec.end());
}

void test_make_sample_full() {
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    size_t sample_size = 17;

    std::vector<int> sample = make_sample(vec, sample_size);
    assert(sample.size() == sample_size);
    assert(is_unique(sample));
    std::sort(sample.begin(), sample.end());
    assert(sample == vec);
}

void test_make_sample_empty() {
    std::vector<int> vec = {};
    size_t sample_size = 0;

    std::vector<int> sample = make_sample(vec, sample_size);
    assert(sample.size() == sample_size);
}


void test_make_sample_exceed_size() {
    std::vector<int> vec = { 1, 2, 3 };
    size_t sample_size = 5;

    std::vector<int> sample = make_sample(vec, std::min(sample_size, vec.size()));
    assert(sample.size() == vec.size());
}

int main() {
    TestFramework::registerTest("Make sample 1", test_make_sample);
    TestFramework::registerTest("Make sample size one", test_make_sample_size_one);
    TestFramework::registerTest("Make sample full", test_make_sample_full);
    TestFramework::registerTest("Make sample empty", test_make_sample_empty);
    TestFramework::registerTest("Make sample exceed size", test_make_sample_exceed_size);

    TestFramework::runTests();
    return 0;
}
