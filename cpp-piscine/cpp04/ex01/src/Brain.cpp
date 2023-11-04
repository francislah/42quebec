#include "Brain.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Brain::Brain(void) 
	{std::cout << "Brain default construction" << std::endl;}

Brain::Brain(const Brain &copy)
	{for(int i = 0; i < 100; i++) {this->_ideas[i] = copy._ideas[i];};
	std::cout << "Brain copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Brain	&Brain::operator=(const Brain &copy){ 
	if (this != &copy){
		for(int i = 0; i < 100; i++) {this->_ideas[i] = copy._ideas[i];}}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Brain::~Brain(void) {std::cout << "Brain destruction" << std::endl;}