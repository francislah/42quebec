#include <gtest/gtest.h>
#include "../inc/stack.hpp"

TEST(Stack, DefaultConstructor) {
	ft::stack<float, int> a;
	EXPECT_EQ(a, a);
	EXPECT_EQ(0, a.getKey());
	EXPECT_EQ(0, a.getValue());
}

TEST(Stack, CopyConstructor) {
	ft::stack<int, int> a;
	ft::stack<int, int> b(a);
	EXPECT_EQ(b, a);
}

TEST(Stack, KeyConstructor) {
	ft::stack<double, int> a(1);
	EXPECT_EQ(1, a.getKey());
	EXPECT_EQ(0, a.getValue());
}

TEST(Stack, Constructor) {
	ft::stack<char, int> a(1, 4);
	EXPECT_EQ(1, a.getKey());
	EXPECT_EQ(4, a.getValue());
}

// TEST(Stack, Allocator) {
// 	ft::stack<int, int> a(1, 4);
// 	EXPECT_TRUE((std::is_same<ft::allocator<ft::pair<int, int>>, decltype(a.get_allocator())>::value));
// }
