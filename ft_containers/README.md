![Testing](https://github.com/FrancisL93/ft_containers/actions/workflows/cmake.yml/badge.svg)

# FT_CONTAINERS
![Containers](.containers.jpg)

## Step 1: Read the subject!
*[Subject Here](en.subject.pdf)*

## Step 2: Set Up A Testing Framework
1-Install cmake

2-Set up cmake with a [CMakeLists.txt](CMakeLists.txt) at project root

3-Build a first simple test
```c++
TEST(Vector, DefaultConstructor) {
	ft::vector<int> mine;
	EXPECT_EQ(mine, mine);}
```
4-Run the test and make the work from the error
```bash
[build] /Users/francislahoud/Documents/ft_containers/test/Vector.cpp:5:2: error: no template named 'vector' in namespace 'ft'; did you mean 'std::vector'?
[build]         ft::vector<int> mine;
```
*Here the test says we don't have a ft::vector defined.
## Step 3: Build the vector class
In file vector.hpp:

```c++
template <typename T>
class vector {
	public:
		vector() {}
		~vector() {}
};
```
Now we get this error, because there is no comparison operator overload for the class.
```bash
error: invalid operands to binary expression ('const ft::vector<int>' and 'const ft::vector<int>')
[build]   if (lhs == rhs) {
```
So we need to implement one outside of the vector class to make it available without calling it from vector.
```c++
template <typename T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
	(void) lhs; (void) rhs;
	return (true);}
```
## Step 3.1: Test it's utility
```c++
TEST(Vector, push_back) {
	ft::vector<int> mine;
	mine.push_back(3);
	EXPECT_EQ(mine, mine);}
```
Add the push_back() member function base on real prototype: void push_back( const T& value ). We will need a size_ member initialized to 4 and a last_ to point to where to place the next push_back().
```c++
template <typename T>
class vector {
	public:
		typedef T value_type;
		typedef std::size_t	size_type;
		vector() : data_(new value_type[4]), last_(0), size_(4) {}
		~vector() {}

		void push_back(const T& value) {
			data_[last_++] = value;}
	private:
		value_type	*data_;
		size_type	last_;
		size_type	size_;
};
```
Make it segfault
```c++
TEST(Vector, push_back_break) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);
	}
	EXPECT_EQ(mine, mine);}
```
Add protections and reallocate memory if necessary:
```c++
void push_back(const T& value) {
			if (last_ == size_) {
				value_type* new_data = new value_type[size_ * 2];
				for (size_type i = 0; i < last_; i++) {
					new_data[i] = data_[i];}
				delete[ ] data_;
				data_ = new_data;
				size_ *= 2;}
			data_[last_++] = value;}
```
Now that we use the new keyword, we need to free the memory on destruction.
We can first run the gtest executable for our test with valgrind. Ex: valgrind ./build/Vector and see we get 65 000+ leaks.
```c++
~vector() {delete data_[ ];}
```
Now Valgrind ./build/Vector will output 0 leaks.
## Step 3.2: Implement size() and capacity() member capacity functions
```c++
size_type size() const {return (size_);}
size_type capacity() const {return (size_);}
```
Test it:
```c++
TEST(Vector, size) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	EXPECT_EQ(mine.size(), mine.size());}
TEST(Vector, capacity) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	EXPECT_EQ(mine.capacity(), mine.capacity());}
```
## Step 3.2: Implement copy constructor
Let's add the the copy constructor and verify orignal.size() to copy.size()
```c++
vector(const vector& other) :
	data_(new value_type[other.size_]), last_(other.last_), size_(other.size_) {
		copy(data_, other.data_);}

private: 
void copy(value_type *data, const value_type* copy) {
	for (size_type i = 0; i < last_; i++) {
		data[i] = copy[i];}}

TEST(Vector, copyConstructor) {
	ft::vector<int> mine;
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		mine.push_back(x++);}
	ft::vector<int> copy(mine);
	EXPECT_EQ(copy.size(), mine.size());}
```
## Step 3.2: Implement operator = overload
```c++
vector& operator=(const vector& other) {
	if (*this != other) {
		delete[ ] data_;
		data_ = new value_type[other.size_];
		copy(data_, other.data_);
		size_ = other.size_;
		last_ = other.last_;
	}
	return (*this);}
```
We will need to reimplement operator == and != non-member functions and realize we need to implement operator [ ] overload as well as iterators. Let's do it simple with juste the [ ] overload:
```c++
reference operator[ ](size_type pos) {return (data_[pos]);}
//Which will need a typedef for reference as the real vector container:
typedef value_type& reference
template <typename T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
	for (std::size_t i = 0; i < lhs.last_ && i < rhs.last_; i++) {
		if (lhs.data_[i] != rhs.data[i]) {return (false);}
	}
	if (lhs.last != rhs.last) {return (false);}
	return (true);}

template <typename T>
bool operator!=(const vector<T>& lhs, const vector<T>& rhs) {
	return !(lhs == rhs);}
```
This won't work because data_ is a private member. So now comes the iterators...
## Step 3.3: Implement iterators
### Step 3.3.1: Implement Allocator
```c++
template <typename T, class Allocator = std::allocator<T> >
class vector {
	public:
		typedef typename allocator_type::pointer	pointer;
//Iterators
template <class myVector>
class vector_iterator {
	 public:
	 	typedef typename myVector::pointer	pointer;

		pointer ptr_;
};
```
### Step 3.3.2: Implement Iterator constructor
```c++
vector_iterator() : ptr_() {}
vector_iterator(pointer ptr) : ptr_(ptr) {}
~vector_iterator() {}
```
### Step 3.3.3: Implement vector member iterators begin() & end()
```c++
iterator begin() {return (iterator(data[0]));}
iterator end() {return (iterator(data[last_]));}
//Define iterator
typedef vector_iterator<vector<T> >		iterator;
```
### Step 3.3.4: Modify == non-member overloads
```c++
//The != needs no modification since it calls the opposite of ==
template <typename T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
	typename vector<T>::iterator it1 = lhs.begin();
	typename vector<T>::iterator it1_end = lhs.end();
	typename vector<T>::iterator it2 = rhs.begin();
	typename vector<T>::iterator it2_end = rhs.end();
	while (it1 != it1_end || it2 != it2_end) {
		if (it1++ != it2++) {return (false);}
	}
	return (it1 == it1_end  && it2 == it2_end);}
```
### Step 3.3.5: Implement vector_iterator non member == & != operator overload
```c++
template <class myVector>
bool operator==(const vector_iterator<myVector>& lhs, const vector_iterator<myVector>& rhs) {
	return (lhs.ptr_ == rhs.ptr_);}

template <class myVector>
bool operator!=(const vector_iterator<myVector>& lhs, const vector_iterator<myVector>& rhs) {
	return !(lhs == rhs);}
```
### Step 3.3.6: Implement vector_iterator increment overload
```c++
vector_iterator& operator++() { //Pre increment
	++ptr_;
	return (*this);}
vector_iterator operator++(int) { //Post increment
	vector_iterator tmp(*this);
	++ptr_;
	return (tmp);}
```
## Step 4: Make a list of everything to implement
- [X] Member Types
	- [X] value_type
	- [X] allocator_type
	- [X] size_type
	- [X] difference_type
	- [X] reference
	- [X] const reference
	- [X] pointer
	- [X] const_pointer
	- [X] iterator
	- [X] const_iterator
	- [X] reverse_iterator
	- [X] const_reverse_iterator
- [X] Member Functions
	- [X] [constructor](https://en.cppreference.com/w/cpp/container/vector/vector)
		- [X] vector();
		- [X] explicit vector(const Allocator& alloc);
		- [X] explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		- [X] template\<class InputIT\>vector(InputIt first, IntputIt last, const Allocator& alloc = Allocator());
		- [X] vector(const vector& other);
	- [X] [destructor](https://en.cppreference.com/w/cpp/container/vector/%7Evector)
		- [X] ~vector();
	- [X] [operator=](https://en.cppreference.com/w/cpp/container/vector/operator%3D)
		- [X] vector& operator=(const vector &other);
	- [X] [assign](https://en.cppreference.com/w/cpp/container/vector/assign)
		- [X] void assign(size_type count, const T& value);
		- [X] template\<class InputIt>void assign(InputIt first, InputIt last);
	- [X] [get_allocator](https://en.cppreference.com/w/cpp/container/vector/get_allocator)
		- [X] allocator_type get_allocator() const;
- [X] Member Functions (Elements Access)
	- [X] [at](https://en.cppreference.com/w/cpp/container/vector/at)
		- [X] reference at(size_type pos);
		- [X] const_reference at(size_type pos) const;
	- [X] [operator [ ]](https://en.cppreference.com/w/cpp/container/vector/operator_at)
		- [X] reference operator[ ](size_type pos);
		- [X] const_reference operator[ ](size_type pos) const;
	- [X] [front](https://en.cppreference.com/w/cpp/container/vector/front)
		- [X] reference front();
		- [X] const_reference front() const;
	- [X] [back](https://en.cppreference.com/w/cpp/container/vector/back)
		- [X] reference back();
		- [X] const_reference back() const;
	- [X] [data](https://en.cppreference.com/w/cpp/container/vector/data)
		- [X] T* data();
		- [X] const T* data() const;
- [X] Member Functions (Iterators)
	- [X] [begin](https://en.cppreference.com/w/cpp/container/vector/begin)
		- [X] iterator begin();
		- [X] const_iterator begin() const;
	- [X] [end](https://en.cppreference.com/w/cpp/container/vector/end)
		- [X] iterator end();
		- [X] const_iterator end() const;
	- [X] [rbegin](https://en.cppreference.com/w/cpp/container/vector/rbegin)
		- [X] reverse_iterator rbegin();
		- [X] const_reverse_iterator rbegin() const;
	- [X] [rend](https://en.cppreference.com/w/cpp/container/vector/rend)
		- [X] reverse_iterator rend();
		- [X] const_reverse_iterator rend() const;
- [X] Member Functions (Capacity)
	- [X] [empty](https://en.cppreference.com/w/cpp/container/vector/empty)
		- [X] bool empty() const;
	- [X] [size](https://en.cppreference.com/w/cpp/container/vector/size)
		- [X] size_type() const;
	- [X] [max_size](https://en.cppreference.com/w/cpp/container/vector/max_size)
		- [X] size_type max_size() const;
	- [X] [reserve](https://en.cppreference.com/w/cpp/container/vector/reserve)
		- [X] void reserve(size_type new_cap);
	- [X] [capacity](https://en.cppreference.com/w/cpp/container/vector/capacity)
		- [X] size_type capacity() const;
- [X] Member Functions (Modifiers)
	- [X] [clear](https://en.cppreference.com/w/cpp/container/vector/clear)
		- [X] void clear();
	- [X] [insert](https://en.cppreference.com/w/cpp/container/vector/insert)
		- [X] iterator insert(const_iterator pos, const T& value);
		- [X] iterator insert(const_iterator pos, size_type count, const T& value);
		- [X] template\<class InputIt\>iterator insert(const_iterator pos, InputIt first, InputIt last);
	- [X] [erase](https://en.cppreference.com/w/cpp/container/vector/erase)
		- [X] iterator erase(iterator pos);
		- [X] iterator erase(iterator first, iterator last);
	- [X] [push_back](https://en.cppreference.com/w/cpp/container/vector/push_back)
		- [X] void push_back(const T& value);
	- [X] [pop_back](https://en.cppreference.com/w/cpp/container/vector/pop_back)
		- [X] void pop_back();
	- [X] [resize](https://en.cppreference.com/w/cpp/container/vector/resize)
		- [X] void resize(size_type count);
		- [X] void resize(size_type count, T value = T());
	- [X] [swap](https://en.cppreference.com/w/cpp/container/vector/swap)
		- [X] void swap(vector& other);
- [X] Non-Member Functions
	- [X] [operator==] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator==(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [operator!=] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator!=(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [operator<] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator\<(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [operator<=] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator\>=(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [operator>] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator\>(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [operator>=] (https://en.cppreference.com/w/cpp/container/vector/operator_cmp)
		- [X] template\<class T, class Alloc\>bool operator\>=(const std::vector\<T, Alloc\>& lhs, const std::vector\<T, Alloc\>& rhs)
	- [X] [swap](https://en.cppreference.com/w/cpp/container/vector/swap2)
		- [X] template\<class T, class Alloc\>void swap(std::vector\<T, Alloc\>& lhs, std::vector\<T, Alloc\>& rhs)
	
### Step 4.1: Implement member types
From the definitions provided by [cppreference](https://en.cppreference.com/w/cpp/container/vector)
```c++
#include <cstddef> //For std::ptrdiff_t
# include <memory> //For std::allocator_traits
typedef T	value_type;
typedef Allocator	allocator_type;
typedef std::size_t	size_type;
typedef std::ptrdiff_t	difference_type;
typedef value_type&	reference;
typedef const value_type&	const_reference;
typedef typename std::allocator_traits<Allocator>::pointer	pointer;
typedef typename std::allocator_traits<Allocator>::const_pointer	pointer;
typedef vector_iterator<vector<T> >	iterator;
typedef vector_const_iterator<vector<T> >	const_iterator;
typedef ft::reverse_iterator<iterator>	reverse_iterator;
typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
```
### Step 4.2: Implement vector_const_iterator
Same as vector_iterator but const
```c++
template <class myVector>
class vector_const_iterator {
	 public:
	 	typedef typename myVector::pointer		pointer;
		typedef typename myVector::value_type	value_type;

		pointer ptr_;

		vector_const_iterator() : ptr_() {}
		vector_const_iterator(pointer ptr) : ptr_(ptr) {}
		~vector_const_iterator() {}

		//Pre increment
		vector_const_iterator& operator++() {++ptr_; return (*this);}
		vector_const_iterator& operator--() {--ptr_; return (*this);}
		//Post increment
		vector_const_iterator operator++(int) {vector_const_iterator tmp(*this); ++ptr_; return (tmp);}
		vector_const_iterator operator--(int) {vector_const_iterator tmp(*this); --ptr_; return (tmp);}
};
```
### Step 4.3: Implement constructors
Default is already implemented.
#### Step 4.3.1: Explicit Allocator constructor
```c++
explicit vector(const Allocator& alloc)
	: alloc_(alloc), data_(nullptr), last_(0), size_(0), capacity_(0) {}
//We need to add alloc_ to the private members of vector
allocator_type	alloc_;
```
Test it
```c++
//We need empty() 
bool empty() const {return (size() == 0);}

TEST(Vector, ExplicitAllocatorConstructor) {
	ft::vector<int, std::allocator<int> > mine((std::allocator<int>()));
	EXPECT_TRUE(mine.empty());
	EXPECT_EQ(mine.size(), 0);
	EXPECT_EQ(mine.capacity(), 0);}
```
### Step 4.3.2: Explicit size constructor
```c++
explicit vector(size_type count)
	: alloc_(), data_(alloc_.allocate(count)), last_(data_ + count), size_(count), capacity_(count) {
		std::uninitialized_fill_n(data_, count, T());}
```
We found errors in copy constructor, so apply modifications:
```c++
vector& operator=(const vector& other) {
	if (*this != other) {
		for (size_type i = 0; data_ + i < last_; i++) {
			alloc_.destroy(data_ + i);}
		alloc_.deallocate(data_, capacity_);
		alloc_ = other.alloc_;
		size_ = other.size_;
		data_ = alloc_.allocate(size_);
		last_ = data_ + size_;
		capacity_ = other.capacity_;
		std::uninitialized_copy(other.data_, other.last_, data_);}
	return (*this);}
```
Now all constructors and destructors are implemented. Verify memory leaks.
```bash
~valgrind ./build/Vector
==68645== LEAK SUMMARY:
==68645==    definitely lost: 0 bytes in 0 blocks
==68645==    indirectly lost: 0 bytes in 0 blocks
==68645==      possibly lost: 0 bytes in 0 blocks
==68645==    still reachable: 0 bytes in 0 blocks
==68645==         suppressed: 18,133 bytes in 162 blocks
```
### Step 4.4: Assign Member Function
Since cleaning the vector is repetitive through some functions I implemented a private tool clean()
```c++
private:
/*Tools*/
void clean() {
	if (!empty()) {
		for (size_type i = 0; data_ + i != last_; i++) {
			alloc_.destroy(data_ + i);}
	}
	if (capacity_ > 0) {
		alloc_.deallocate(data_, capacity_);}
}

void assign(size_type count, const T& value) {
	clean();
	data_ = alloc_.allocate(count);
	last_ = data_;
	for (size_type i = 0; i < count; i++) {
		last_++ = value;}
	size_ = count;
	capacity_ = count;}

template <class Iter>
void assign(Iter first, Iter last) {
	clean();
	data_ = alloc_.allocate(std::distance(first, last));
	last_ = data_;
	for (Iter i = first; i != last; ++i) {
		alloc_.construct(last_++, *i);}
	size_ = std::distance(first, last);
	capacity_ = size_;}
```
We will now encounter a compilation problem, where the compiler won't know which assign to use and use the wrong one.
We got this test: 
```c++
TEST(Vector, AssignCount) {
    ft::vector<int, std::allocator<int> > mine;
    mine.assign(10, 42);

	EXPECT_FALSE(mine.empty());
	EXPECT_EQ(mine.size(), 10);
	EXPECT_EQ(mine.capacity(), 10);

	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(mine[i], 42);}}
```
### Step 4.4.1: Enable_if & is_integral

This should call the assign(size_type count, const T& value), but it calls the assign(Iter first, Iter last).
We need to enable the second assign only if it is integral.
```c++
template <typename Iter>
typename std::enable_if<
	std::is_copy_constructible<typename std::iterator_traits<Iter>::value_type>::value &&
	std::is_integral<typename std::iterator_traits<Iter>::difference_type>::value
>::type
assign(Iter first, Iter last, const Allocator& alloc = Allocator()) {...}

template <typename U = T>
typename std::enable_if<std::is_copy_constructible<U>::value>::type
assign(size_type count, const T& value) {...}
```
The enable and is_integral will be implemented in a seperated file type_traits.hpp since it will be reused for other containers. We will then have to replace std:: by ft:: for the enable_if ad is_integral.
```c++
template <typename T>
struct is_integral {static const bool value = false;};

#define DEFINE_INTEGRAL_TYPE(S) template<> struct is_integral<S> {static const bool value = true; };
DEFINE_INTEGRAL_TYPE(bool)
DEFINE_INTEGRAL_TYPE(char)
DEFINE_INTEGRAL_TYPE(signed char)
DEFINE_INTEGRAL_TYPE(unsigned char)
DEFINE_INTEGRAL_TYPE(wchar_t)
DEFINE_INTEGRAL_TYPE(short)
DEFINE_INTEGRAL_TYPE(unsigned short)
DEFINE_INTEGRAL_TYPE(int)
DEFINE_INTEGRAL_TYPE(unsigned int)
DEFINE_INTEGRAL_TYPE(long)
DEFINE_INTEGRAL_TYPE(unsigned long)
DEFINE_INTEGRAL_TYPE(long long)
DEFINE_INTEGRAL_TYPE(unsigned long long)
#undef DEFINE_INTEGRAL_TYPE

//convention call to shorten the use
template <typename T>
struct is_integral_t {typedef typename is_integral<T>::value value;};

template <typename T>
const bool is_integral_v = is_integral<T>::value;

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {typedef T type;};

template <bool B, typename T = void>
const typename enable_if<B, T>::type* enable_if_v = 0;
```
### Step 4.5: get_allocator
We return a copy of the allocator:
```c++
allocator_type get_allocator() const {return (alloc_);}
```
### Step 4.6: Member access at()
Same as operator[], only with protection and throw exception if not valid.
```c++
reference at(size_type pos) {
	if (!(pos < size_) || pos < 0) {throw(std::out_of_range("Position out bonds"));}
	else {return (data_[pos]);}
}
const_reference at(size_type pos) const {
	if (!(pos < size_)) {throw(std::out_of_range("Position out bonds"));}
	else {return (data_[pos]);}
}
```
### Step 4.7: Member access operator[]
Same as the at() function, but without protections.
```c++
reference operator[](size_type pos) {return (data_[pos]);}
const_reference operator[](size_type pos) const {return (data_[pos]);}
```
### Step 4.8: Member access front() & back()
Quite simple here...
```c++
reference front() {return (data_[0]);}
const_reference front() const {return (data_[0]);}
reference back() {return (data_[size_ - 1]);}
const_reference back() const {return (data_[size_ - 1]);}
```
### Step 4.9: Member access data()
Return a pointer to the begining of the array.
```c++
value_type* data() {return (data_);}
const value_type* data() const {return (data_);}
```
### Step 4.10: Member Iterators begin() & end()
```c++
iterator begin() {return (iterator(data_));}
const_iterator begin() const {return (const_iterator(data_));}
iterator end() {return (iterator(last_));}
const_iterator end() const {return (const_iterator(last_));}
```
# Step 5: Implement Iterator_Traits
Reimplement the cpp reference member type for each version:
```c++
template <class Iter>
struct iterator_traits {
public:
	typedef typename Iter::difference_value	difference_value;
	typedef typename Iter::value_type		value_type;
	typedef typename Iter::pointer			pointer;
	typedef typename Iter::reference		reference;
	typedef typename Iter:iterator_category	iterator_category;


};

template <class T>
struct iterator_traits<T*> {
	typedef T	value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};
```
# Step 5: Implement Reverse_iterator
- [X] Member Types
	- [X] iterator_type
	- [X] iterator_category
	- [X] value_type
	- [X] difference_type
	- [X] pointer
	- [X] reference
- [X] Member Functions
	- [X] [constructor](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/reverse_iterator)
		- [X] reverse_iterator();
		- [X] explicit reverse_iterator(iterator_type x);
		- [X] template\<class U\> reverse_iterator(const reverse_iterator\<U\>& other);
	- [X] [operator=](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator%3D)
		- [X] template\<class U\>reverse_iterator& operator=(const reverse_iterator\<U\>& other);
	- [X] [base](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/base)
		- [X] iterator_type base() const;
	- [X] [operator* & operator->](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*)
		- [X] reference operator*() const;
		- [X] pointer operator->() const;
	- [X] [operator[]](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_at)
		- [X] /\*unspecified\*/ operator[](difference_type n ) const;
	- [X] [operator++,+,+=,--,-,-=](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_arith)
		- [X] reverse_iterator& operator++()
		- [X] reverse_iterator operator++(int)
		- [X] reverse_iterator operator+(difference_type n) const;
		- [X] reverse_iterator& operator+=(difference_type n)
		- [X] reverse_iterator& operator--()
		- [X] reverse_iterator operator--(int)
		- [X] reverse_iterator operator-(difference_type n) const;
		- [X] reverse_iterator& operator-=(difference_type n);
- [X] Member Objects
	- [X] current (protected)
- [X] [Non-Member Functions](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_cmp)
	- [X] All using: template\<class Iter1, class Iter2\>
		- [X] bool operator==(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
		- [X] bool operator!=(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
		- [X] bool operator<(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
		- [X] bool operator<=(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
		- [X] bool operator>(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
		- [X] bool operator>=(const reverse_iterator\<Iter1\>& lhs, const reverse_iterator\<Iter1\>& rhs);
	- [X] [Operator+](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator%2B)
		- [X] template\<class Iter>reverse_iterator\<Iter\> operator+(typename reverse_iterator\<Iter\>::difference_type n, const reverse_iterator\<Iter\>& it);
	- [X] [Operator-](https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator-)
		- [X] template\<class Iter>reverse_iterator\<Iter\> operator-(typename reverse_iterator\<Iter\>::difference_type n, const reverse_iterator\<Iter\>& it);
```c++
template <class Iter>
class reverse_iterator {
private:
	iterator_type current;
public:
	typedef Iter iterator_type;
	typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;

	reverse_iterator() : current() {}
	explicit reverse_iterator(iterator_type it) : current(it) {}
};
```