#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
T square(T x) {
	std::cout << x * x << " ";
	return (x * x);}

template <typename T, typename F>
void iter(T *array, size_t size, F func) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);}
}

#endif