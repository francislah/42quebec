#include "Intern.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Intern::Intern(void) {
	std::cout << "Intern default construction" << std::endl;}

Intern::Intern(const Intern &copy) {
	std::cout << "Intern copy construction" << std::endl;
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

Form	*Intern::makeForm(std::string form_name, std::string target) {
	std::string	forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	int	ret = -1;
	for (int i = 0; i < 3; i++) {if (form_name == forms[i]) {ret = i;}}
	switch (ret) {
		case -1: {throw Intern::FormDoesntExist(); return (NULL);}
		case 0: {std::cout << "Intern creates " << forms[ret] << std::endl;
			return new ShrubberyCreationForm(target);}
		case 1: {std::cout << "Intern creates " << forms[ret] << std::endl;
			return new PresidentialPardonForm(target);}
		case 2: {std::cout << "Intern creates " << forms[ret] << std::endl;
			return new RobotomyRequestForm(target);}
	}
	return (NULL);
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Intern	&Intern::operator=(const Intern &copy){
	if (this != &copy) {
		*this = copy;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Intern::~Intern(void){std::cout << "Intern destruction" << std::endl;}

