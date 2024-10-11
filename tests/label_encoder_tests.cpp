#include <gtest/gtest.h>
#include "../LabelEncoder.h"
#include <vector>
#include <string>


class LabelEncoderFixture: public testing::Test {
protected:
    LabelEncoder<std::string, int> encoder;

    void SetUp() override {
        // Setup code goes here
    }

    void TearDown() override {
        // Teardown code goes here
    }
};

TEST_F(LabelEncoderFixture, FitTest) {
    std::vector<std::string> labels = {"cat", "dog", "dogs", "very big dog", "cat", "cat"};
    encoder.fit(labels);

    EXPECT_EQ(encoder.get_class_count(), 4);
    EXPECT_EQ(encoder.transform_by_one_label("cat"), 0);
    EXPECT_EQ(encoder.transform_by_one_label("very big dog"), 3);
    EXPECT_EQ(encoder.transform_by_one_label("dogs"), 2);
    encoder.clear();
    EXPECT_EQ(encoder.get_class_count(), 0);
}

TEST_F(LabelEncoderFixture, TransformOnVectorsTest) {
    std::vector<std::string> labels = {"cat", "dog", "dogs", "very big dog", "cat", "cat"};
    encoder.fit(labels);
    std::vector<int> result = encoder.transform(labels);

    EXPECT_EQ(encoder.get_class_count(), 4);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[4], 0);
    EXPECT_EQ(result[5], 0);
    EXPECT_EQ(result[2], 2);
    encoder.clear();
    EXPECT_EQ(encoder.get_class_count(), 0);
}

TEST_F(LabelEncoderFixture, FitTransformTest) {
    std::vector<std::string> labels = {"cat", "dog", "dogs", "very big dog", "cat", "cat"};
    std::vector<int> result = encoder.fit_transform(labels);

    EXPECT_EQ(encoder.get_class_count(), 4);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[4], 0);
    EXPECT_EQ(result[5], 0);
    EXPECT_EQ(result[2], 2);
    encoder.clear();
    EXPECT_EQ(encoder.get_class_count(), 0);
}

TEST_F(LabelEncoderFixture, InverseTransformTest) {
    std::vector<std::string> labels = {"cat", "dog", "dogs", "very big dog", "cat", "cat"};
    std::vector<int> result = encoder.fit_transform(labels);
    std::vector<std::string> inverse_result = encoder.inverse_transform(result);

    EXPECT_EQ(encoder.get_class_count(), 4);
    EXPECT_EQ(inverse_result[0], "cat");
    EXPECT_EQ(inverse_result[4], "cat");
    EXPECT_EQ(inverse_result[5], "cat");
    EXPECT_EQ(inverse_result[2], "dogs");
    encoder.clear();
    EXPECT_EQ(encoder.get_class_count(), 0);
}

