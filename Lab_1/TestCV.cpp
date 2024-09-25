#include "TestCV.h"

void TestBuildUnique()
{
    std::vector<std::vector<std::string>> text =
    {
        {"hello", "hello", "world"},
        {"!", "world", "hello"}
    };
    std::set<std::string> expected = { "hello", "world", "!" };
    std::set<std::string> result = BuildUnique(text);
    CU_ASSERT_EQUAL(result.size(), expected.size());
    for (const std::string& word : expected)
    {
        CU_ASSERT(result.find(word) != result.end());
    }
}

void TestSplittingWords()
{
    std::string text = "Hello world World ! heLlo";
    std::vector<std::string> expected = { "hello", "world", "world", "!", "hello" };
    std::vector<std::string> result = SplittingWords(text);
    CU_ASSERT_EQUAL(result.size(), expected.size());
    for (int i = 0; i < result.size(); i++)
    {
        CU_ASSERT_STRING_EQUAL(result[i].c_str(), expected[i].c_str());
    }
}

void TestBuildCountMatrix()
{
    std::vector<std::vector<std::string>> text = {
        {"hello", "world", "its"},
        {"world", "!"}
    };
    std::set<std::string> vocabulary = {"!", "hello", "its", "world"};
    std::vector<std::vector<int>> expected = {
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };
    std::vector<std::vector<int>> result = BuildCountMatrix(text, vocabulary);
    CU_ASSERT_EQUAL(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        CU_ASSERT_EQUAL(result[i].size(), expected[i].size());
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            CU_ASSERT_EQUAL(result[i][j], expected[i][j]);
        }
    }
}