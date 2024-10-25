#include <gtest/gtest.h>
#include <vector>
#include "../MersenneTwister.h"
#include "../UniformDistribution.h"
#include <ctime>
#include <cmath>

typedef long long ll;

class MersenneTwisterFixture: public testing::Test {
protected:
    MersenneTwister gen = MersenneTwister(std::time(nullptr));
    UniformDistribution dis = UniformDistribution(1, 100);

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(MersenneTwisterFixture, UniformDistributionTest) {
    for (int i=0; i < 1000; i++) {
        unsigned int random_number = dis(gen);
        ASSERT_TRUE(random_number >= 1 && random_number <= 100);
    }
}

TEST_F(MersenneTwisterFixture, UniformDistributionForCustomMinMaxValuesTest) {
    dis.set_min_max_values(-111, -17);
    for(int i=0; i < 1000; i++) {
        unsigned int random_number = dis(gen);
        ASSERT_TRUE(random_number >= -111 && random_number <= -17);
    }

    dis.set_min_max_values(1000000, 2000000);
    for(int i=0; i < 1000; i++) {
        unsigned int random_number = dis(gen);
        ASSERT_TRUE(random_number >= 1000000 && random_number <= 2000000);
    }
}

TEST_F(MersenneTwisterFixture, MersenneTwisterWithGivenSeedTest) {
    gen.seed(42);
    std::vector<unsigned int> first = {};
    for (int i=0; i<1000; i++)
        first.push_back(gen());

    gen.seed(42);
    std::vector<unsigned int> second = {};
    for (int i=0; i<1000; i++)
        second.push_back(gen());

    ASSERT_EQ(first, second);

    gen.seed(std::time(nullptr));
}

TEST_F(MersenneTwisterFixture, UniformDistributionChiTest) {
    unsigned int experiments_number = 10000;
    std::vector<unsigned int> counter(100, 0);
    unsigned int expected_count = experiments_number / 100;
    for (int i=0; i<10000; i++) {
        counter[dis(gen) - 1]++;
    }

    double chi_square = 0.0;

    for (auto count: counter) {
        chi_square += (count - expected_count) * (count - expected_count) * 1.0 / expected_count;
    }

    unsigned int df = 99;

    double chi_critical = 124.342;

    ASSERT_LE(chi_square, chi_critical);
}

TEST_F(MersenneTwisterFixture, UniformDistributionChiBiggerDataTest) {
    unsigned int experiments_number = 1000000;
    unsigned int min = 10001, max = 13000;
    dis.set_min_max_values(min, max);
    std::vector<unsigned int> counter(max - min + 1, 0);
    unsigned int expected_count = experiments_number / (max - min - 1);
    for (int i=0; i<experiments_number; i++) {
        counter[dis(gen) - min]++;
    }

    double chi_square = 0.0;

    for (auto count: counter) {
        chi_square += (count - expected_count) * (count - expected_count) * 1.0 / expected_count;
    }

    double chi_critical = 3182.10;

    ASSERT_LE(chi_square, chi_critical);
}