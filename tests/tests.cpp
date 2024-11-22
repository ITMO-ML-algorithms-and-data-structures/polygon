#include <mlpack.hpp>
#include <gtest/gtest.h>
#include "../Binarizer.h"


class BinarizerFixture : public testing::Test
{
protected:
    int n_thresholds;
    Binarizer<double> binarizer = Binarizer<double>(4);
    arma::mat dataset;
    arma::vec target;

    void SetUp() override
    {
        n_thresholds = 3;
        dataset = arma::mat{
            {1.0, 2.0, 3.0},
            {4.0, 5.0, 6.0},
            {7.0, 8.0, 9.0}
        };
        target = arma::vec{1, 0, 1};
    }

    void TearDown() override
    {
        // Teardown code goes here
    }
};

TEST_F(BinarizerFixture, FindThresholdsTest)
{
    binarizer.find_thresholds(dataset);

    arma::mat expected = arma::mat{
        {2.5, 3.5, 4.5},
        {4.0, 5.0, 6.0},
        {5.5, 6.5, 7.5}
    };

    ASSERT_TRUE(arma::approx_equal(
        binarizer.get_thresholds(), expected, "absdiff", 1e-5
    ));
}

TEST_F(BinarizerFixture, TestTransformWithGivenThresholds)
{
    arma::vec thresholds = {4.0, 5.0, 6.0};
    arma::mat binarized_dataset = binarizer.transform_with_given_thresholds(dataset, thresholds);

    arma::mat expected_data = arma::mat{
        {0, 0, 0},
        {0, 0, 0},
        {1, 1, 1}
    };

    ASSERT_TRUE(arma::approx_equal(
        binarized_dataset, expected_data, "absdiff", 1e-5
    ));
}

TEST_F(BinarizerFixture, TestFit) {
    // Проверяем, что оптимальные пороги корректно определяются
    binarizer.fit(dataset, target);

    ASSERT_EQ(binarizer.get_optimal_thresholds().n_rows, dataset.n_cols);
}

TEST_F(BinarizerFixture, TestFitTransform) {
    // Проверяем, что fit_transform работает корректно
    arma::mat binarized_dataset = binarizer.fit_transform(dataset, target);

    ASSERT_EQ(binarized_dataset.n_rows, dataset.n_rows);
    ASSERT_EQ(binarized_dataset.n_cols, dataset.n_cols);
}

TEST_F(BinarizerFixture, TestThresholdInitialization) {
    // Проверяем корректность начальной инициализации порогов
    binarizer.find_thresholds(dataset);

    for (size_t col_index = 0; col_index < dataset.n_cols; ++col_index) {
        arma::vec col = dataset.col(col_index);
        double min_value = col.min();
        double max_value = col.max();

        for (size_t threshold_index = 0; threshold_index < n_thresholds; ++threshold_index) {
            double expected_threshold = min_value + (threshold_index + 1) * (max_value - min_value) / (n_thresholds + 1);
            ASSERT_NEAR(binarizer.get_thresholds()(threshold_index, col_index), expected_threshold, 1e-5);
        }
    }
}