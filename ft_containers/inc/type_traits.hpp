#pragma once

# include <iostream>

namespace ft {

// C++98-compatible implementation of enable_if
template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};

template <bool B, typename T = void>
struct enable_if_v {
    typedef typename enable_if<B, T>::type type;
};

template <typename T>
struct is_integral {
    // static assertion for C++98 compliance
    private:
    typedef char yes;
    typedef struct { char _[2]; } no;

    template<typename U>
    static yes test(T*,
        typename enable_if<(std::numeric_limits<U>::is_specialized && std::numeric_limits<U>::is_integer), U>::type* = 0);

    template<typename>
    static no test(...);

public:
    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
    // end static assertion
};

// template <typename T>
// struct is_integral {static const bool value = false;};

// #define DEFINE_INTEGRAL_TYPE(S) template<> struct is_integral<S> {static const bool value = true; };
// DEFINE_INTEGRAL_TYPE(bool)
// DEFINE_INTEGRAL_TYPE(char)
// DEFINE_INTEGRAL_TYPE(signed char)
// DEFINE_INTEGRAL_TYPE(unsigned char)
// DEFINE_INTEGRAL_TYPE(wchar_t)
// DEFINE_INTEGRAL_TYPE(short)
// DEFINE_INTEGRAL_TYPE(unsigned short)
// DEFINE_INTEGRAL_TYPE(int)
// DEFINE_INTEGRAL_TYPE(unsigned int)
// DEFINE_INTEGRAL_TYPE(long)
// DEFINE_INTEGRAL_TYPE(unsigned long)
// DEFINE_INTEGRAL_TYPE(long long)
// DEFINE_INTEGRAL_TYPE(unsigned long long)
// #undef DEFINE_INTEGRAL_TYPE

// template <typename T>
// struct is_integral_t {typedef typename is_integral<T>::value value;};


// template <typename T>
// const bool is_integral_v = is_integral<T>::value;

// template <bool B, typename T = void>
// struct enable_if {};

// template <typename T>
// struct enable_if<true, T> {typedef T type;};

// template <bool B, typename T = void>
// const typename enable_if<B, T>::type* enable_if_v = 0;

// template <bool B, typename T = void>
// struct enable_if_t {typedef typename enable_if<B, T>::type type;};

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
        if (*first1 < *first2) {return true;}
        if (*first2 < *first1) {return false;}
    }
    return (first1 == last1) && (first2 != last2);}

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    for (; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2))
            return false;}
    return true;}

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p ) {
	 for (; first1 != last1; ++first1, ++first2) {
        if (!p(*first1, *first2)) {
            return false;}
    }
    return true;}

}