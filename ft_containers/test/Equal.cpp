#include <gtest/gtest.h>
#include "../inc/equal.hpp"

TEST(Equal, SameIntVector) {
	std::vector<int> c = {1, 2, 3};
	std::vector<int> d = {1, 2, 3};
	EXPECT_TRUE(ft::equal(c.begin(), c.end(), d.begin(), d.end()));
}

TEST(Equal, DifferentSizeFloatVector) {
	std::vector<float> c = {1, 2, 3};
	std::vector<float> d = {1, 2};
	EXPECT_FALSE(ft::equal(c.begin(), c.end(), d.begin(), d.end()));
}