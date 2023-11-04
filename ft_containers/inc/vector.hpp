#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include "type_traits.hpp" 
//#pragma clang loop vectorize(assume_safety)

namespace ft {

/****************************/
/* Vector Constant Iterator */
/****************************/
template <class myVector>
class vector_const_iterator {
public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef typename myVector::value_type	value_type;
	typedef typename myVector::difference_type difference_type;
	typedef typename myVector::pointer		pointer;
	typedef const value_type&		reference;

	pointer ptr_;

	vector_const_iterator() : ptr_(NULL) {}
	vector_const_iterator(pointer ptr) : ptr_(ptr) {}
	vector_const_iterator(const vector_const_iterator& other) : ptr_(other.ptr_) {}
	vector_const_iterator& operator=(const vector_const_iterator& other) {
		if (this != &other) {ptr_ = other.ptr_;}
		return (*this);}
	~vector_const_iterator() {}

	const myVector& base() const {return ptr_;}
	reference operator*() const {return (*ptr_);}
	pointer operator->() const {return ptr_;}
	reference operator[](difference_type n) const {return (*(ptr_ + n));}

	vector_const_iterator& operator++() {++ptr_; return (*this);}
	vector_const_iterator& operator--() {--ptr_; return (*this);}
	vector_const_iterator operator++(int) {vector_const_iterator tmp(*this); ++ptr_; return (tmp);}
	vector_const_iterator operator--(int) {vector_const_iterator tmp(*this); --ptr_; return (tmp);}

	vector_const_iterator& operator+=(difference_type n) {ptr_ += n; return (*this);}
	vector_const_iterator& operator-=(difference_type n) {ptr_ -= n; return (*this);}
	friend vector_const_iterator operator+(const vector_const_iterator& lhs, difference_type n) {
		vector_const_iterator temp(lhs);
		return (temp += n);}
	friend vector_const_iterator operator+(difference_type n, const vector_const_iterator& rhs) {return (rhs + n);}
	friend vector_const_iterator operator-(difference_type n, const vector_const_iterator& rhs) {return (rhs - n);}
	friend difference_type operator-(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return (lhs.ptr_ -rhs.ptr_);}
	friend bool operator==(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return (lhs.ptr_ == rhs.ptr_);}
	friend bool operator!=(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return !(lhs.ptr_ == rhs.ptr_);}
	friend bool operator<(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return (lhs.ptr_ < rhs.ptr_);}
	friend bool operator<=(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return !(rhs < lhs);}
	friend bool operator>(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return (rhs < lhs);}
	friend bool operator>=(const vector_const_iterator& lhs, const vector_const_iterator& rhs) {
		return !(lhs < rhs);}	
};

/****************************/
/*     Vector Iterator      */
/****************************/
template <class myVector>
class vector_iterator : public vector_const_iterator<myVector> {
public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef typename myVector::value_type	value_type;
	typedef typename myVector::difference_type difference_type;
	typedef typename myVector::pointer		pointer;
	typedef const value_type&		reference;
	
	vector_iterator() : vector_const_iterator<myVector>(){}
	vector_iterator(pointer ptr) : vector_const_iterator<myVector>(ptr) {}
	vector_iterator(const vector_iterator& other) : vector_const_iterator<myVector>(other.ptr_) {}
	~vector_iterator() {}

	reference operator*() const {return (*this->ptr_);}
	reference operator[](difference_type n) const {return (*(this->ptr_ + n));}
	vector_iterator& operator++() {++this->ptr_; return (*this);}
	vector_iterator& operator--() {--this->ptr_; return (*this);}
	vector_iterator operator++(int) {vector_iterator tmp(*this); ++this->ptr_; return (tmp);}
	vector_iterator operator--(int) {vector_iterator tmp(*this); --this->ptr_; return (tmp);}
	vector_iterator& operator+=(difference_type	n) {this->ptr_ += n; return (*this);}
	vector_iterator& operator-=(difference_type	n) {this->ptr_ -= n; return (*this);}

	friend vector_iterator operator+(vector_iterator const& lhs, typename vector_iterator::difference_type rhs) {return vector_iterator(lhs.ptr_ + rhs);}
	friend vector_iterator operator-(vector_iterator const& lhs, typename vector_iterator::difference_type rhs) {return vector_iterator(lhs.ptr_ - rhs);}
	friend typename vector_iterator::difference_type operator-(vector_iterator const& lhs, vector_iterator const& rhs) {return lhs.ptr_ - rhs.ptr_;}
	friend bool operator<(const vector_iterator& lhs, const vector_iterator& rhs) { return lhs.ptr_ < rhs.ptr_; }
	friend bool operator>(const vector_iterator& lhs, const vector_iterator& rhs) { return lhs.ptr_ > rhs.ptr_; }
	friend bool operator<=(const vector_iterator& lhs, const vector_iterator& rhs) { return lhs.ptr_ <= rhs.ptr_; }
	friend bool operator>=(const vector_iterator& lhs, const vector_iterator& rhs) { return lhs.ptr_ >= rhs.ptr_; }
};

/****************************/
/*           Vector         */
/****************************/
template <typename T, class Allocator = std::allocator<T> >
class vector {
public:
	typedef T 												value_type;
	typedef Allocator 										allocator_type;
	typedef std::size_t										size_type;
	typedef std::ptrdiff_t									difference_type;
	typedef value_type& 									reference;
	typedef const value_type& 								const_reference;
	typedef typename std::allocator_traits<Allocator>::pointer			pointer;
	typedef typename std::allocator_traits<Allocator>::const_pointer	const_pointer;
	typedef vector_iterator<vector<T> >						iterator;
	typedef vector_const_iterator<vector<T> >				const_iterator;
	typedef std::reverse_iterator<iterator>					reverse_iterator;
	typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;
private:
	allocator_type	alloc_;
	value_type	*data_;
	value_type	*last_;
	size_type	size_;
	size_type	capacity_;

public: 
	vector() : alloc_(allocator_type()), data_(alloc_.allocate(0)), last_(data_), size_(0), capacity_(0) {}
	explicit vector(const Allocator& alloc)
		: alloc_(alloc), data_(alloc_.allocate(0)), last_(data_), size_(0), capacity_(0) {}

	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		: alloc_(alloc),
		data_(alloc_.allocate(count)),
		last_(data_ + count),
		size_(count),
		capacity_(count) {
			std::uninitialized_fill_n(data_, count, value);}

	template <class Iter>
	vector(Iter first, Iter last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<Iter>::value>::type* = 0)
		: alloc_(alloc), data_(alloc_.allocate(std::distance(first, last))),
		last_(data_), size_(std::distance(first, last)), capacity_(size_) {
			for (Iter i = first; i != last; ++i) {
				alloc_.construct(last_++, *i);}
	}
	vector(const vector& other) :
		alloc_(other.alloc_), data_(alloc_.allocate(other.size_)), last_(data_ + other.size_), size_(other.size_), capacity_(other.capacity_) {
			std::uninitialized_copy(other.data_, other.last_, data_);}
	~vector() {clean();}
	vector& operator=(const vector& other) {
		if (*this != other) {
			clean();
			alloc_ = other.alloc_;
			size_ = other.size_;
			data_ = alloc_.allocate(size_);
			capacity_ = other.capacity_;
			std::uninitialized_copy(other.data_, other.last_, data_);
			last_ = data_ + size_;
		}
		return (*this);
	}
/*Member Functions*/
    typename ft::enable_if<std::is_copy_constructible<T>::value>::type
    assign(size_type count, const T& value, const Allocator& alloc = Allocator()) {
        clean();
		alloc_ = alloc;
        data_ = alloc_.allocate(count);
        last_ = data_;
        for (size_type i = 0; i < count; i++) {
            alloc_.construct(last_++, value);}
        size_ = count;
        capacity_ = count;}
   template <typename Iter>
    typename ft::enable_if<
        std::is_copy_constructible<typename std::iterator_traits<Iter>::value_type>::value &&
        ft::is_integral<typename std::iterator_traits<Iter>::difference_type>::value
    >::type
    assign(Iter first, Iter last) {
        clean();
        size_ = std::distance(first, last);
        capacity_ = size_;
        data_ = alloc_.allocate(size_);
        last_ = data_;
        std::uninitialized_copy(first, last, data_);}

	allocator_type get_allocator() const {return (alloc_);}

/*Elements acces*/
	reference at(size_type pos) {
		if (!(pos < size_) || pos == static_cast<size_type>(-1)) {throw(std::out_of_range("Position out bonds"));}
		else {return (data_[pos]);}
	}
	const_reference at(size_type pos) const {
		if (!(pos < size_)) {throw(std::out_of_range("Position out bonds"));}
		else {return (data_[pos]);}
	}
	reference operator[](size_type pos) {return (data_[pos]);}
	const_reference operator[](size_type pos) const {return (data_[pos]);}
	reference front() {return (data_[0]);}
	const_reference front() const {return (data_[0]);}
	reference back() {return (data_[size_ - 1]);}
	const_reference back() const {return (data_[size_ - 1]);}
	value_type* data() {return (data_);}
	const value_type* data() const {return (data_);}

/*Iterators*/
	iterator begin() {return (iterator(data_));}
	const_iterator begin() const {return (const_iterator(data_));}
	iterator end() {return (iterator(last_));}
	const_iterator end() const {return (const_iterator(last_));}
	reverse_iterator rbegin() {return (reverse_iterator(last_));}
	const_reverse_iterator rbegin() const {return (const_reverse_iterator(last_));}
	reverse_iterator rend() {return (reverse_iterator(data_));}
	const_reverse_iterator rend() const {return (const_reverse_iterator(data_));}

/*Capacity*/
	bool empty() const {return (begin() != end());}
	size_type size() const {return (size_);}
	size_type max_size() const {return (alloc_.max_size());}
	void reserve(size_type new_cap) {
		if (new_cap <= capacity()) {return ;}
		T* new_data = alloc_.allocate(new_cap);
		std::uninitialized_copy(data_, data_ + size(), new_data);
		clean();
		data_ = new_data;
		last_ = data_ + size();
		capacity_ = new_cap;}
	size_type capacity() const {return (capacity_);}

/*Modifiers*/
	void clear() {
		for (size_type i = 0; i < size_; ++i) {
			alloc_.destroy(data_ + i);}
		size_ = 0;}
	iterator insert(iterator position, const T& value) {
		size_type index = position - begin();
		if (size_ == capacity_) {reserve(capacity_ + 1);}
		data_[size_] = back();
		for (size_type i = size_; i > index; --i) {
			data_[i] = data_[i - 1];}
		++size_;
		alloc_.construct(data_ + index, value);
		return (begin() + index);}
	iterator insert(iterator position, size_type count, const T& value) {
    	size_type index = position - begin();
    	if (size_ + count > capacity_) {reserve(size_ + count);}
    	for (size_type i = 0; i < count; ++i) {
    	   data_[size_ + i] = back();}
    	for (size_type i = size_ + count - 1; i > index + count - 1; --i) {
     	   data_[i] = data_[i - count];}
   		for (size_type i = 0; i < count; ++i) {
        	alloc_.construct(data_ + index + i, value);}
    	size_ += count;
		return (begin() + index);}
	template <class InputIt>
	void insert(iterator position, InputIt first, InputIt last, typename ft::enable_if<!std::is_integral<InputIt>::value>::type* = 0) {
		size_type index = position - begin();
		size_type count = distance(first, last);
		if (size_ + count > capacity_) {reserve(size_ + count);}
		for (size_type i = 0; i < count; ++i) {
			data_[size_ + i] = back();}
		for (size_type i = size_ + count - 1; i > index + count - 1; --i) {
			data_[i] = data_[i - count];}
		for (size_type i = 0; i < count; ++i) {
			alloc_.construct(data_ + index + i, *(first + i));}
		size_ += count;}
	iterator erase(iterator pos) {
    	if (pos == end()) {return pos;}
   		alloc_.destroy(pos.ptr_);
		for (iterator i = pos + 1; i != end(); ++i) {
			alloc_.construct((i - 1).ptr_, *i.ptr_);
			alloc_.destroy(i.ptr_);}
    	--size_;
		--last_;
    	return pos;}
	template <typename Iter>
	iterator erase(Iter first, Iter last) {
		for (iterator it = first; it != last; ++it) {
			erase(first);}
		return (first) + 1;
	}
	void push_back(const T& value) {
		if (size_ == capacity_) {
			size_type new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
			value_type* new_data = alloc_.allocate(new_capacity);
			std::uninitialized_copy(data_, last_, new_data);
			clean();
			data_ = new_data;
			last_ = data_ + size_;
			capacity_ = new_capacity;}
		alloc_.construct(last_++, value);
		size_++;}
	void pop_back() {
		if (size_ < 1) {return;}
		--last_;
		alloc_.destroy(last_);
		--size_;}
	void resize(size_type count, T value = T()) {
		if (count < size_) {
			erase(data_ + count, last_);
			insert(begin(), count, value);}
		else if (count > size_) {
			insert(end(), count - size_, value);}
		size_ = count;
	}
	void swap(vector& other) {
		std::swap(data_, other.data_);
   		std::swap(size_, other.size_);
    	std::swap(capacity_, other.capacity_);
    	std::swap(alloc_, other.alloc_);
	}
private:
/*Tools*/
	void clean() {
		if (data_ != nullptr) {
			clear();
			alloc_.deallocate(data_, capacity_);}
		data_ = nullptr;
		last_ = nullptr;
		capacity_ = 0;
		size_ = 0;}
};

template <typename T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
	return (rhs.size() == lhs.size() &&
		ft::equal(lhs.begin(), lhs.end(), rhs.begin())) ? true : false;}

template <typename T, class Alloc>
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return !(lhs == rhs);}
template <typename T, class Alloc>
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	if (lhs.size() != rhs.size()) {return (lhs.size() < rhs.size());}
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
template <typename T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (lhs < rhs || lhs == rhs);}
template <typename T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return !(lhs <= rhs);}
template <typename T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return !(lhs < rhs);}
template <typename T, class Alloc>
void swap(vector<T, Alloc>& first, vector<T, Alloc>& second) {
    first.swap(second);}
}

#endif