#include <gtest/gtest.h>
#include "../inc/map.hpp"

TEST(Map, DefaultConstructor) {
	ft::map<float, int> a;
	EXPECT_EQ(a, a);
	EXPECT_EQ(0, a.getKey());
	EXPECT_EQ(0, a.getValue());
}

TEST(Map, CopyConstructor) {
	ft::map<int, int> a;
	ft::map<int, int> b(a);
	EXPECT_EQ(b, a);
}

TEST(Map, KeyConstructor) {
	ft::map<double, int> a(1);
	EXPECT_EQ(1, a.getKey());
	EXPECT_EQ(0, a.getValue());
}

TEST(Map, Constructor) {
	ft::map<char, int> a(1, 4);
	EXPECT_EQ(1, a.getKey());
	EXPECT_EQ(4, a.getValue());
}

TEST(Map, Allocator) {
	ft::map<int, int> a(1, 4);
	EXPECT_TRUE((std::is_same<ft::allocator<ft::pair<int, int>>, decltype(a.get_allocator())>::value));
}
