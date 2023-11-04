#include <gtest/gtest.h>
#include "../inc/vector.hpp"

TEST(VectorMemberFunctions, DefaultConstructor) {
	ft::vector<int> mine;
	EXPECT_EQ(mine, mine);
}

TEST(VectorMemberFunctions, ExplicitAllocatorConstructor) {
	ft::vector<int, std::allocator<int> > mine((std::allocator<int>()));
	EXPECT_TRUE(mine.empty());
	EXPECT_EQ(mine.size(), 0);
	EXPECT_EQ(mine.capacity(), 0);
}

TEST(VectorMemberFunctions, ExplicitSizeConstructor) {
	ft::vector<int, std::allocator<int> > mine(10);
	EXPECT_FALSE(mine.empty());
	EXPECT_EQ(mine.size(), 10);
	EXPECT_EQ(mine.capacity(), 10);
}

TEST(VectorMemberFunctions, AssignOperator) {
    int arr[] = {1, 2, 3, 4, 5};
    ft::vector<int, std::allocator<int> > mine;
    mine.assign(arr, arr + 5);

	EXPECT_FALSE(mine.empty());
	EXPECT_EQ(mine.size(), 5);
	EXPECT_EQ(mine.capacity(), 5);

	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(mine[i], arr[i]);}
}

TEST(VectorMemberFunctions, AssignCount) {
    ft::vector<int, std::allocator<int> > mine;
    mine.assign(10, 42);

	EXPECT_FALSE(mine.empty());
	EXPECT_EQ(mine.size(), 10);
	EXPECT_EQ(mine.capacity(), 10);

	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(mine[i], 42);}
}

TEST(Vector, size) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	EXPECT_EQ(10000, mine.size());
}

TEST(Vector, capacity) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	EXPECT_EQ(mine.capacity(), mine.capacity());
}

TEST(Vector, copyConstructor) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	ft::vector<int> copy(mine);
	EXPECT_EQ(copy.size(), mine.size());
}

TEST(Vector, operatorEqual) {
	ft::vector<int> mine;
	ft::vector<int> copy;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	copy = mine;
	EXPECT_EQ(copy.size(), mine.size());
}

TEST(Vector, GetAllocatorCopyCanBeUsedToAllocateMemory) {
    // Create a vector and get a copy of its allocator
    ft::vector<int> vec(10, 42);
    auto alloc_copy = vec.get_allocator();
    
    // Use the allocator copy to allocate some memory and check that it works
    int* ptr = alloc_copy.allocate(5);
    EXPECT_NE(ptr, nullptr);
    alloc_copy.deallocate(ptr, 5);
}

TEST(Vector, GetAllocatorCopyCanBeUsedToConstructNewVector) {
    // Create a vector and get a copy of its allocator
    ft::vector<int> vec(10, 42);
    auto alloc_copy = vec.get_allocator();
    
    // Use the allocator copy to construct a new vector and check that it works
    ft::vector<int> new_vec(alloc_copy);
    EXPECT_EQ(new_vec.size(), 0);
    EXPECT_EQ(new_vec.capacity(), 0);
    EXPECT_EQ(new_vec.get_allocator(), alloc_copy);
}

/*Elements Access*/
TEST(VectorElementsAccess, AtOutOfRange) {
	ft::vector<int> vec(5);
	EXPECT_THROW(vec.at(5), std::out_of_range);
}

TEST(VectorElementsAccess, AtInRange) {
	ft::vector<int> vec(5, 42);
	EXPECT_EQ(vec.at(3), 42);
}

TEST(VectorElementsAccess, AtConstOutOfRange) {
	const ft::vector<int> vec(5);
	EXPECT_THROW(vec.at(5), std::out_of_range);
}

TEST(VectorElementsAccess, OperatorBracket) {
  // Test accessing an element in a non-empty vector.
  ft::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);

  // Test modifying an element.
  vec[3] = 42;
  EXPECT_EQ(vec[3], 42);
}

TEST(VectorElementsAccess, FrontNonEmptyVector) {
  ft::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorElementsAccess, BackNonEmptyVector) {
  ft::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v.back(), 3);
}

TEST(VectorElementsAccess, DataExpectedAddress) {
	ft::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(&v[0], v.data());
}

TEST(VectorElementsAccess, DataConstExpectedAddress) {
	ft::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	const ft::vector<int> vec(v);
	EXPECT_EQ(&vec[0], vec.data());
}

/*Iterators*/
TEST(Vector, begin) {
	ft::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);}
	EXPECT_EQ(*v.begin(), 0);
}

TEST(Vector, beginWithEmptyVector) {
	ft::vector<int> v;
	EXPECT_EQ(v.begin(), v.end());
}

TEST(Vector, const_begin) {
	ft::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);}
	const ft::vector<int> c(v);
	EXPECT_EQ(*c.begin(), 0);
}

// Test fixture for the ft::vector class
class VectorIterators : public ::testing::Test {
 protected:
  virtual void SetUp() {
    // Create a test vector with some elements
    for (int i = 1; i <= 3; i++) {
      vector_.push_back(i);
    }
  }

  // Declare your ft::vector object here
  ft::vector<int> vector_;
};

// Test the non-const version of begin()
TEST_F(VectorIterators, TestBegin) {
  EXPECT_EQ(1, *vector_.begin());
}

// Test the const version of begin()
TEST_F(VectorIterators, TestConstBegin) {
  const ft::vector<int>& const_vector = vector_;
  EXPECT_EQ(1, *const_vector.begin());
}

// Test the non-const version of end()
TEST_F(VectorIterators, TestEnd) {
  EXPECT_EQ(3, *(--vector_.end()));
}

// Test the const version of end()
TEST_F(VectorIterators, TestConstEnd) {
  const ft::vector<int>& const_vector = vector_;
  EXPECT_EQ(3, *(--const_vector.end()));
}

// Test the non-const version of rbegin()
TEST_F(VectorIterators, TestRBegin) {
  EXPECT_EQ(3, *vector_.rbegin());
}

// Test the const version of rbegin()
TEST_F(VectorIterators, TestConstRBegin) {
  const ft::vector<int>& const_vector = vector_;
  EXPECT_EQ(3, *const_vector.rbegin());
}

// Test the non-const version of rend()
TEST_F(VectorIterators, REnd) {
  EXPECT_EQ(1, *(--vector_.rend()));
}

// Test the const version of rend()
TEST_F(VectorIterators, ConstREnd) {
  const ft::vector<int>& const_vector = vector_;
  EXPECT_EQ(1, *(--const_vector.rend()));
}

/*Capacity*/

TEST(VectorCapacity, Reserve) {
	// Create a vector with some elements
	ft::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);}


	// Reserve new capacity
	vec.reserve(20);

	// Verify capacity has been updated
	EXPECT_EQ(20, vec.capacity());

	// Verify elements are unchanged
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(i, vec[i]);}
}

TEST(VectorCapacity, InsertInMiddle) {
  ft::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(4);
  vec.push_back(5);

  ft::vector<int>::iterator it = vec.begin() + 2;
  vec.insert(it, 3);

  ASSERT_EQ(vec.size(), 5);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 3);
  ASSERT_EQ(vec[3], 4);
  ASSERT_EQ(vec[4], 5);
}

/*Modifiers*/
TEST(VectorModifiers, push_back_once) {
	ft::vector<int> mine;
	mine.push_back(3);
	EXPECT_EQ(mine, mine);
}

TEST(VectorModifiers, push_back_break) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);
	}
	EXPECT_EQ(mine, mine);
}

/*Non-Member Functions*/

TEST(VectorNonMembers, LessThanOperator) {
	ft::vector<int> vec1;
	ft::vector<int> vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	vec2.push_back(1);
	vec2.push_back(3);

	EXPECT_TRUE(vec2 < vec1);
	EXPECT_FALSE(vec1 < vec2);
}

TEST(VectorNonMembers, LessThanOrEqualOperator) {
	ft::vector<int> vec1;
	ft::vector<int> vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);

	EXPECT_EQ(vec1.size(), vec2.size());
	EXPECT_TRUE(vec2 <= vec1);
	EXPECT_TRUE(vec1 <= vec2);

	vec2.push_back(4);

	EXPECT_TRUE(vec1 <= vec2);
	EXPECT_FALSE(vec2 <= vec1);
}

TEST(VectorNonMembers, GreaterThanOperator) {
	ft::vector<int> vec1;
	ft::vector<int> vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	vec2.push_back(1);
	vec2.push_back(3);

	EXPECT_TRUE(vec1 > vec2);
	EXPECT_FALSE(vec2 > vec1);
}

TEST(VectorNonMembers, GreaterThanOrEqualOperator) {
	ft::vector<int> vec1;
	ft::vector<int> vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);

	EXPECT_TRUE(vec1 >= vec2);
	EXPECT_TRUE(vec2 >= vec1);

	vec2.push_back(4);

	EXPECT_TRUE(vec2 >= vec1);
	EXPECT_FALSE(vec1 >= vec2);
}