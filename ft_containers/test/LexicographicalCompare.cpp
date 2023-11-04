#include <gtest/gtest.h>
#include "../inc/lexicographical_compare.hpp"

TEST(LexicographicalCompare, DifferentIntVectorCompare) {
	std::vector<int> c = {1, 2, 3};
	std::vector<int> d = {1, 2, 4};
	EXPECT_TRUE(ft::lexicographical_compare(c.begin(), c.end(), d.begin(), d.end()));
}

TEST(LexicographicalCompare, DifferentStringVectorCompare) {
	std::vector<std::string> c = {"Salut", "Bonjour", "Aurevoir"};
	std::vector<std::string> d = {"Salut", "Bonjour", "Aurevoir2"};
	EXPECT_TRUE(ft::lexicographical_compare(c.begin(), c.end(), d.begin(), d.end()));
}

TEST(LexicographicalCompare, SameStringVectorCompare) {
	std::vector<std::string> c = {"Salut", "Bonjour", "Aurevoir"};
	std::vector<std::string> d = {"Salut", "Bonjour", "Aurevoir"};
	EXPECT_FALSE(ft::lexicographical_compare(c.begin(), c.end(), d.begin(), d.end()));
}