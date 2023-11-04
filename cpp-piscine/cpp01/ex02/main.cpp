#include <iostream>

int	main( void ) {
	std::string	string = "HI THIS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "   Address of string: " << reinterpret_cast<void *>(&string) << std::endl;
	std::cout << "Address of stringPTR: " << reinterpret_cast<void *>(stringPTR) << std::endl;
	std::cout << "Address of stringREF: " << reinterpret_cast<void *>(&stringREF) << std::endl;

	std::cout << "\n   Value of string: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	return (0);
}
