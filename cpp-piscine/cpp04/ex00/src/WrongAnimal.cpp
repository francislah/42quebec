#include "WrongAnimal.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

WrongAnimal::WrongAnimal(void) : _type("")
	{std::cout << "WrongAnimal default construction" << std::endl;}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
	{std::cout << "WrongAnimal construction" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
	{std::cout << "WrongAnimal copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

std::string	WrongAnimal::getType(void) {return (this->_type);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	WrongAnimal::makeSound(void) {std::cout << "Extraterrestrial sounds..." << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy){
	if (this != &copy){
		this->_type = copy._type;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

WrongAnimal::~WrongAnimal(void){std::cout << "WrongAnimal destruction" << std::endl;}