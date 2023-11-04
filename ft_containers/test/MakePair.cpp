#include <gtest/gtest.h>
#include "../inc/make_pair.hpp"

TEST(MakePair, IntPair) {
	
	ft::pair<int, int> a = ft::make_pair(1,2);
	ft::pair<int, int> b(1, 2);
	EXPECT_EQ(a, b);
}