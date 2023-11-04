#pragma once

# include <iostream>
# include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;

	reverse_iterator() : current() {}
	explicit reverse_iterator(iterator_type it) : current(it) {}
	template<class U>
	reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {}
	template<class U>
	reverse_iterator& operator=(const reverse_iterator<U>& other) {
		current = other.current;
		return (*this);}

	iterator_type base() const {return (current);}

	reference operator*() const {
		Iterator tmp = current;
		return (*--tmp);}
	pointer operator->() const {return &(operator*());}
	typename reverse_iterator::reference operator[](difference_type n) const {return *(current - n - 1);}

	reverse_iterator& operator++() {
		--current;
		return (*this);}
	reverse_iterator& operator--() {
		++current;
		return (*this);}

	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		++current;
		return (tmp);}
	reverse_iterator operator--(int) {
		reverse_iterator tmp = *this;
		--current;
		return (tmp);}

	reverse_iterator operator+(difference_type n) const {
		return (reverse_iterator(current - n));}
	reverse_iterator operator-(difference_type n) const {
		return (reverse_iterator(current + n));
	}

	reverse_iterator& operator+=(difference_type n) {
		current -= n;
		return (*this);}
	reverse_iterator& operator-=(difference_type n) {
		current += n;
		return (*this);}

protected:
	iterator_type current;
};

template<class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());}
template<class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return !(lhs == rhs);}
template<class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());}
template<class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return !(lhs < rhs);}
template<class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());}
template<class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return !(lhs > rhs);}

template <typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator+(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs) {
    return (rhs.base() + lhs.base());
}

template <typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs) {
    return (rhs.base() - lhs.base());
}
}