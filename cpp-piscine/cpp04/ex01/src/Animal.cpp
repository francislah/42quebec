#include "Animal.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Animal::Animal(void) : _type("")
	{std::cout << "Animal default construction" << std::endl;}

Animal::Animal(std::string type) : _type(type)
	{std::cout << "Animal construction" << std::endl;}

Animal::Animal(const Animal &copy) : _type(copy._type)
	{std::cout << "Animal copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

std::string	Animal::getType(void) {return (this->_type);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	Animal::makeSound(void) {std::cout << "No sound came out..." << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Animal	&Animal::operator=(const Animal &copy){
	if (this != &copy){
		this->_type = copy._type;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Animal::~Animal(void){std::cout << "Animal destruction" << std::endl;}