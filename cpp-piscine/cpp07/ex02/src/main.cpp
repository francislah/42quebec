#include <iostream>
#include "../include/Array.hpp"

int main( void ) {
	Array<int> a(5);
	Array<std::string> b;
	int	*c = new int();

	std::cout << *c << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	try {std::cout << b[0] << std::endl;}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;}
	std::cout << a[4] << std::endl;
	a[0] = 55;
	std::cout << a[0] << std::endl;

	return (0);
}