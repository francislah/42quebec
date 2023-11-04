#include <gtest/gtest.h>
#include "../inc/type_traits.hpp"


// Test is_integral
TEST(IsIntegralTest, Basic) {
	EXPECT_TRUE(ft::is_integral_v<int>);
	EXPECT_TRUE(ft::is_integral_v<short>);
	EXPECT_TRUE(ft::is_integral_v<long>);
	EXPECT_TRUE(ft::is_integral_v<long long>);

	EXPECT_FALSE(ft::is_integral_v<float>);
	EXPECT_FALSE(ft::is_integral_v<double>);
	EXPECT_FALSE(ft::is_integral_v<char*>);
}

// Test enable_if with copy-constructible type
template <typename T>
typename ft::enable_if<std::is_copy_constructible<T>::value>::type
foo(const T&) {
	SUCCEED();
}

TEST(EnableIfTest, CopyConstructibleType) {
	int i = 42;
	foo(i);
}

// Test enable_if with non-copy-constructible type
struct NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator=(const NoCopy&) = delete;
};

template <typename T>
typename ft::enable_if<std::is_copy_constructible<T>::value>::type
bar(const T&) {
	FAIL(); // Should not reach here
}

template <typename T>
typename ft::enable_if<!std::is_copy_constructible<T>::value>::type
bar(const T&) {
	SUCCEED();
}

TEST(EnableIfTest, NonCopyConstructibleType) {
	NoCopy n;
	bar(n);
}

// Test enable_if with non-integral type
template <typename T>
typename ft::enable_if<ft::is_integral<T>::value>::type
baz(const T&) {
	FAIL(); // Should not reach here
}

template <typename T>
typename ft::enable_if<!ft::is_integral<T>::value>::type
baz(const T&) {
	SUCCEED();
}

TEST(EnableIfTest, NonIntegralType) {
	float f = 3.14;
	baz(f);
}