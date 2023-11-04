#include <gtest/gtest.h>
#include "../inc/pair.hpp"

TEST(Pair, DefaultConstructor) {
	ft::pair<int, int> a;
	EXPECT_EQ(a, a);
}

TEST(Pair, CopyConstructor) {
	ft::pair<int, int> a(1, 2);
	ft::pair<int, int> b(a);
	EXPECT_EQ(a, b);
}

TEST(Pair, FirstConstructor) {
	ft::pair<int, int> a(1);
	ft::pair<int, int> b(a);
	EXPECT_EQ(a, b);
}

TEST(Pair, Constructor) {
	ft::pair<int, int> a(1, 2);
	EXPECT_EQ(a, a);
}

TEST(Pair, Swap) {
	ft::pair<int, int> a(1, 2);
	ft::pair<int, int> c(5, 3);
	ft::pair<int, int> tmp(a);
	c.swap(a);
	EXPECT_EQ(tmp, c);
}