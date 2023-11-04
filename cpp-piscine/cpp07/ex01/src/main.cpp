#include <iostream>
#include "../include/Iter.hpp"

void	print(std::string word) {
	std::cout << word << std::endl;}

int main( void ) {
	int array[] = {0, 1, 2, 3, 4, 5, 6};
	size_t size = sizeof(array) / sizeof(*array);
	iter(array, size, square<int>);
	std::cout << std::endl;
	double arr[] = { 1.0, 2.0, 3.4, 4.0, 5.0 };
	iter(arr, 5, square<double>);
	std::cout << std::endl;
	std::string words[] = {"Burger", "Poutine", "Fries"};
	iter(words, 3, print);
	
	return (0);
}