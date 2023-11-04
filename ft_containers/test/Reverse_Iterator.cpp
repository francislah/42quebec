#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../inc/reverse_iterator.hpp"

TEST(ReverseIteratorMemberFunctions, OperatorBracket) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::reverse_iterator<std::vector<int>::iterator> rit(v.end());

  EXPECT_EQ(rit[0], 5);
  EXPECT_EQ(rit[1], 4);
  EXPECT_EQ(rit[2], 3);
  EXPECT_EQ(rit[3], 2);
  EXPECT_EQ(rit[4], 1);
}