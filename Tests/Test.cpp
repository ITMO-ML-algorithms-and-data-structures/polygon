#include "Test.h"

#include <string>
#include <unordered_map>
#include <vector>

#include "CUnit/CUnit.h"

#include "../Utils/Timer.h"

#include "../SamplingArray.h"

void TestArraySize() {
    Timer timer;
    const std::string testFilePath = R"(your/path/to/file.txt)";
    const int newSize = 4;
    const std::vector<int> result = SamplingArray(testFilePath, newSize);
    CU_ASSERT_EQUAL(result.size(), newSize);
}

void TestUniqueValue() {
    Timer timer;
    const std::string testFilePath = R"(your/path/to/file.txt)";
    const int newSize = 4;
    std::vector<int> result = SamplingArray(testFilePath, newSize);

    std::unordered_map<int, int> resultCounts;
    for (int value : result) {
        resultCounts[value]++;
        CU_ASSERT(resultCounts[value] == 1);
    }
}

void TestInvalidPath() {
    Timer timer;
    const std::string testFilePath = R"(your/path/to/file.txt)";
    const int newSize = 4;
    const std::vector<int> result = SamplingArray(testFilePath, newSize);
    CU_ASSERT(result.empty());
}
